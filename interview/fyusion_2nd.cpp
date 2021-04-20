#include <iostream>
#include <vector>
using namespace std;

/*Implement a function that takes as input a vector of integers and returns an integer with 3 possible values: 1: input is strictly monotonic increasing, 0: input is not strictly monotonic, -1: input is strictly monotonic decreasing:*/

int check(const int a, const int b)
{
  if (a > b) return 1;
  else if (a == b) return 0;
  else return -1;
}

/*
 * returns 1: monotonic increasing
 * 0: non-monotonic
 * -1: monotonic decreasing
 */
int isMonotonic(const vector<int>& inputVec)
{
   if (inputVec.empty() || inputVec.size() == 1) return 0;
   int state = check(inputVec[1], inputVec[0]); 
   if (state == 0) return state;
  
   int curr_state = state;
   for (int i = 1 ; i < inputVec.size(); ++i) {
     // increasing
     curr_state = check(inputVec[1], inputVec[0]);
     if (curr_state != state) return 0;
     else continue;
   }
   return state;
}

// To execute C++, please define "int main()"
int main() {
  vector<int> in1 = {1,2,3}; //1
  vector<int> in2 = {1,2,1}; //0 
  vector<int> in3 = {1,1,1}; //0
  vector<int> in4 = {1,0,-1};//-1
  vector<int> in5 = {1};//0
  vector<int> in6 = {}; //0
  
  
  
  std::cout << inMonotonic(in1) << endl;
  cout << inMonotonic(in2) << endl;
  cout << inMonotonic(in3) << endl;
  cout << inMonotonic(in4) << endl;
  cout << inMonotonic(in5) << endl;
  cout << inMonotonic(in6) << endl;
  
  
  return 0;
}
