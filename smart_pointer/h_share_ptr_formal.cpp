// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Counter {
public:
    Counter() : m_counter(0) {}
    Counter(const Counter& other) = delete; // Copy constructor
    Counter& operator=(const Counter& other) = delete;

    ~Counter() = default;

    void reset() {
        m_counter = 0;
    }

    size_t get() {
        return m_counter;
    }

    void operator++() {
        ++m_counter;
    }

    void operator--() {
        --m_counter;
    }

        // Overloading << operator 
    friend ostream& operator<<(ostream& os, const Counter& counter) 
    { 
        os << "Counter Value : "
           << counter.m_counter << endl; 
    } 
private: 
    size_t m_counter; 
    
};

/**
 * Two pointers in the private: 1. int pointer  2. Count pointer.
 * 
**/
class SharedPtr {
public:
    explicit SharedPtr(int* ptr) : m_ptr(ptr) {
        m_counter = new Counter();
        if (ptr)
            ++(*m_counter);
    }
    //
    SharedPtr(const SharedPtr& other) {
        m_ptr = other.m_ptr;
        m_counter = other.m_counter;
        ++(*m_counter);
    }
    ~SharedPtr() {
        --(*m_counter);
        if (!m_counter->get()) {
            delete m_counter;
            delete m_ptr;
        }
    }
    
    int* get() { 
        return m_ptr; 
    } 

    int* operator->() {
        return m_ptr;
    }

    int& operator*() {
        return *m_ptr;
    }
    
    friend ostream& operator<<(ostream& os, SharedPtr& sp) { 
        os << "Address pointed : "
           << sp.get() << endl; 
        cout << *(sp.m_counter) << endl; 
    } 


private:
    int* m_ptr;
    Counter* m_counter; 
};

int main() { 
    // ptr1 pointing to an integer. 
    SharedPtr ptr1(new int(151)); 
    cout << "--- Shared pointers ptr1 ---\n"; 
    *ptr1 = 100; 
    cout << " ptr1's value now: " << *ptr1 << endl; 
    cout << ptr1; 
  
    { 
        // ptr2 pointing to same integer where ptr1 is pointing to 
        // Shared pointer reference counter should have 
        // increased now to 2. 
        SharedPtr ptr2 = ptr1; // Using copy constructor
        cout << "--- Shared pointers ptr1, ptr2 ---\n"; 
        cout << ptr1; 
        cout << ptr2; 
  
        { 
            // ptr3 pointing to same integer which 
            // ptr1 and ptr2 are pointing to. 
            // Shared pointer reference counter 
            // should have increased now to 3. 
            SharedPtr ptr3(ptr2); // Also using copy constructor
            cout << "--- Shared pointers ptr1, ptr2, ptr3 ---\n"; 
            cout << ptr1; 
            cout << ptr2; 
            cout << ptr3; 
        } 
  
        // ptr3 is out of scope. 
        // It would have been destructed. 
        // So shared pointer reference counter 
        // should have decreased now to 2. 
        cout << "--- Shared pointers ptr1, ptr2 ---\n"; 
        cout << ptr1; 
        cout << ptr2; 
    } 
  
    // ptr2 is out of scope. 
    // It would have been destructed. 
    // So shared pointer reference counter 
    // should have decreased now to 1. 
    cout << "--- Shared pointers ptr1 ---\n"; 
    cout << ptr1; 
  
    return 0; 
}









// //// Template Method
// #include <iostream>
// #include <string>
// using namespace std;
// class Counter {
// public:
//     Counter() : m_counter(0) {}
//     Counter(const Counter& other) = delete;
//     Counter& operator=(const Counter& other) = delete;

//     ~Counter() = default;

//     void reset() {
//         m_counter = 0;
//     }

//     size_t get() {
//         return m_counter;
//     }

//     void operator++() {
//         ++m_counter;
//     }

//     void operator--() {
//         --m_counter;
//     }

//         // Overloading << operator 
//     friend ostream& operator<<(ostream& os, const Counter& counter) 
//     { 
//         os << "Counter Value : "
//            << counter.m_counter << endl; 
//     } 
// private: 
//     size_t m_counter; 
    
// };

// template<typename T>
// class SharedPtr {
// public:
//     explicit SharedPtr(T* ptr) : m_ptr(ptr) {
//         m_counter = new Counter();
//         if (ptr)
//             ++(*m_counter);
//     }
//     SharedPtr(const SharedPtr<T>& other) {
//         m_ptr = other.m_ptr;
//         m_counter = other.m_counter;
//         ++(*m_counter);
//     }
//     ~SharedPtr() {
//         --(*m_counter);
//         if (!m_counter->get()) {
//             delete m_counter;
//             delete m_ptr;
//         }
//     }
    
//     T* get() { 
//         return m_ptr; 
//     } 

//     T* operator->() {
//         return m_ptr;
//     }

//     T& operator*() {
//         return *m_ptr;
//     }
    
//     friend ostream& operator<<(ostream& os, SharedPtr<T>& sp) { 
//         os << "Address pointed : "
//            << sp.get() << endl; 
//         cout << *(sp.m_counter) << endl; 
//     } 


// private:
//     T* m_ptr;
//     Counter* m_counter; 
// };

// int main() { 
//     // ptr1 pointing to an integer. 
//     SharedPtr<string> ptr1(new string("abc")); 
//     cout << "--- Shared pointers ptr1 ---\n"; 
//     *ptr1 = "foo"; 
//     cout << " ptr1's value now: " << *ptr1 << endl; 
//     cout << ptr1; 
  
//     { 
//         // ptr2 pointing to same integer 
//         // which ptr1 is pointing to 
//         // Shared pointer reference counter 
//         // should have increased now to 2. 
//         SharedPtr<string> ptr2 = ptr1; 
//         cout << "--- Shared pointers ptr1, ptr2 ---\n"; 
//         cout << ptr1; 
//         cout << ptr2; 
  
//         { 
//             // ptr3 pointing to same integer 
//             // which ptr1 and ptr2 are pointing to. 
//             // Shared pointer reference counter 
//             // should have increased now to 3. 
//             SharedPtr<string> ptr3(ptr2); 
//             cout << "--- Shared pointers ptr1, ptr2, ptr3 ---\n"; 
//             cout << ptr1; 
//             cout << ptr2; 
//             cout << ptr3; 
//         } 
  
//         // ptr3 is out of scope. 
//         // It would have been destructed. 
//         // So shared pointer reference counter 
//         // should have decreased now to 2. 
//         cout << "--- Shared pointers ptr1, ptr2 ---\n"; 
//         cout << ptr1; 
//         cout << ptr2; 
//     } 
  
//     // ptr2 is out of scope. 
//     // It would have been destructed. 
//     // So shared pointer reference counter 
//     // should have decreased now to 1. 
//     cout << "--- Shared pointers ptr1 ---\n"; 
//     cout << ptr1; 
  
//     return 0; 
// } 