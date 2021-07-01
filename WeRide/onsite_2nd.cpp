// Compiled with: g++ -Wall -std=c++14 -pthread

#include <iostream>
#include <vector>
using namespace std;
int stairs (int n) {
    if (n == 1) {return 1;}
    
    // vector<int> dp(n, 0);
    vector<vector<int> > dp(3, vector<int>(n, 0));
    // step1
    dp[0][0] = 1;
    dp[1][0] = 0;
    dp[2][0] = 0;
    // step2
    dp[0][1] = 0;
    dp[1][1] = 1;
    dp[2][1] = 0;
    // step3
    dp[0][2] = 1;
    dp[1][2] = 1;
    dp[2][2] = 1;
    for (int j = 0 ; j < 3 ; ++j) {
        for (int i = 3 ; i <= n ; ++i) {
                
            if (j == 0) {
                dp[j][i] = dp[1][i-1] + dp[2][i-1]; 
            }
            else if (j == 1) {
                dp[j][i] = dp[0][i-2] + dp[2][i-2];
            }
            else if (j == 2){
                dp[j][i] = dp[0][i-3] + dp[1][i-3];
            }
        }        
    }

    return dp[0][n-1] + dp[1][n-1] + dp[2][n-1];
}

// last step == 1
// dp[0][i] = sigma(dp[m][i-1])   m != 0

int main(){
    cout << "Hello, World!" << endl;
    cout << stairs(2) << endl;
    cout << stairs(4) << endl;
    cout << stairs(5) << endl;

    return 0;
}


// n stairs
// 1 2 or 3 steps
// 