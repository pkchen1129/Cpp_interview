#include<iostream>
#include<vector>
#include <random>
#include <cstdint>
// #include<>
template<typename T>
class Point
{
public:
    T x;
    T y;
};


//////////////////////////////Basic Struct//////////////////////////
struct pose_t
{
    float x;
    float y;
    float theta;
};
struct singleray
{
    Point<float> origin;  
    float        range;
    float        theta; 
};
struct lidar
{
public:
    std::vector<singleray> ray;
    std::vector<float> ranges;
    std::vector<float> thetas;
};
struct particle_t
{
public:
    pose_t pose;
    pose_t parentpose;
    double weight;
};
struct particles
{
public:
    int32_t num_particles;
    std::vector<particle_t> particles;
    double weight;
};


//////////////////////////////Mapping///////////////////////////
class map
{
public:
    void updatemap();
};
class occgrid
{

};


//////////////////////////////Model//////////////////////////
class actionmodel
{
public:
    particle_t applyaction(particle_t& prior){

        //action model
        pose_t odometry;// Gain odometry from encoder
        particle_t newsample;
        newsample.parentpose = prior.pose;
        newsample.weight = prior.weight;

        pose_t pre_odo = current_odo;
        pose_t current_odo = odometry;
        float dtheta = current_odo.theta - pre_odo.theta;
        float dx = current_odo.x - pre_odo.x;
        float dy = current_odo.y - pre_odo.y;

        float alpha = atan2(dy, dx) - pre_odo.theta;         

        float ds = sqrt(dx*dx + dy*dy);
        float alpha2 = dtheta - alpha;
        float k1 = 0.1, k2 = 0.1, k2 = 0.1;
        float e1_stddev = k1 * fabs(alpha);
        float e2_stddev = k2 * fabs(ds);
        float e3_stddev = k1 * fabs(alpha2);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<float> e1(0, e1_stddev);
        std::normal_distribution<float> e2(0, e2_stddev);
        std::normal_distribution<float> e3(0, e3_stddev);
        float noise1 = e1(gen);
        float noise2 = e2(gen);
        float noise3 = e3(gen);
        newsample.pose.x = prior.pose.x + (ds + noise2)*cos(prior.pose.theta + alpha + noise1);
        newsample.pose.y = prior.pose.y + (ds + noise2)*sin(prior.pose.theta + alpha + noise1);
        newsample.pose.theta = prior.pose.theta + dtheta + noise1 + noise3;
        newsample.pose.theta = newsample.pose.theta;
        return newsample;
    }
private:
    pose_t current_odo;
};
class sensormodel
{
public:
    double score(singleray& ray, occgrid& map){
        Point<int> sid, eid, eid_prev, eid_post;
        Point<double> pos(ray.origin.x,ray.origin.y);
        Point<double> scan_end, scan_end_prev, scan_end_post;
        float Dis = ray.range;
        float Angle = ray.theta;
        double meter_per_cell = 0.05;
        double end_log, pre_log, post_log, score;
        double end_score, pre_score, post_score;

        sid = global_position_to_grid_cell(pos,map);
            
        scan_end.x = cos(Angle)*Dis + pos.x;     
        scan_end.y = sin(Angle)*Dis + pos.y;
        eid = global_position_to_grid_cell(scan_end,map);

        scan_end_prev.x = cos(Angle)*(Dis - meter_per_cell) + pos.x;     
        scan_end_prev.y = sin(Angle)*(Dis - meter_per_cell) + pos.y;
        eid_prev = global_position_to_grid_cell(scan_end_prev,map);

        scan_end_post.x = cos(Angle)*(Dis + meter_per_cell) + pos.x;     
        scan_end_post.y = sin(Angle)*(Dis + meter_per_cell) + pos.y;
        eid_post = global_position_to_grid_cell(scan_end_post,map);

        //get log odds of the cell where ray ends and the cells before and after it
        // and then convert log odds from [-127,127] to [0,254] by adding 127

        end_log = (double) map.logOdds(eid.x,eid.y);
        pre_log = (double) map.logOdds(eid_prev.x,eid_prev.y);
        post_log =(double) map.logOdds(eid_post.x,eid_post.y);

        if(end_log > 0.0){
            end_score = (double) map.logOdds(eid.x,eid.y) + 128.0;
            pre_score = pre_log <= 0.0 ? -pre_log : pre_log ; 
            // score = 0.8 * end_score + 0.2 * pre_score;
            score = end_score ;
            return score;
        }
        else return 0.0;

    }

    double likelihood(particle_t& proposal,lidar& scan,occgrid& map){
        double scanscore= 0.0, rayscore = 0.0;
        for(auto r : scan.ray){
            rayscore = score(r,map);
            scanscore += rayscore;
        }
        return scanscore;
    }
private:
    lidar ray_;
    
};



//////////////////////////////Particle Filter//////////////////////////
class particlefilter
{
public:
    void initialize();
    std::vector<particle_t> resampleposterior(){
        double r = genResamplingRand();
        std::vector<particle_t> prior;
        double sum_weight = 0.0;
        for (const particle_t& particle : posterior_) {
            sum_weight += particle.weight;
            while (r < sum_weight) {
                particle_t new_particle = particle;
                new_particle.weight = unif_weight_;
                prior.push_back(new_particle);
                r += unif_weight_;
            }
            // std::cout << "U: " << r << "\r";
            if (int(prior.size()) == kNumParticles_) break;
        }
    }
    //Do Action Model
    std::vector<particle_t> computeproposal(std::vector<particle_t> prior)
    {
        std::vector<particle_t> proposal;
        for(int i = 0 ; i < prior.size() ;++i){
            proposal[i] = actionmodel_.applyaction(prior[i]);
        }
        return proposal;
    }
    //Do Sensor Model
    std::vector<particle_t> computenormalizedposterior(
        std::vector<particle_t> proposal,
        lidar& laser,
        occgrid& map)
    {
        std::vector<particle_t> posterior;
        double N = 0.0;
        //Pass through Sensor Model
        for(int i = 0 ; i < proposal.size() ; ++i){
            posterior[i] = sensormodel_.likelihood(proposal[i],laser,map);
            N += posterior[i].weight;
        }
        // Do Normalized
        for(int i = 0; i < proposal.size() ; ++i){
            posterior[i].weight /= N;
        }
        return posterior;
    }
    pose_t updatefilter(pose_t& odometry, lidar& laser, occgrid& map){
        //if(move){}
        auto prior = resampleposterior();
        auto proposal = computeproposal(prior);
        posterior_ = computenormalizedposterior(proposal, laser, map);
        posteriorpose_ = estimateposterior(posterior_);
    }
private:
    actionmodel actionmodel_;
    sensormodel sensormodel_;
    std::vector<particle_t> posterior_;
    pose_t posteriorpose_;

};





//////////////////////////////SLAM//////////////////////////
class slam
{
public:
    void updatelocalization()
    {
        previouspose_ = currentpose_;
        currentpose_ = filter_.updatefilter();
        // auto particles = filter_.particles();
    }
    void updatemap()
    {
        mapper_.updatemap();
    }
    void run()
    {
        if(scan > 100)
        {
            updatelocalization();
            updatemap();
        }
    }
    
private:
    pose_t odometry_pose;
    pose_t currentpose_;
    pose_t previouspose_;
    particlefilter filter_;
    map mapper_;
    occgrid map_;
};




//////////////////////////////Main//////////////////////////
int main(){
    slam s;
    s.run();

}