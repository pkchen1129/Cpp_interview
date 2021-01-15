#include <iostream>
struct aggregate
{
    int a;
    int b;
};
int main(){
    aggregate agg{3,4};
    std::cout << agg.a;
    std::cout << agg.b;

}