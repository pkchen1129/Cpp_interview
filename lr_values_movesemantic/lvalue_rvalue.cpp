#include <iostream>

using namespace std;
void SetValue (int& val) {
    
}
// Using const would accept both.
void Print (const int& a) {
    cout << "Accept both" << endl;
}
void Print (int& a) {
    cout << "Accept only lvalue" << endl;
}
void Print (int&& a) {
    cout << "Accept only rvalue" << endl;
}

int main()
{
    int i = 10;
    int SetValue(i);
    
    /*Test1*/
    // Cannot use a reference lvalue to receive a right value, except using const.
    // int& a = 10; // no
    const int& b = 10; // yes
    
    
    /*Test2*/
    int c = 12; // c and d is lvalue
    int d = 13;
    // c+d is rvalue
    
    Print(c+d); //Will only call "Accept only rvalue"
    Print(c); //Will only call "Accept only lvalue"
    return 0;
}

