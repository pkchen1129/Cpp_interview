// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;
class Matrix {
private:
    size_t _row;
    size_t _col;
    vector<int> _data;
    size_t _next(size_t curId);
    size_t _pre(size_t nextId);
    void _moveData(size_t id);
public:
    Matrix(size_t row, size_t col) : _row(row), _col(col), _data(row * col) {}
    // Get element
    int& getElement(size_t i, size_t j) {
        return _data[i * _col + j];
    }
    // Set element
    void setElement(size_t i, size_t j, int val) {
        _data[i * _col + j] = val;
    }
    // Print
    void print() {
        for (int i = 0; i < _data.size(); ++i) {
            if (i % _col == 0)
                cout << endl;
            cout << _data[i] << "    ";
        }
        cout << endl << endl;
    }

    // Overloading operator ()
    int& operator()(size_t i, size_t j) {
        return _data[i * _col + j];
    }

    void naive_transpose () {
        vector<int> dataT(int(_data.size()));
        std::swap(_row, _col);
        for (int i = 0 ; i < data.size() ; ++i) {
            int n_col = i / _row; // row for now is the new "row"
            int n_row = i % _row;
            dataT[n_row * _col + n_col] = data[i];
        }
        _data = dataT;
    }

    void transpose() {
        for (int i = 0; i < _data.size(); ++i) {
            int cur = i;
            int next = _next(cur);
            while (next > cur)
                next = _next(next);
            // next == cur or next < cur (skip)
            if (next == cur)
                _moveData(cur);
        }
        std::swap(_row, _col);
    }
    
};

size_t Matrix::_next(size_t curId) {
    //matrix[a][b], _row x _col, curId = a * _col + b 
    //transpose matrix[b][a], _col x _row, nextId = b * _row + a
    return (curId % _col) * _row + curId / _col;
}

size_t Matrix::_pre(size_t nextId) {
    //matrix[b][a], _col x _row, nextId = b * _row + a
    //matrix[a][b], _row x _col, id = a * _col + b
    return (nextId % _row) * _col + nextId / _row;
}

void Matrix::_moveData(size_t id) {
    size_t start = id;
    int temp = _data[start];
    size_t pre = _pre(start);
    while (pre != id) {
        _data[start] = _data[pre];
        start = pre;
        pre = _pre(pre);
    }
    _data[start] = temp;
}

int main() {
    // Write C++ code here
    Matrix A(4,3);
    A(0, 0) = 1;
    A(0, 1) = 2;
    A(0, 2) = 3;
    A(1, 0) = 4;
    A(1, 1) = 5;
    A(1, 2) = 6;
    A(2, 0) = 7;
    A(2, 1) = 8;
    A(2, 2) = 9;
    A(3, 2) = 6;
    A.print();
    A.naive_transpose();
    A.print();
    A.transpose();
    A.print();
    std::cout << "Hello world!";

    return 0;
}