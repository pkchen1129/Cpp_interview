/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

double Fun(vector<vector<int>>& input) {
    int k = input.size();
    int n = input[0].size();
    vector<vector<double>> dp(k, vector<double>(n, 1.0)); // dp[i][j] : the max rate when we sell i-th stock on j-th day 
    double rate0 = 1.0;
    double rate1 = 1.0;
    
    for (int j = 1; j < n; j++) {
        double rate2 = 1.0;
        for (int i = 0; i < k; i++) {
            dp[i][j] = max(dp[i][j - 1] * input[i][j] / input[i][j - 1], rate0 * input[i][j] / input[i][j - 1]);
            // dp[i][j - 1] * input[i][j] / input[i][j - 1] : the rate when we sell i-th stock on j-th day instead of (j-1)-th day
            // rate0 * input[i][j] / input[i][j - 1] : the rate when we sold any stock on (j-2)-th day and buy i-th stock on (j-1)-th day and sell on j-th day
            rate2 = max(rate2, dp[i][j]);
        }
        rate0 = max(rate0, rate1);
        rate1 = max(rate1, rate2);
    }
    return rate1;
    // follow up : minimize the space complexity 
}

int main()
{
    // multiple stocks ? 
    //                  Theoretically we can hold multiple stocks at the same time, but what we want is max rate.
    //                  So, holding multiple stocks doesn't affect the final result
    // one day cooldown restriction: We can not buy and sell stock at same day
    //                               If we sell 0-th stock when the price is 400 (3rd day), we can not buy any stock at the same day
    //                               So, We buy 1-th stock when the price is 200(4-th day)
    vector<vector<int>> input = {{100, 200, 300, 400, 500, 600, 700},
	{200, 200, 200, 200, 200, 400, 400}};
	double res = Fun(input);
    cout << res << endl;
    // explanation : buy 0-th stock on 0-th day (price: 100) and sell it on 3-th day (price: 400)
    //               buy 1-th stock on 4-th day (price: 200) and sell it on 3-th day (price: 400)
    //               max rate = (400 / 100) * (400 / 200) = 8
	
    input = {{100, 200, 300, 400, 200, 600, 700}};
    res = Fun(input);
    cout << res << endl;
    // explanation : buy 0-th stock on 0-th day (price: 100) and sell it on 3-th day (price: 400)
    //               buy 0-th stock on 5-th day (price: 200) and sell it on 7-th day (price: 700)
    //               max rate = (400 / 100) * (700 / 200) = 14
    return 0;
}
