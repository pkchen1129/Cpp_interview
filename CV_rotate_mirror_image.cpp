#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Rotate: Transpose then Reverse at each row
void rotate_square_image(vector<vector<u_char>>& matrix) {
    int n = matrix.size();
    for (int i = 0 ; i < n-1 ; ++i){
        for(int j = 0 ; j < n-i ; j++){
            swap(matrix[i][j] , matrix[n - 1 - j][n - 1 - i]);
        }
    }
    reverse(matrix.begin(), matrix.end());
}

// When not square, Doing transpose
vector<vector<u_char>> rotate (vector<vector<u_char>>& matrix) {
    int n= matrix[0].size();
    int m = matrix.size();
    vector<vector<u_char>> output(n, vector<u_char>(m));
    for (int r = 0; r < m; r++)  
    {  
        for (int c = 0; c < n; c++)  
        {  
            output[c][r] = matrix[r][c];
        }  
    }  
    return output;
}

// When not square, doing Rotate
vector<vector<u_char>> rotate (vector<vector<u_char>>& matrix) {
    int n= matrix[0].size();
    int m = matrix.size();
    vector<vector<u_char>> output(n, vector<u_char>(m));
    for (int r = 0; r < m; r++)  
    {  
        for (int c = 0; c < n; c++)  
        {  
            output[c][r] = matrix[r][c];
        }  
        reverse(output.begin(), output.end());
    }  
    return output;
}

void MirrorImage (vector<vector<unsigned char >>& PixelGrid)
{
    int n= PixelGrid[0].size();
    int m = PixelGrid.size();

    for (int row = 0; row < m / 2; row++)
    {
        for (int col = 0; col < n ; col++)
        {
            int swapRow = m - 1 - row; // Mirror pixel

            unsigned char temp = PixelGrid[row][col];
            PixelGrid[row][col] = PixelGrid[swapRow][col];
            PixelGrid[swapRow][col] = temp;

        }
    }
}