#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;
double get_distance(vector<double>p1, vector<double>p2) {
    return sqrt((p1[0] - p2[0])*(p1[0] - p2[0]) + (p1[1] - p2[1])*(p1[1] - p2[1]));
}
double get_perimeter (vector<vector<double>> input) {
    double perimeter = 0;
    for (int i = 0 ; i < input.size() ; ++i) {
        // min heap
        priority_queue<double> min_distance;
        for (int j = 0 ; j < input.size() ; ++j) {
            if (i == j) continue;
            min_distance.push(get_distance(input[j], input[i]));
            if (min_distance.size() > 2) min_distance.pop();
        }
        while (!min_distance.empty()) {
            perimeter += min_distance.top();
            min_distance.pop();
        }
    }
    return perimeter / 2;
}
int main() {
    vector<vector<double>> inputs = {{2,0},{0,0},{0,2},{2,2},{1,3}};
    cout << get_perimeter(inputs);
}