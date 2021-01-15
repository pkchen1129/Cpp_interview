/**



**/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>
using namespace std;

vector<pair<double,int>> sortingtask( vector<pair<double,int>>&input ){
    sort(input.begin(), input.end());
    unordered_map<int, double> m;
    vector<pair<double,int>> ans;
    int i = 0;

    while (i < input.size()){
        int lower_b_index = input[i].second;
        double lower_b = input[i].first;
        while(input[i].first - lower_b <= 1.0 && i < input.size()){
            lower_b_index = min(lower_b_index, input[i].second);
            m[input[i].second] = input[i].first;
            i++;
        }
        ans.push_back( {m[lower_b_index],lower_b_index} );

        lower_b_index = INT_MAX;
        lower_b = 0;
        m.clear();
    }
    return ans;
}

int main(){
    vector<pair<double,int>> input = {{6.3,13},{5.0, 7}, {6.4, 15},{5.8,5},{5.9,9}};
    cout << "initial: " << endl;
    for(auto& p : input){
        cout << p.first << "," << p.second << endl;
    }
    cout << endl;
    vector<pair<double,int>>out = sortingtask(input);
    
    cout << "ans: " << endl;
    for(auto& p : out){
        cout << p.first << "," << p.second << endl;
    }
    return 0;
}







// #include <vector>
// #include <iostream>
// #include <algorithm>
// #include <numeric>
// #include <cmath>
// #include <utility>
// #include <fstream>
// #include <unordered_map>
// #include <climits>
// #include <stdlib.h>

// using namespace std;

// void sortAndDisplay(ofstream& fout,vector<pair<double,int>>& cars_in_our_lane){
//     sort(cars_in_our_lane.begin(), cars_in_our_lane.end());
//     unordered_map<int, double> m;
//     vector<pair<double,int>> ans;
//     int i = 0;

//     while (i < (int)cars_in_our_lane.size()){
//         int lower_b_index = cars_in_our_lane[i].second;
//         double lower_b = cars_in_our_lane[i].first;
//         while(abs(cars_in_our_lane[i].first - lower_b) < 1.0 && i < (int)cars_in_our_lane.size()){
//             lower_b_index = min(lower_b_index, cars_in_our_lane[i].second);
//             m[cars_in_our_lane[i].second] = cars_in_our_lane[i].first;
//             i++;
//         }
//         ans.push_back( {m[lower_b_index],lower_b_index} );

//         lower_b_index = INT_MAX;
//         lower_b = 0;
//         m.clear();
//     }
//     for(auto& p : ans){
//         fout << p.first << "," << p.second << endl;
//     }
//     // return ans;
// }

// std::vector<std::pair<double,int>> getCarsInOurLane();