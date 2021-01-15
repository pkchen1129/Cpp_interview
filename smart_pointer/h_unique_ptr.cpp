#include <iostream>

using namespace std;

// template <class T>
// class SmartPtr{
// public:
// 	explicit SmartPtr(T *p){
// 	    ptr = p;
// 	    cout<< "create" << endl;
//     }

//     ~SmartPtr(){
//     	cout<< "destroy" << endl;
//     	delete (ptr);
//     }
//     T & operator * () {  return *ptr; } 
//     T * operator -> () { return ptr; } 
// private:
// 	T *ptr;

// }; 

// int main()
// {
//     SmartPtr<int> ptr (new int());
//     *ptr = 20;
//     cout<< *ptr <<endl;

//     return 0;
// }




// Unique Pointer
#include <iostream>

template <typename T>
class UniquePtr {
private:
    T* m_ptr;
public:
    explicit UniquePtr(T* ptr) : m_ptr(ptr) {}
    UniquePtr(const UniquePtr<T>& other) = delete;
    UniquePtr(UniquePtr<T>&& ptr)
        : m_ptr(std::move(&ptr))
    {
        ptr.m_ptr = nullptr;
    }
    ~UniquePtr() {
        delete m_ptr;
    }
    
    UniquePtr<T>& operator=(UniquePtr<T> &&ptr) {
        if (this != ptr) {
            delete m_ptr;
            m_ptr = ptr.m_ptr;
            ptr.m_ptr = nullptr;
        } 
        return *this;
    }
    
    UniquePtr<T>& operator=(const UniquePtr<T>& uptr) = delete;
    
    T* operator-> () {
        return m_ptr;
    }
    T& operator* () {
        return *m_ptr;
    }
};



int main() {
    int* a = new int(2);
    int* b = a;
    UniquePtr<int> uptr(a);
    // UniquePtr<int> uptr2 = a;
    std::cout << *a;
}