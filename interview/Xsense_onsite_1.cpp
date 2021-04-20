1. Ask if 50 white balls and 50 black balls, two empty jars, how to distribute that so that the probability of getting white ball is maximize.

2. C++ questions

3. 

Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.




Example 1:
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.

#include <iostream>
#include <vector>

void divide (vector<int>& input) {
  int sum1 = 0, sum2 = accumulate(input.begin(), input.end(), 0);
  return recurssive(input, sum1, sum2);
}

bool recurssive (vector<int>& input, int& sum1, int& sum2) {
  if (sum1 == sum2) return true; // we want
  if (sum2 == 0) return false; // End
  for (int i = 0 ; i < input.size() ; ++i) {
    recurssive(input, sum + input[i], sum2 - input[i]);
  }
  return false;
}
