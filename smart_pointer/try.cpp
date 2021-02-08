// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class counter {
public: 
    counter() : m_counter(0){}
    counter(const counter& copy_) = delete;
    counter& operator=(const counter& assign_) = delete;
    ~counter() = default;

    size_t get() {
        return m_counter;
    }
    void operator++(){
        ++m_counter;
    }
    void operator--(){
        --m_counter;
    }
    ostream& operator<<(ostream& os, const counter& counter)
    {
        os << "value :" << counter.m_counter << endl;
    }
private:
    size_t m_counter;
};

class Sharedptr
{
public: 
    explicit Sharedptr() {
        
    }
private:
    int * ptr;
    counter* m_counter;
};

