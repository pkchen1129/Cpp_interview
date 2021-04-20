// Your previous Plain Text content is preserved below:

// Rate your familiarity with the following concepts and practices, using the following scale:
// (or just leave it blank if you’ve never heard of it)

// 1 I’ve heard of it, but don’t really know much about it.
// 2 I have a beginner-level understanding of this
// 3 I work enough with this enough to talk intelligently about it
// 4 I’ve worked extensively with this, but I’m no expert
// 5 I’m one of the most knowledgeable people I know on this subject



// 4 C/C++
// 3 Matlab
// 3 Python
// 3 OpenCV
// 2 ROS
// 3 Tensorflow / Pytorch
// 3 Maximum likelihood estimation
// 2 Fixed-point / floating-point issues
// 4 Simultaneous localization and mapping
// 4 Image feature detection and tracking
// 4 Rotation matrices / coordinate transforms
// 2 GNSS / GPS
// 4 Camera calibration
// 3 Multi-sensor fusion
// 2 Convex optimization
// 3 Linear programming
// 4 Gauss-newton methods
// 3 Singular value decomposition
// 4 EKF
// 3 Cmake


------------------
Q) Given an i.i.d. standard normal gaussian vector x (zero mean unit variance), generate a random vector y with mean m and covariance matrix Q:

x ~ N(0,I)

y ~ N(m,Q)

[sigma1^2 0
 0        sigma2^2]
 
y = ((sqrt(q)*x) + m)

L = cholesky(Q)
y = L * x + m

Q = L*L^T = [q1^2 0 
             0   q2^2]

covar(L*x) = Q

// A^T * A = R^T * R (upper triangle matrix)


------------------
Q) Given a set of samples of 3D points (X[n], Y[n], Z[n]) (n ranges from 0 to N-1) that lie approximately on a plane, find a plane that they approximately lie on. 
// (bonus: assume that some of the points in this set don’t actually belong to that plane)

1. ax + by + cz = 1

2. (RANSAC) model fitting => 
while () {
  randomly pick 3 points compose a plane
  count the inliers (dis(points vs plane) < epsilon)
  
}

3. least square:
min ||Ax - b||2

A = [px1 py1 1
     px2 py2 1
     .
     .
     .
     .
     pxn pyn 1]

b = [a ,b ,c]^T
y = [pz1 pz2 ..... pzn]^T

min ||Ax - b||2
X = (A^T * A)^{-1} * A^Tb;


p1 = [1 0 0]
p2 = [1 1 0]
p3 = [1 1 1]

X = [a,b,c] = ?

ax + by + cz = 1 !!!


Ans: 
x = 1



// Parameter model:
// Line: 
// t = (5,1)

// p(2, 3)

// line : 2 + 5t, 3 + t



// Plane:
// A = 
// p1 = [1 0 0]
// p2 = [1 1 0]
// p3 = [1 1 1]

// t = (a,b,c)
// plane => 
// 1 + at, bt , ct
// 1 + at, 1 + bt , ct
// 1 + at, 1 + bt , 1 + ct


// Q) How do you average two integers without overflow?

#include <iostream>
using namespace std;

int averageTwoInts(int x, int y) {
  // x = 1,y = 2
  // x = 9999999, y = 99999;
  // x = 234, y = 4567;
  
  to_string();
  // loop change to char
  string s1 = to_string(x);
  string s2 = to_string(y);
  string s3;
  int p1 = s1.size() - 1;
  int p2 = s2.size() - 1;
  int p3 = 0;
  
  while (p1 >= 0 || p2 >= 0) {
    p1
  }
  
  
  int d = (x+y) % 2; // 0 or 1
  int z =  (x+y) / 2;

  return z;
}

// To execute C++, please define "int main()"
int main() {
  cout << averageTwoInts(2,4) << endl;
  cout << averageTwoInts(3,5) << endl;
  cout << averageTwoInts(101,102) << endl;
  cout << averageTwoInts(-3,-5) << endl;
  return 0;
}


Q) Camera Calibration(Camera model, Calibration, P3P, )
Q) Image feature detection and tracking(SIFT, detect the corner)
Q) EKF(tracking, models)
Q) Rotation matrices / coordinate transforms(How to know it is rotation matrices)
Q) SLAM(Know 2d pixel values, know R, t => Get the 3D points)