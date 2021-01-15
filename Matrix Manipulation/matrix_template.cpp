// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class Matrix {
private:
    size_t _row;
    size_t _col;
    vector<T> _data;
    size_t _next(size_t curId);
    size_t _pre(size_t nextId);
    void _moveData(size_t id);
public:
    Matrix(size_t row, size_t col) : _row(row), _col(col), _data(row * col) {}
    T& getElement(size_t i, size_t j) {
        return _data[i * _col + j];
    }

    void setElement(size_t i, size_t j, T val) {
        _data[i * _col + j] = val;
    }

    void print() {
        for (int i = 0; i < _data.size(); ++i) {
            if (i % _col == 0)
                cout << endl;
            cout << _data[i] << "    ";
        }
        cout << endl << endl;
    }

    T& operator()(size_t i, size_t j) {
        return _data[i * _col + j];
    }

    void naive_transpose() {
        vector<T> dataT(int(_data.size()));
        for (int i = 0; i < _data.size(); ++i) {
            int n_col = i / _col;
            int n_row = i % _col;
            dataT[n_row * _row + n_col] = _data[i]; 
        }
        _data = dataT;
         std::swap(_row, _col);
    }
    // https://songlee24.github.io/2014/04/09/matrix-transpose-inplace/
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

template <typename T>
size_t Matrix<T>::_next(size_t curId) {
    //matrix[a][b], _row x _col, curId = a * _col + b 
    //transpose matrix[b][a], _col x _row, nextId = b * _row + a
    return (curId % _col) * _row + curId / _col;
}

template <typename T>
size_t Matrix<T>::_pre(size_t nextId) {
    //matrix[b][a], _col x _row, nextId = b * _row + a
    //matrix[a][b], _row x _col, id = a * _col + b
    return (nextId % _row) * _col + nextId / _row;
}

template <typename T>
void Matrix<T>::_moveData(size_t id) {
    size_t start = id;
    int temp = _data[id];
    size_t pre = _pre(id);
    while (pre != start) {
        _data[id] = _data[pre];
        id = pre;
        pre = _pre(pre);
    }
    _data[id] = temp;
}

int main() {
    // Write C++ code here
    Matrix<double> A(4,3);
    A(0, 0) = 1.1;
    A(0, 1) = 2.2;
    A(0, 2) = 3.3;
    A(1, 0) = 4.4;
    A(1, 1) = 5.5;
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