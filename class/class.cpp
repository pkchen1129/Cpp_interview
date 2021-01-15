#include <iostream>
// #include <string>
class Human{
private:
    int age;
    // string phonenum;
public:
    Human(){
        age = 1;
    }
    Human(int x) : age(x)
    {
        // age = x;
    }
    void setage(int x){
        age = x;
    }
    int getage(){
        return age;
    }
};
int main(){
    Human* Brian = new Human(5);
    // Brian->setage(20);
    std::cout << Brian->getage() << std::endl;
}