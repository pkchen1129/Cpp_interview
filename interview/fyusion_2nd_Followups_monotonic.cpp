#include <iostream>
#include <vector>
using namespace std;

/*Implement a function that takes as input a vector of integers and returns an integer with 3 possible values: 1: input is strictly monotonic increasing, 0: input is not strictly monotonic, -1: input is strictly monotonic decreasing:*/

/*
 * returns 1: monotonic increasing
 * 0: non-monotonic
 * -1: monotonic decreasing
 */

int isMonotonic(vector<int>& inputVec) {
    bool increase = true, decrease = true;
    if (inputVec.empty() || inputVec.size() == 1) return 0;
    for (int i = 1 ; i < (int)inputVec.size() ; ++i) {
        increase &= (inputVec[i-1] < inputVec[i]);
        decrease &= (inputVec[i-1] > inputVec[i]);
    }
    if (increase) return 1;
    else if (decrease) return -1;
    else return 0;
}


// To execute C++, please define "int main()"
int main() {
  vector<int> in1 = {1,2,3}; //1
  vector<int> in2 = {1,2,1}; //0 
  vector<int> in3 = {1,1,1}; //0
  vector<int> in4 = {1,0,-1};//-1
  vector<int> in5 = {1};//0
  vector<int> in6 = {}; //0
  
  
  
  cout << isMonotonic(in1) << endl;
  cout << isMonotonic(in2) << endl;
  cout << isMonotonic(in3) << endl;
  cout << isMonotonic(in4) << endl;
  cout << isMonotonic(in5) << endl;
  cout << isMonotonic(in6) << endl;
  
  
  return 0;
}
