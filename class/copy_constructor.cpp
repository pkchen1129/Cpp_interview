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
    MyString s("This is life");
    CopyMyString(s);
    // However, if you want to do the following, it would still be shallow copy. If want deep copy, do the copy assignemnet operator!!!!!
    /*
    MyString overwite("Who cares?");
    overwrite = s;
    */
}