#include <iostream>

// Unique Pointer class
template <typename T>
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
};

// Example usage
class Test {
public:
    void show() { std::cout << "Test class method called!" << std::endl; }
};

int main() {
    UniquePointer<Test> up(new Test()); // Creating a unique pointer
    up->show(); // Accessing methods using -> operator

    UniquePointer<int> upInt(new int(42));
    // UniquePointer<int> upInt = new int(42); // Error. bc of explicit constructor
    std::cout << "UniquePointer holds: " << *upInt << std::endl;
    
    return 0;
}
