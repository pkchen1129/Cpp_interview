// Ch9 p.243
#include <iostream>
#include <string.h>
using namespace std;
class MyString
{
private:
    char *buffer;
public:
    //Constructor
    MyString(const char* initstring)
    {
        // buffer = NULL;
        buffer = new char[strlen(initstring) + 1];
        strcpy(buffer, initstring);
    }
    // This is necessary Copy Constructor!!!!!
    MyString(const MyString& copy_)
    {
        // buffer = NULL;
        buffer = new char[strlen(copy_.buffer) + 1];
        strcpy(buffer, copy_.buffer);
        cout << "copy constructor" << endl;
    }   
    // This is a copy assignment operator=
    MyString& operator= (const MyString& copy_)
    {
         buffer = new char[strlen(copy_.buffer) + 1];
         strcpy(buffer, copy_.buffer);
        cout << "copy assignment operator=" << endl;

    }
    ~MyString()
    {
        delete [] buffer;
    }
    int Getlen()
    {
        return strlen(buffer); // Len of pointer
    } 
    const char* GetString()
    {
        return buffer;
    }
};
/*
    This would only perform shallow copy. It would happen to produce 2 pointers point to one memory
    Thus when the CopyMyString() func ends, it'll delete the memory first time. 
    Then if main() ends, it'll call the destructor and delete the memory second time which will cause troubles.
*/
void CopyMyString(MyString s)
{
    cout << s.GetString() << endl;
    return;
}

int main(){
    /*Call Copy constructor*/
    MyString s("This is life");
    // CopyMyString(s); // A way to call copy constructor
    MyString a = s; // Another way to call copy constructor
    MyString b(s); // Another way to call copy constructor



    /*Call copy Assignment operator=*/
    MyString c("Who cares?");
    c = s;

}