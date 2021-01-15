#include <iostream>
using namespace std;

class Motor
{
private:
    bool isFreshwater_;

public:
    Motor(){}
    Motor(bool isFreshwater) : isFreshwater_(isFreshwater){}
    void ignite(){
        std::cout << "I am a Motor" << std::endl;
    }
    void hello(){
        std::cout << "hello" << endl;
    }
};


class Car : private Motor
{
public:
    Car() : Motor(false){}
    void ignite()
    {
        std::cout << "I am Car" << std::endl;
    }
};





int main(){
    Car t;
    t.ignite();
    // t.hello(); // It can't access the hello();
}