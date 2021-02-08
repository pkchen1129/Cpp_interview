// Motional
// 2021/1/21
// Motional Onsite: 
// 1. Yimu Wang: 
// Newton Raphson =>  https://www.geeksforgeeks.org/program-for-newton-raphson-method/
// f(x) = x*2 - 1, 要找他的root.
// 沒有答的很好, 提示蠻多的我才做出來
// 有回答出整個邏輯架構跟算法, 只是
// 中間卡蠻久的 基本上算是沒有做出來...

// 2.  Ajay Charan:
// Matrix manipulation and creating a class. 考寫class 基本像是constructor等等
// Implement Matrix transpose. 我用一個最智障的方法去完成它... 但應該算是做出來了


// 3. Chengfeng Wen:
// 考find median. 因為之前有寫過 所以有寫出來,用兩個heap , follow up 問說如果是sliding window該怎麼解, 其實就是把heap 換成兩個set, set 本身就有排序
// 295 有寫出來, 480它也沒叫我寫只是問問我的想法, 算是有回答對一半, 講完他覺得回答的不錯
// LC 295 + 480


// 2021/1/22
// Motional Onsite part2: 
// 4. Ning Xu
// 考很廣的東西從camera model, KF, EKF, PF, backend, reprojection error(沒很確定), 
// Affine transformation of y = Ax+b covariance(推導) Link, Bayesian, polymorphism(pure virtual function)...etc 

// 5. Jeffery Hsu
// 考transformation between different coordinate of the sensors on the car. ex: T cam:radar, T cam:base.... use what kind of data structure to store that. using unordered_map, 直接要寫出整個的code.




#include <iostream>
using namespace std;
#include <string>


// 1. 
class Vehicle {
    std::string id_;
    int mileage_{};
public:
    Vehicle(const std::string id_input, int mileage_input)
      : id_(id_input), mileage_(mileage_input){}
    virtual int GetCapacity() const = 0;
    int GetMileage() const {
        return mileage_;
    }
};


// TODO: Implement a class called Sedan
// add a class data member capacity
// and implement the function GetCapacity()

class Sedan : Vehicle
{ 
public:
  int capacity;
  Sedan(std::string id_input, int mileage_input_, int capacity_input) : id_(id_input), mileage_(mileage_input),capacity(capacity_input) {}
  int GetCapacity() override {
    return capacity;
  }
};

// To execute C++, please define "int main()"
int main() {
  //auto words = { "Hello, ", "World!", "\n" };
  //for (const string& word : words) {
  //  cout << word;
  //}
  Vehicle *v1 = new Sedan("VEH001", 1000, 20);
  std::cout << "Capacity " << v1->GetCapacity() << std::endl;

  return 0;
}

/*
[u,v,1] = 1/Z( K  R [X Y Z 1]^T (3))

K [ fx s  cx
    0  fy cy 
    0  0  1 ]

R = [   R   t 
        0 0 0 1]
        
// x ~ N (mu, Sigma)
// y = Ax + b 
    
 y_mean = A*mu + b 
 Cov[y] = E[(y-y_h)*(y-y_h)^T]
  = E[Ax+b-(Ax_h+b) * (Ax+b-(Ax_h+b))]
  = E[A(x-x_h) * A(x-x_h)T]
  = A E[(x-x_h)*(x-x_h)^T] A^T
  = A Sigma A^T
 y_cov = A*Sigma*A^T 
 
 
 Bayes
 p(x|y) = p(y|x)*p(x) / Sum {p(y|x)*p(x) -- p(y)
 */
