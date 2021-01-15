//Multiple inheritance
#include <iostream>
using namespace std;

class Motor
{
private:
    bool isFreshwater_;

public:
    Motor(){}
    void ignite(){
        std::cout << "I am a Motor" << std::endl;
    }
    // void hello(){
    //     std::cout << "hello" << endl;
    // }
};

class Wheel
{
public:
    void pressure(){
        cout << "Pressure" << endl;
    }
};

class Glass
{
public:
    void hardness(){
        cout << "hardness" << endl;
    }
};


class Car : public Motor , public Wheel , public Glass
{
public:
    Car(){}
    void ignite()
    {
        std::cout << "I am Car" << std::endl;
    }
};





int main(){
    Car c;
    c.ignite();
    c.hardness();
    c.pressure();
    // t.hello(); // It can't access the hello();
}