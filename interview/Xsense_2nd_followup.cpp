/*
 * How do you average two integers without overflow?
*/
#include <iostream>
#include <algorithm>
using namespace std;

int averageTwoInts(int x, int y) {
    int a = x / 2;
    int b = y / 2;
    int residual = (x % 2 + y % 2) / 2; // Summing up the remainder then divide by 2
    return  a + b + residual;
}

// To execute C++, please define "int main()"
int main() {
  cout << averageTwoInts(2,4) << endl;
  cout << averageTwoInts(3,5) << endl;
  cout << averageTwoInts(101,102) << endl;
  cout << averageTwoInts(-3,-5) << endl;
  cout << averageTwoInts(INT_MAX, INT_MAX) << endl;
  return 0;
}



/*
 * How to know it is rotation matrices
*/

1. The matrix is Orthogonal. R*R^T = R^T * R = I
2. det(R) = 1


/*
 * Corner Detection
*/
To detect the corner, we can use second moment matrix to know whether it is flat, edge, or corners. 
M = [Sigma Ix*Ix  Sigma IxIy
     Sigma IxIy   Sigma IyIy ];
  = R^{-1} [lambda1  0 
            0        lambda2];

If (lambda2 >> lambda1) || (lambda1 >> lambda2) then it is Edge. 
If lambda2 ~= lambda1 and are big, then it is Corner.
If lambda2 ~= lambda1 and are small, then it is flat region.


/*
 * SLAM problem
*/
If having the piexel values and the Camera Pose, We can first gain the homography matrix.
H = K*[r1, r2, t];
p = [x y 1] // The pixel value
projection = H * p;
Norm of the projection  = projection / p(z)