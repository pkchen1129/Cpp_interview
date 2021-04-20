// Compiled with: g++ -Wall -std=c++14 -pthread
// rotate a RGB image by 90 degrees 

#include <iostream>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>>& img) {
    const int m = img.size(); //img = m x m
    int curSize = m;
    // img = 3 x 3
    
    
    while (curSize <= 1) {
        vector<int> f_row = img[0];
        //first col -> first row
        for (int j = 2; j > 0; --j) {
            img[0][2-j] = img[j][0]; // 0,0 <- 2,0     0,1 <- 1,0
        }
        // last row -> first col
        for (int j = 1; j < 3; ++j) {
            img[j][0] = img[m][j];  // 1,0 <- 2,1     2,0 <- 2,2
        }

        // last col -> last row
        for (int j = 1; j < 3; ++j) {
            img[m][j] = img[j][m]  // 2,1 <- 1,2     2,2<- 0,2
        }
        //  first row - > last col
        for (int j = 0; j < m; ++j) {
            img[j][m] = f_row[j];
        }
    }
        


    
    
}


int main(){
    cout << "Hello, World!" << endl;
    return 0;
}
