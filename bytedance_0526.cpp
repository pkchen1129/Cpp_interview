// You have an infinite number of stacks arranged in a row and numbered (left to right) from 0, each of the stacks has the same maximum capacity.

// Implement the DinnerPlates class:

// - DinnerPlates(int stackCapacity) Initializes the object with the maximum capacity of each stack.

// - void push(int val) pushes the given positive integer val into the leftmost stack with size less than capacity. If all stacks are full, create a new stack, insert the given integer into that stack, and append it to the existing stack collection.

// - int pop() returns the value at the top of the rightmost non-empty stack and removes it from that stack, and returns -1 if all stacks are empty.

// - int popAtStack(int index) returns the value at the top of the stack with the given index and removes it from that stack, and returns -1 if the stack with that given index is empty.

// Example:
// DinnerPlates d(2);  // Initialize with capacity = 2
// d.push(1); [1]
// d.push(2); [1, 2]
// d.push(3); [1, 2], [3]
// d.push(4); [1, 2], [3, 4]
// d.push(5);  [1, 2], [3, 4], [5]
// cout << d.popAtStack(0) << endl;   // Returns 2. [1], [3, 4], [5]
// d.push(20);   [1, 20], [3, 4], [5]
// d.push(21);  [1, 20], [3, 4], [5, 21]
// cout << d.popAtStack(0) << endl;   // Returns 20 [1], [3, 4], [5, 21]
// cout << d.popAtStack(2) << endl;   // Returns 21. [1], [3, 4], [5]
// cout << d.pop() << endl;            // Returns 5.
// cout << d.pop() << endl;         // Returns 4.
// cout << d.pop() << endl;           // Returns 3. 
// cout << d.pop() << endl;           // Returns 1.  There are no stacks.
// cout << d.pop() << endl;           // Returns -1.  There are still no stacks.

#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class DinnerPlates {
public:
    DinnerPlates(int stackCapacity) : capacity(stackCapacity){
    }

    void push(int val) {
        int p = 0;
        // At first
        if (v_stack.empty()) {
            stack<int> s;
            s.push(val);
            v_stack.push_back(s);
            return;
        }
        while (v_stack[p].size() == capacity ) {
            p++;      
        }
        
        // pushing element into old stacks
        if (p != v_stack.size()) {
            // In the middle
            v_stack[p].push(val);
        }
        else {
            // Adding new stacks
            stack<int> s;
            s.push(val);
            v_stack.push_back(s);
        }
    }

    int pop() {
        if (v_stack.empty()) {
            return -1;
        }
        int element = v_stack.back().top();
        v_stack.back().pop();
        if (v_stack.back().empty()) v_stack.pop_back();
        return element;
    }

    int popAtStack(int index) {
        if (index > v_stack.size() - 1 || v_stack[index].empty()) return -1;
        int ans = v_stack[index].top();
        v_stack[index].pop();
        return ans;
    }

    // Debug
    void print() {
        for (auto st : v_stack) {
            while (!st.empty()) {
                cout << st.top() << "  ";
                st.pop();
            }
            cout << endl;
        }
    }
private:
    vector<stack<int> > v_stack;
    int capacity;
};


int main () {
    DinnerPlates d(2);  // Initialize with capacity = 2
    d.push(1); //[1]
    d.push(2); //[1, 2]
    d.push(3); //[1, 2], [3]
    d.push(4); //[1, 2], [3, 4]
    d.push(5);  //[1, 2], [3, 4], [5]
    cout << d.popAtStack(0) << endl;   // Returns 2. [1], [3, 4], [5]
    d.push(20);   //[1, 20], [3, 4], [5]
    d.push(21);  //[1, 20], [3, 4], [5, 21]
    cout << d.popAtStack(0) << endl;   // Returns 20 [1], [3, 4], [5, 21]
    cout << d.popAtStack(2) << endl;   // Returns 21. [1], [3, 4], [5]
    cout << d.pop() << endl;            // Returns 5. [1], [3, 4]
    cout << d.pop() << endl;         // Returns 4. [1], [3]
    cout << d.pop() << endl;           // Returns 3. 
    cout << d.pop() << endl;           // Returns 1.  There are no stacks.
    cout << d.pop() << endl;           // Returns -1.  There are still no stacks.
}