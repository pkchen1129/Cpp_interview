// Online C++ compiler to run C++ program online
#include <iostream>
#include <string.h>
class String 
{
public:
    String() = default;
    String(const char* string)
    {
        printf("Created!\n");
        m_Size = strlen(string);
        m_Data = new char[m_Size];
        memcpy(m_Data, string, m_Size);
    }
    // Normal Copy constructor is required since => Entity entity(String("Cherno"));
    String(const String& other)
    {
        printf("Copied!\n");
        m_Size = other.m_Size;
        m_Data = new char[m_Size]; // That's not a good thing for that we'll need to allocate a new temporary memory 
        memcpy(m_Data, other.m_Data, m_Size);
    }
    // Move constructor!!!! Will do move! rather than copy when doing => : m_Name(name)
    String(String&& other) noexcept
    {
        printf("Moved!\n");
        m_Size = other.m_Size;
        m_Data = other.m_Data; // // We're doing assigning the pointer but not allocate new memories!!!

        // Create a hollow object  
        other.m_Size = 0;     
        other.m_Data = nullptr;
    }
    //Move assign operator
    String& operator=(String&& other) noexcept
    {
        printf("Assigned!\n");
        if (this != &other) // to prevent if we did other = other in main
        {
            if (m_Data) delete[] m_Data; // because we are overwrite here
            m_Size = other.m_Size;       // need to delete original data
            m_Data = other.m_Data;     
            other.m_Size = 0;
            other.m_Data = nullptr;            
        }
        return *this;
    }
    
    ~String()
    {
        printf("Destroyed!\n");
        delete[] m_Data;
    }
    
    void Print()
    {
        for (uint32_t i = 0; i < m_Size; ++i)
            printf("%c", m_Data[i]);
        printf("\n");
    }
private:
    char* m_Data;
    uint32_t m_Size;
};

class Entity
{
public:
    Entity(const String& name)
        : m_Name(name)
    {
    }
    
    Entity(String&& name) // Could input rvalue
        : m_Name(std::move(name)) // Change to lvalue
    {
    }
    
    void PrintName()
    {
        m_Name.Print();
    }
private:
    String m_Name;
};
int main() {
    // Write C++ code here
    Entity entity(String("Cherno")); // Will have to create memory twice from  "Cherno" -> String -> Entity by copy constructor of String
    entity.PrintName();
    

    // Doing Moving Constructor
    String string = "Hello";
    String dest(std::move (string)); //  = String dest = std::move(string);
    
    // Assign operator
    // String dest1;
    // dest1 = std::move(string);
    
    // String apple = "Apple";
    return 0;
}