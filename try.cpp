
//Quick Sort

#include <iostream>
#include <vector>

using namespace std;

void insertionsort(vector<int> &v){
    int n = v.size();
    for(int i = 0; i < n ; ++i){
        int key = v[i];
        int j = i - 1;
        while(v[j] > key && j>=0){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
}


int main()
{
    vector<int> v = {9, 4, 1, 6, 7, 3, 8, 2, 5};
    int n = v.size();
    insertionsort(v);
    for(auto a : v) cout << a << ",";
    return 0;
}
