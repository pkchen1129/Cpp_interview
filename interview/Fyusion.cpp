// What are the problems with this code? How would you fix it?
using namespace std;
#include <iostream>
#include <vector>
class PointXYZ 
{ 
public:
  PointXYZ(double x, double y, double z) : x_(x), y_(y), z_(z) {}
  double x_, y_, z_;
};

class PointXYZRGB : public PointXYZ 
{
  PointXYZRGB(double x, double y, double z, int r, int g, int b) : PointXYZ(x, y, z), r_(r), g_(g), b_(b) {}
  int r_, g_, b_;
};

class PointXYZRGBA : public PointXYZ 
{
  PointXYZRGBA(double x, double y, double z, int r, int g, int b, int a) : PointXYZ(x, y, z), r_(r), g_(g), b_(b), a_(a) {}
    int r_, g_, b_, a_;
};

// Void visualize(________ all_points) {
//  // visualizes
// }

int main() {



    vector<PointXYZ*> all_points;
    PointXYZ* a = new PointXYZ(0,1,2);

    PointXYZRGB b(0, 1, 2, 255, 255, 255);
    all_points.push_back(&a);
    all_points.push_back(&b);


    vector<PointXYZ> all_points;
    all_points.push_back(PointXYZRGB(0, 1, 2, 255, 255, 255));
    all_points.push_back(PointXYZRGB(1, 2, 3, 255, 255, 255));

}











using namespace std;
class Base {
public:
  virtual void print() { cout<<"Base \n"; }
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

output: 

Base
Derived
Derived
Base
