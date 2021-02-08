#include <iostream>
#include <cmath>

/*
 f(x) = x^2 - 1
 x' = x - f(x)/f(x)';
 
 f'(x) = 2*x;
 
*/
using namespace std;

int main()
{
    double error = 0;
    int count = 0;
    double x = 4;
    
    while (abs( (x*x - 1) / (2*x) ) > 0.00001) {
        x = x - (x*x - 1) / (2*x);
        count++;
        cout << x << " ";
    }
    cout << "count = " << count << endl;
    
}
