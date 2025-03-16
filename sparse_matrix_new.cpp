/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
class SparseMatrix {
private:
    vector<vector<int>> v; // sparse matrix
public:
    SparseMatrix (vector<vector<int>>& input) {
        ToSparse(input);
    }
    void ToSparse (vector<vector<int>>& input) {
        for (int i = 0; i < input.size(); ++i) {
            for (int j = 0; j < input[0].size(); ++j) {
                if (input[i][j] == 0) continue;
                v.push_back({i, j, input[i][j]});
            }
        }
        return;
    }
    void ToNormal () {
        int r = 0, c = 0;
        for (const auto& input : v) {
            r = max(r, input[0] + 1);
            c = max(c, input[1] + 1);
        }
        vector<vector<int>> normal(r, vector<int>(c, 0));
        for (const auto& i : v) {
            normal[i[0]][i[1]] = i[2];
        }
        print(normal);
        return;
    }

    SparseMatrix operator+(SparseMatrix const& other) {
        vector<vector<int>> result(v.size(), vector<int>(v[0].size(), 0));
        for (int i = 0; i < v.size(); ++i) {
            for (int j = 0; j < other.v.size(); ++j) {
                int ai = v[i][0], ak = v[i][1], aik = v[i][2];
                int bk = other.v[j][0], bj = other.v[j][1], bkj = other.v[j][2];
                if (ai == bk && ak == bj) result[ai][bj] += aik + bkj;
            }
        }
        return SparseMatrix(result);
    }
    SparseMatrix operator*(SparseMatrix const& other) {
        // Need check size
        vector<vector<int>> result(v.size(), vector<int>(v[0].size(), 0));
        for (int i = 0; i < v.size(); ++i) {
            for (int j = 0; j < other.v.size(); ++j) {
                int ai = v[i][0], ak = v[i][1], aik = v[i][2];
                int bk = other.v[j][0], bj = other.v[j][1], bkj = other.v[j][2];
                if (ai == bk) result[ai][bj] += aik * bkj;
            }
        }
        return SparseMatrix(result);
    }
    
    void print(vector<vector<int>> vv) {
        cout << "====print=====" << endl;
        for (int i = 0 ; i < vv.size() ; ++i) {
            for (int j = 0 ; j < vv[0].size() ; ++j) {
                cout << vv[i][j] << ", ";
            }
            cout << endl;
        }
    }
    void printSparse() {
        cout << "====print sparse=====" << endl;
        for (int i = 0 ; i < v.size() ; ++i) {
            for (int j = 0 ; j < v[0].size() ; ++j) {
                cout << v[i][j] << ", ";
            }
            cout << endl;
        }
    }
    
};


int main()
{
    vector<vector<int>> v1 {{1,4},{1,1}};
    vector<vector<int>> v2 {{1,1},{1,7}};
    SparseMatrix o1(v1);
    SparseMatrix o2(v2);
    o1.printSparse();
    o2.printSparse();
    SparseMatrix o = o1 + o2;
    SparseMatrix o3 = o1 * o2;
    o.printSparse();
    o.ToNormal();
    o3.printSparse();
    o3.ToNormal();
    return 0;
}
