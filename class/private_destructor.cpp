/*
All objects on the stack get popped when the stack is unwound and therefore the compiler would need to 
compile and invoke the destructor ~private_destructor(). However, since it is private, it can't access.
*/
#include <iostream>
using namespace std;
class private_destructor
{
private:
    ~private_destructor(){};
public:

    // To avoid memory leak, we should declare a static destructor which could only be called once
    static void release_memory(private_destructor* pp)
    {
        delete pp;
    }
};

int main(){
    // private_destructor p; // Couldn't be declared on stack!!!!!!!!!
    private_destructor* p = new private_destructor(); // Could only be declared on heap!!!!!!!!!

    // delete p;
    //Use static member to destruct
    private_destructor::release_memory(p);
    return 0;
}


