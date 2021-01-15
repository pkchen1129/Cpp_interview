#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class SparseMatrix{
    const int MAX = 100;
    int **data;
    int row, col;
    int len; // Using len to know how big is the matrix is!!!
public:
    SparseMatrix(int r, int c) : row(r), col(c), len(0){
        data = new int *[MAX];
        for(int i = 0 ; i < MAX ; ++i){
            data[i] = new int[3];
        }
    }
    void insert(int r, int c, int val){
        if(r > row || c > col){
            cout << "Wrong!!!" << endl;
        }
        else{
            data[len][0] = r;
            data[len][1] = c;
            data[len][2] = val;
            len++;
        }
    }
    void add(SparseMatrix b){
        if(b.row != row || b.col != col){
            cout << "not match" << endl;
        } 
        else{
            SparseMatrix result(row,col);

            // Initiate two pointers
            int a_point = 0, b_point = 0;
            
            while(a_point < len && b_point < b.len){
                // b's index is smaller
                if(data[a_point][0] > b.data[b_point][0] || data[a_point][0] == b.data[b_point][0] && data[a_point][1] > b.data[b_point][1]){
                    result.insert(b.data[b_point][0], b.data[b_point][1], b.data[b_point][2]);
                    b_point++;
                }
                // a's index is smaller
                else if(data[a_point][0] < b.data[b_point][0] || data[a_point][0] == b.data[b_point][0] && data[a_point][1] < b.data[b_point][1]){
                    result.insert(data[a_point][0], data[a_point][1], data[a_point][2]);
                    a_point++;
                }
                // IF both are same
                else{
                    int val = data[a_point][2] + b.data[b_point][2];
                    result.insert(data[a_point][0],data[a_point][1],val);
                    a_point++;
                    b_point++;
                }
                
            }
            while (a_point < len) 
                result.insert(data[a_point][0], 
                                data[a_point][1], 
                                data[a_point++][2]); 

            while (b_point < b.len) 
                result.insert(b.data[b_point][0], 
                                b.data[b_point][1], 
                                b.data[b_point++][2]);
            result.print(); 
        }  
    }
    SparseMatrix transpose(){
        SparseMatrix result(row,col);
        result.len = len;
        
        for(){
            
        }
        return result;
    }
    void print() 
    { 
        cout << "\nDimension: " << row << "x" << col; 
        cout << "\nSparse Matrix: \nRow\tColumn\tValue\n"; 
  
        for (int i = 0; i < len; i++) 
        { 
            cout << data[i][0] << "\t " << data[i][1]  
                 << "\t " << data[i][2] << endl; 
        } 
    } 

};





int main(){
    SparseMatrix a(4,4);
    SparseMatrix b(4,4);
    a.insert(1, 2, 10); 
    a.insert(1, 4, 12); 
    a.insert(3, 3, 5); 
    a.insert(4, 1, 15); 
    a.insert(4, 2, 12); 
    b.insert(1, 3, 8); 
    b.insert(2, 4, 23); 
    b.insert(3, 3, 9); 
    b.insert(4, 1, 20); 
    b.insert(4, 2, 25); 
    a.add(b);





}