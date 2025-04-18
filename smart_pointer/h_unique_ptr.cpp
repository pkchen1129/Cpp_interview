#include <iostream>

// Unique Pointer class
template <typename T>
// only use in make_unique:     template <typename T, typename... Args>
class UniquePointer {
private:
    T* ptr; // Raw pointer

public:
    // Constructor
    explicit UniquePointer(T* p = nullptr) : ptr(p) {}

    // Destructor - deletes the managed object
    ~UniquePointer() {
        delete ptr;
    }

    // Delete copy constructor and copy assignment operator
    UniquePointer(const UniquePointer&) = delete;
    UniquePointer& operator=(const UniquePointer&) = delete;

    // Move constructor
    UniquePointer(UniquePointer&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    // Move assignment operator
    UniquePointer& operator=(UniquePointer&& other) noexcept {
        if (this != &other) {
            delete ptr; // Free existing resource
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    // Overload dereference operator
    T& operator*() const { return *ptr; }

    // Overload arrow operator
    T* operator->() const { return ptr; }

    // Get raw pointer (for debugging or special use cases)
    T* get() const { return ptr; }

    // Release ownership of the managed object
    T* release() {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }

    // Reset the unique pointer with a new object
    void reset(T* newPtr = nullptr) {
        delete ptr;
        ptr = newPtr;
    }
    // make_unique
    UniquePtr<T> make_unique(Args&&... args) {
        return UniquePtr<T>(new T(std::forward<Args>(args)...));
    }
};

// Example usage
class Test {
public:
    void show() { std::cout << "Test class method called!" << std::endl; }
}

class Test {
public:
    void hello() {
        cout << "Hello from Test!" << endl;
    }
};

int main() {
    UniquePointer<int> upInt(new int(42));
    UniquePointer<int> upInt = new int(42); // Error. bc of explicit constructor
    UniquePtr<Test> p1(new Test());

    UniquePtr<Test> p2 = std::move(p1);  // Move construct

    if (p1.get() == nullptr) {
        cout << "p1 is empty after move." << endl;
    }

    p2.reset(new Test());  // Reset 指到新物件

    UniquePtr<Test> p3;
    p3 = std::move(p2);  // Move assign
}
/*
1. 禁止 copy
2. 支援 move
3. 自動 delete
4. get() / reset() / release() 基本 API
5. * / -> 支援用法

*/
