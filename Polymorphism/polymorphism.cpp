#include <iostream>
using namespace std;
class Fish
{
private:
    bool isFreshwater_;

public:
    // Could try with/without virtual
    virtual void swim(){
        std::cout << "I am a fish" << std::endl;
    }

};

class Tuna : public Fish
{
public:

    void swim()
    {
        std::cout << "I am Tuna" << std::endl;
    }
};

class Carp : public Fish
{
public:

    void swim(){

        std::cout << "I am Carp" << std::endl;

    }
};
/////////////
void print(Fish& inputfish){
    inputfish.swim();
}


int main(){
    Tuna t;
    Carp c;
    Fish f;

    print(t);
    print(c);
    print(f);
}


// ------------------------------------------ //
// Virtual Destructor