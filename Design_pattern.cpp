/**
 * @file Design_pattern.cpp
 * @brief The most important thing is to prevent the code from changing client's code
 * Thus, we use a static function:
 *  
 * static Vehicle* Create(vehicletype type) 
 * 
 * to solve the problem. We create the static function so that 
 * @date 2021-02-17
 * 
 * 
 */

#include <iostream>
using namespace std;

enum vehicletype {
    two_wheel, three_wheel, fourth_wheel
};

class Vehicle
{
public:
    virtual void Print () 
    {
        cout << "It's Vehicle" << endl;
    }
    static Vehicle* Create(vehicletype type);
};

class twowheel : public Vehicle
{
public:
    void Print () {cout << "It's Twowheel Vehicle" << endl;}
};

class threewheel : public Vehicle
{
public:
    void Print () {cout << "It's Threewheel Vehicle" << endl;}
};

class fourthwheel : public Vehicle
{
public:
    void Print () {cout << "It's fourthwheel Vehicle" << endl;}
};
// Just like a socket so that it could be called in Client.
Vehicle* Vehicle::Create (vehicletype type) {
    if (type == two_wheel) return new twowheel();
    else if (type == three_wheel) return new threewheel();
    else if (type == fourth_wheel) return new fourthwheel();
    
    return NULL; 
}
// Don't need to change the content of client //
class Client
{
public:
    Client()
    {
        vehicletype type = three_wheel; // two_wheel, fourth_wheel
        pVehicle = Vehicle::Create(type);
    }
    ~Client()
    {
        if (pVehicle) {
            delete[] pVehicle;
            pVehicle = NULL;
        }
    }
    Vehicle* getvehicle(){
        return pVehicle;
    }
private:
    Vehicle* pVehicle;
};

////////////////////////////////////////////////////

int main() {
    Client * pclient = new Client();
    Vehicle * pVehicle = pclient->getvehicle();
    pVehicle->Print();
    return 0;
}