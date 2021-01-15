#include <iostream>
// class Fish
// {
// protected:
//     bool isFreshwater;
    
// };

// class Tuna : public Fish
// {
// public:
//     Tuna()
//     {
//         //Since it is protected, it could only be accessed by derived here in this class
//         isFreshwater = true;
//     }
//     void swim(){
//         isFreshwater = false;
//         std::cout << isFreshwater << std::endl;
//     }
// };





// int main(){
//     Tuna t;
//     t.swim();
//     // t.isFreshwater = false; //this is not accessible b.c. it is protected
// }



//--------------------------------------------------------------------------------//
// Override
class Fish
{
private:
    bool isFreshwater_;

public:
    Fish(){}
    Fish(bool isFreshwater) : isFreshwater_(isFreshwater){}
    void swim(){
        std::cout << "I am a fish" << std::endl;
    }
    void hello(){
        std::cout << "Hello" << std::endl;
        
    }
};

class Tuna : public Fish
{
public:
    Tuna() : Fish(false){}
    void swim()
    {
        std::cout << "I am Tuna" << std::endl;
    }
};

class Carp : public Fish
{
public:
    Carp() : Fish(true){}
    void swim(){

        std::cout << "I am Carp" << std::endl;

    }
};


int main(){
    Tuna t;
    Carp c;
    Fish f;
    //These three shows that swim() would override the base function!!!!!!!
    t.swim();
    t.Tuna::swim();
    c.swim();

    f.swim();
    c.Fish::swim(); // Could invoke base function with derived instance
    t.Fish::swim();

    c.hello(); //Inherit from base case
}


//------------------------------------------------------------------//
// Order of construction //
