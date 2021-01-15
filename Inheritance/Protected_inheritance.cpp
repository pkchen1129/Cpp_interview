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


class Car : protected Motor
{
public:
    Car() : Motor(false){}
    void ignite()
    {
        std::cout << "I am Car" << std::endl;
    }
    void hello_Car(){
        std::cout << "hello_car" << endl;
    }
};

class RaceCar : protected Car
{
public:
    RaceCar(){}
    void ignite()
    {
        std::cout << "I am Racecar" << std::endl;
        //!!!!!!! From here it could access the derived class Car and the derived derived class Motor
        hello();
        hello_Car();  
    }
};





int main(){
    Car t;
    t.ignite(); //
    // t.hello(); // It still can't access the hello();

    RaceCar r;
    r.ignite(); // It can access the ignite();

}

