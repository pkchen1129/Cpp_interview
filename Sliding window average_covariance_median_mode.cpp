// Sliding window getting the last k average
#include <iostream>
#include <queue>
using namespace std;

// Moving average
class Solution
{
private:
    int size;
    double sum;
    queue<int> q;
public:
    Solution (int k) {
        this->size = k;
        sum = 0;
    }
    double get (int input) {
        if (q.size() >= size) {
            sum -= q.front(); q.pop();
        }
        q.push(input);
        sum += input;
        return sum / q.size();
        
    }
};

// Moving variance
class Solution
{
private:
    int size;
    double sum;
    double average;
    double variance;
    queue<int> q;
public:
    Solution (int k) {
        this->size = k;
        sum = 0;
        average = 0;
    }
    void update (int input) {
        double oldavg = average;
        int old = 0;
        if (q.size() >= size) {
            sum -= q.front(); q.pop();
            old = q.front();;
        }
        q.push(input);
        sum += input;
        average = sum / q.size();
        variance += (input-old)*(input-average+old-oldavg)/(size-1);
    }
};

// Sliding window median https://www.cnblogs.com/grandyang/p/6620334.html
// Sliding window maximum https://leetcode.com/submissions/detail/375975051/

int main() {
    
}