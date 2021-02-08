#include <iostream>
#include <vector>
using namespace std;

// Matrix 2D double
// num_row, cols, num
// [num num ]
// M.trans() m
class Matrix 
{
public:
  // Matrix () : rows(2), cols(2), vals(0) {}
  Matrix (int row, int col, int val) : rows(row), cols(col), vals(val) ,m(rows, vector<int>(cols,vals)), t_cols(row), t_row(col)
  {

    for (int i = 0 ; i < rows; ++i) {
      vector<int> a;
      for (int j = 0 ; j < cols ; ++j) {
        a.push_back(vals);
      }
      m.push_back(a);
    }
    

    
    for (int i = 0 ; i < t_row; ++i) {
      vector<int> a;
      for (int j = 0 ; j < t_cols ; ++j) {
        a.push_back(vals);
      }
      m_.push_back(a);
    }
  
  }
  
  
  void trans(){
    for (int i = 0 ; i < t_row; ++i) {
      for (int j = 0 ; j < t_cols ; ++j) {
        m_[i][j] = m[j][i];
      }
    }
  }
  
  void print1 () {
    for (int i = 0 ; i < rows; ++i) {
      for (int j = 0 ; j < cols ; ++j) {
        cout << m[i][j]  << " ";
      }
      cout << endl;
    }
  }
  void print2 () {
    for (int i = 0 ; i < t_row; ++i) {
      for (int j = 0 ; j < t_cols ; ++j) {
        cout << m_[i][j]  << " ";
      }
      cout << endl;
    }
  }
  
  
private:
  int rows;
  int cols;
  int vals;
  
  int t_cols = rows;
  int t_row = cols;
  vector<vector<int>> m;
  vector<vector<int>> m_;
  
  // int a[];
};
// To execute C++, please define "int main()"
int main() {
  Matrix M(2,3,-1);
  M.print1();
  M.trans();
  M.print2();
  
  
}
