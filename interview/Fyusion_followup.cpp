using namespace std;
#include <iostream>
#include <vector>
class Base {
public:
  void print() { cout<<"Base \n"; }
};
class Derived: public Base {
public:
  void print() { cout<<"Derived \n"; }
};
int main(void) {
  Base* bp1(new Base());
  bp1->print();
  Base* bp2(new Derived());
  bp2->print();
  Derived* dp1(new Derived());
  dp1->print();
  Derived* dp2(new Base());
  dp2->print();
  return 0;
}

/*
 *    It would print:
 *    Base
 *    Base
 *    Derived
 *    N/A
 *
 *    1, 3, 4. The reason is that a base pointer could points to derived and base memory. However, Derived pointer could only point to derived. 
 *    This explin the first, third and the last case. And it'll call the function of their class.
 *
 *    2. Base* bp2(new Derived());
 *    As for the second one, the reason it's showing "Base" is that there's no virtual in front of : "virtual" void print() { cout<<"Base \n"; }
 *    If adding virtual, then we can call the derived class's void print(); Also we can then add override: void print() "override" { cout<<"Derived \n"; }
 *
 *    Also if there's members declared only at the derived class, it won't be called because of slicing. 
 *    Slicing means that if derived is assigned to a base object, the variables of derived might disappear.
 *    
 */








using namespace std;
class PointXYZ
{
public:
    PointXYZ () {}
    PointXYZ (int x, int y, int z) : _x(x), _y(y), _z(z) {}
    int _x, _y, _z;
    virtual void display(){
        cout << _x << endl;
    }
};

class PointXYZRGBD : public PointXYZ
{
public:
    PointXYZRGBD () {}
    PointXYZRGBD(int x, int y, double z, int r, int g, int b) : PointXYZ(x, y, z), r_(r), g_(g), b_(b) {}
    int g_, r_, b_;
    void display(){
        cout << g_ << endl;
    }
};

//  Add the "&" or "*", so that when passing the derived class in, it could also be passed by reference, pointers, slicing won't happen.
void visualization (PointXYZ& a) {
    a.display();
}
void visualization_p (PointXYZ* a) {
    a->display();
}


int main() {
    // 1. Demonstrate slicing
    PointXYZ b(1,2,3);
    PointXYZRGBD d(4,5,6,255 ,255 ,255);
    b = d;    // Object Slicing,   g_, r_, b_ of d are sliced off 
    visualization(b); // Yes!! run PointXYZ::display();
    visualization(d); // Yes!! run PointXYZRGBD::display(); since there's virtual
    // Result: 
    // 1 
    // 255 (If not pass by reference, this would be 4)
    



    // 2. Check what kind of data type should be placed in vector
    // If putting pointer PointXYZ* ...
    vector<PointXYZ*> all_points;
    PointXYZ *pb = new PointXYZ(1,2,3);
    PointXYZRGBD *pd = new PointXYZRGBD(4,5,6,255 ,255 ,255);
    all_points.push_back(pb);
    all_points.push_back(pd);
    all_points[0] -> display();
    all_points[1] -> display(); // At this situation, we're able to call the derived PointXYZRGBD's additional variables such as g_;
    cout << sizeof(all_points[0]); // 8
    // Result : 
    // 1
    // 255
    // 8

    
    // 3. If putting PointXYZ ...
    vector<PointXYZ> all_points_obj;
    PointXYZ b(1,2,3);
    PointXYZRGBD d(4,5,6,255 ,255 ,255);
    all_points_obj.push_back(b);
    all_points_obj.push_back(d);
    all_points_obj[0].display();
    all_points_obj[1].display(); // At this situation, we're not able to call the derived PointXYZRGBD's additional variables such as g_ because of slicing.
    cout << sizeof(all_points[0]); // 24
    // Result
    // 1
    // 4
    // 24
    
}

