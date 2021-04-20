// 例如 space/time locality 为什么用array比 hashmap好？
// 例如 为什么resize array的时候不应该线性，可以用每次size成倍增加实现 append的time complexity接近O(1)
//       N/8 => N/16 => N/32 ==> 1  
// https://www.drdobbs.com/c-made-easier-how-vectors-grow/184401375 
// If increase in constant ex: 1.5 or 2, it'll be O(n) for the final copy complexity)
// b.c. n/16 + n/8 + n/4 + n/2 + n < O(2n) => O(n)
// 1 < k < 2
// https://www.zhihu.com/question/36538542 (The best situation might be 1.5)
// 例如 C++ array操作中新开和释放内存 


#include <bits/stdc++.h>
using namespace std;
const int INITIAL_SIZE = 8;
template <typename T> 
class Vector 
{
    T* arr;
    int capacity;
    int sizet;
 
public:
    // Default constructor to initialise
    // an initial capacity of 1 element and
    // allocating storage using dynamic allocation
    Vector() : arr(new T[INITIAL_SIZE]), capacity(1), sizet(0) {}
    Vector(const Vector &v)   //copy constructor
        : capacity(v.capacity),
          sizet(v.sizet),
          arr(new T[v.sizet])
    {            
        std::copy(v.arr, v.arr + sizet, arr);

    }
    T &operator [](const int index){            //overloading index[] operator
        return arr[index];
    }
    // Function to add an element at the last
    void push_back(T data)
    {
        if (sizet == capacity) {
            T* temp = new T[2 * capacity];
            // copying old array elements to new array
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }
            // deleting previous array
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
        // Inserting data
        arr[sizet] = data;
        sizet++;
    }
 
    // function to add element at any index
    void push(int data, int index)
    {
 
        // if index is equal to capacity then this
        // function is same as push defined above
        if (index == capacity)
            push_back(data);
        else
            arr[index] = data;
    }
 
    // function to extract element at any index
    
    // T get(int index)
    // {
    //     // if index is within the range
    //     if (index < sizet)
    //         return arr[index];
    // }
 
    // function to delete last element
    void pop() { sizet--; }
 
    // function to get size of the vector
    int size() { return sizet; }
 
    // function to get capacity of the vector
    int getcapacity() { return capacity; }
 
    // function to print array elements
    void print()
    {
        for (int i = 0; i < sizet; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~Vector(){              //dtor
        delete []arr;
    }
};
 
// Driver code
int main()
{
    Vector<int> v;
    Vector<char> v1;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v1.push_back(71);
    v1.push_back(72);
    v1.push_back(73);
    v1.push_back(74);
 
    cout << "Vector size : " << v.size() << endl;
    cout << "Vector capacity : " << v.getcapacity() << endl;
 
    cout << "Vector elements : ";
    v.print();
 
    v.push(100, 1);
 
    cout << "\nAfter updating 1st index" << endl;
 
    cout << "Vector elements of type int : " << endl;
    v.print();
    // This was possible because we used templates
    cout << "Vector elements of type char : " << endl;
    v1.print();
    // cout << "Element at 1st index of type int: " << v.get(1)
    //      << endl;
    // cout << "Element at 1st index of type char: "
    //      << v1.get(1) << endl;
 
    v.pop();
    v1.pop();
 
    cout << "\nAfter deleting last element" << endl;
 
    cout << "Vector size of type int: " << v.size() << endl;
    cout << "Vector size of type char: " << v1.size()
         << endl;
    cout << "Vector capacity of type int : "
         << v.getcapacity() << endl;
    cout << "Vector capacity of type char : "
         << v1.getcapacity() << endl;
 
    cout << "Vector elements of type int: ";
    v.print();
    cout << "Vector elements of type char: ";
    v1.print();
 
    return 0;
}