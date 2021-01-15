#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/** Slowest Key Press
char slowestkey (vector<vector<int>>& keytimes) {
    vector<int> vec(keytimes.size(),0);
    int global = 0;
    vec[0] = keytimes[0][1];
    char ans;
    for (int i = 1 ; i < keytimes.size() ; ++i) {
        // vec[i] = keytimes[i][1] - keytimes[i-1][1];
        global = max( global, keytimes[i][1] - keytimes[i-1][1]);
        if (global == keytimes[i][1] - keytimes[i-1][1]) ans = keytimes[i][0] + 'a';
    }
    return ans;
    
}
int main(){
    vector<vector<int>> v = {{0,2}, {1,5} , {0,9}, {2,15}};
    char ans = slowestkey(v);
    cout << ans << endl;
}
**/


// Cutting Metal Surplus
// https://www.1point3acres.com/bbs/thread-669083-1-1.html


// Common Prefix Length
// int commonPrefix(string& s) {
//     int ans = 0;
//     for (int i = 0 ; i < (int)s.size(); ++i) {
//         int l = 0, r = i+1, count = 0;
//         int sizee = min(i-1, (int)s.size()-i-1);
//         while (l <= i && r < s.size()) {
//             if (s[l] == s[r]) count++;
//             l++;
//             r++;
//         }
//         ans += count;
//     }
//     return ans + (int)s.size();
// }
// int main() {
//     string s = "abcabcd";
//     int ans = commonPrefix(s);
//     cout << ans << endl;
// }

// University Career Fair
// int maxevents(int& n, vector<int>& arrivals , vector<int>& duration ){
//     vector<vector<int>> v;
//     int ans = 0;
//     for (int i = 0 ; i < n ; ++i) {
//         v.push_back({arrivals[i], duration[i]});
//     } 
//     sort(v.begin(), v.end(), [] (vector<int>& a, vector<int>& b) {return a[0] + a[1] < b[0] + b[1];});
//     int curendtime = v[0][0] + v[0][1];
//     for (int i = 1 ; i < n-1; ++i) {
//         if (curendtime <= v[i+1][0]){
//             ans++;
//             curendtime = v[i+1][0] + v[i+1][1];
//         }
//     }
//     return ans+1;
// }

// int main() {
//     int n = 5;
//     vector<int> arrivals = {1,3,3,5,7};
//     vector<int> duration = {2,2,1,2,1};
//     int ans = maxevents(n, arrivals, duration);
//     cout << ans;

// }






// // Largest Subgrid
// int main() {
    
// }