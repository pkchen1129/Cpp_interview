#include <iostream>
// #include <>
class President
{
private:
    // 1. Private default constructor: Can't declare outside!!!
    President(){};
    // 2. Create private copy constructor
    President(const President& copy_president);
    // 3. Create private copy assignment operator
    President& operator= (const President&);
public:
    // President(){};
    //Create static instance member
    static President& Getinstance(){
        static President onlyinstance; // There's gonna be only one instance
        return onlyinstance;
    }
};

int main(){
    //The only way to create instance!!!
    President& onlypresident = President::Getinstance();

    //The followings are some incorrect ways
    /*
    1. Can't access private default constructor, stack or heap
    President second;
    President* third = new President();

    2. Can't access Copy Constructor
    President fourth = onlypresident;

    3. Can't access operator= (Want to create a copy via assignment)
    onlypresident = President::Getinstance();
    */
   return 0;
}