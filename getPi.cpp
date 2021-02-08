// https://www.geeksforgeeks.org/estimating-value-pi-using-monte-carlo/
#include <iostream>
// RAND_MAX: the max number of rand()
// Thus, rand()/RAND_MAX will always < 1
using namespace std;
int main() {
    double x, y;
    int iteration = 1000000;
    int inliers = 0;
    srand(time(nullptr));

    for (int i = 0; i < iteration; ++i) {
        x = static_cast<double>(rand()) / RAND_MAX; 
        y = static_cast<double>(rand()) / RAND_MAX;
        if (x*x + y*y <= 1) ++inliers;
    }

    // 0.25*1*1*pi : 1*1 = inliers : iteration
    // pi = 4 * inliers / iteration 

    double pi = 4.0 * static_cast<double>(inliers) / iteration;

    std::cout << pi;

    return 0;
}