#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <assert.h>

using namespace std;

const int INITIAL_SIZE = 8;

class String {
public:
// Initialize an empty string.
String() {
    // Constructor: points the pointer to memory.
    buf_ = new char[INITIAL_SIZE];
    length_ = 0;
    capacity = INITIAL_SIZE;
}

// Get the ith character (0 indexed).
char get(int i) {
  assert(i < length_ && i >= 0);
  return buf_[i];
}

// Append c to the end of the string.
void append(char c) {
    //check if need to resize, check if 8 16 32 64... resize
    if (length_ == capacity){
        capacity *= 2;
        char* new_buf_ = new char[capacity];
        for (int i=0; i < capacity; i++){
            new_buf_[i] = buf_[i];
        }
        delete buf_;  // deallocate!
        buf_ = new_buf_;// set old buf to new one
    }
    buf_[length_] = c;
    length_ += 1;
}

// Get the length of the string.
int length() {
    return length_;
}
private:
    // Fill this in.
    char* buf_;
    int length_;
    int capacity;
};

int main() {
    String s;
    s.append('c');
    assert(s.get(0) == 'c');
    assert(s.length() == 1);
    return 0;
}