#include <iostream>
#include <queue>
using namespace std;

// To execute C++, please define "int main()"
int main() {
  priority_queue<int> small, big;
  vector<int> v = {2,3,1,4,5,3,2,2,2,2,4,2};
  for (int i = 0 ; i < v.size() ; ++i) {
    small.push(v[i]);
    big.push(-small.top());
    small.pop();
    
    if(big.size() > small.size()){
      small.push(-big.top());
      big.pop();
    }
    double median = (small.size() > big.size()) ? small.top() : (-big.top() + small.top()) * 0.5 ;
    cout << median << endl;
  }
  return 0;
}
