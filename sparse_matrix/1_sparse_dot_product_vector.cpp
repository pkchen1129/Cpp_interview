#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
int dotProduct (unordered_map<int, double> asht, unordered_map<int, double> bsht) {
  int idx_a;
  double val_a, val_b;
  double dot = 0;

  for (auto it : asht) {
    idx_a = it.first;
    val_a = it.second;
    auto itb = bsht.find(idx_a);
    if (itb != bsht.end()) {
      val_b = itb->second;
      dot += val_a * val_b;
    }
  }
  return dot;
}

unordered_map<int, double> Add (unordered_map<int, double> asht, unordered_map<int, double> bsht) {
  int maxsize = 0;
  unordered_map<int, double> ans;
  for (auto it : asht) {
    maxsize = max(maxsize, it.first);
  }
  for (auto it : bsht) {
    maxsize = max(maxsize, it.first);
  }
  
  for (int i = 0 ; i < maxsize + 1 ; ++i) {
    if (asht.find(i) == asht.end() && bsht.find(i) == bsht.end()) continue;
    double a = asht.find(i) == asht.end() ? 0 : asht[i];
    double b = bsht.find(i) == bsht.end() ? 0 : bsht[i];
    ans[i] = a + b;
  }

  
  return ans;
}

void print(unordered_map<int, double> asht) {
  int maxsize = 0;
  for (auto it : asht) {
    maxsize = max(maxsize, it.first);
  }
    // cout << maxsize << endl;
  for (int i = 0 ; i < maxsize + 1 ; ++i) {
    double a = asht.find(i) == asht.end() ? 0 : asht[i];
    cout << a << endl;
  }
}
int main() {

  // Dot product of two sparse vectors stored in hash tables
  unordered_map<int, double> asht({{0, 1.}, {7, 2.}, {8, 3.}});
  unordered_map<int, double> bsht({{7, 4.}, {8, 9.}});
  cout << dotProduct(asht, bsht) << endl;
  unordered_map<int, double> ans = Add(asht, bsht);
  print(ans);

  return 0;
}