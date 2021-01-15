#include <iostream>
#include <vector>
using namespace std;

int main() {
  string input;
  cin>>input;
  
  
  vector<int> cnt(5);
  int frogs = 0, ans = 0;
  string s = "neigh";
  for (auto c : input) {
      int n = s.find(c);
      ++cnt[n];
      // 'c'
      if (n == 0) {
          frogs++;
          ans = max(frogs, ans);
      }
      // 'k'
      else if (n == 4) {
          frogs--;
      }
      // 'r,o,a'
      else if (--cnt[n-1] < 0) return -1;

  }
  int out = frogs == 0 ? ans : -1;
  cout<<out;
  return 0;
}