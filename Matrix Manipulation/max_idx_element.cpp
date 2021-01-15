#include <vector>  
#include <algorithm>  
#include <iostream>  
using namespace std;
int main()
{
    int a[] = { 2, 3, 5, 4, 6,1,6 };
    vector<int>b (a,a+5);
    
    auto p = max_element(b.begin(), b.end());
    auto q = min_element(b.begin(), b.end());
    cout << *p << endl;
    cout << *q << endl;
    cout << std::distance(b.begin(), p) << endl;
    // system("pause");
    return 0;

}