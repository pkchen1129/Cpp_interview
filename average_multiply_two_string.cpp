
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
// Average for two points
int averageTwoInt (int a, int b) {
    // Overflow problem
    int x = a / 2;
    int y = b / 2;
    int residual = ((a % 2) + (b % 2)) / 2;
    return x + y + residual;
}

// Just for multiple
string multipleTwoNum (string a, string b) {
    bool negative = false;
    // -+ or +-
    if ((a[0] == '-' && b[0] != '-') || (a[0] != '-' && b[0] == '-') ) {
        negative = true;
    }
    a = a[0] == '-' ? a.substr(1) : a;
    b = b[0] == '-' ? b.substr(1) : b;
    int m = a.size();
    int n = b.size();
    string ans(m + n, '0');
    for (int i = m - 1 ; i >= 0 ; --i) {
        for (int j = n - 1 ; j >= 0 ; --j) {
            int sum = (a[i] - '0') * (b[j] - '0') + (ans[i + j + 1] - '0');
            ans[i + j + 1] = (sum % 10) + '0';
            ans[i + j] += (sum / 10);
        }
    }
   for(int i = 0; i < m + n; i++){
      if(ans[i] !='0') {
          return negative ? ('-' + ans.substr(i)) : ans.substr(i);
      }
   }
   return "0";
}







// Follow up for minus
int compareNums(string num1, string num2) {
    int len1 = num1.size(), len2 = num2.size();
    if (len1 < len2) return -1;
    else if (len1 > len2) return 1;
    else { // (len1 == len2) 
        // compare first char
        if (len1 == 0) return 0;
        else if (num1[0] < num2[0]) return -1;
        else if (num1[0] > num2[0]) return 1;
        else return compareNums(num1.substr(1), num2.substr(1));
    }
}
// Follow up for minus
int minusTwoNum (string a, string b) {
    // make sure a > b > 0
    string ans;
    int carry = 0;
    int p1 = a.size() - 1;
    int p2 = b.size() - 1;
    while (p1 >= 0 || p2 >= 0 || carry == 1) {
        int x = p1 < 0 ? 0 : a[p1] - '0';
        int y = p2 < 0 ? 0 : b[p2] - '0';
        int digitans = x - y - carry;
        if (digitans < 0) {
            carry = 1;
            digitans += 10;
        } else {
            carry = 0;
        }
        ans += digitans;
        p1--;
        p2--;
    }
    return stoi(ans);
}
// for pure positive adding two nums
int addingTwoNum (string a, string b) {
    int p1 = a.size() - 1;
    int p2 = b.size() - 1;
    string ans = "";
    int carry = 0;
    while (p1 >= 0 || p2 >= 0) {
        int num1 = p1 < 0 ? 0 : a[p1] - '0';
        int num2 = p2 < 0 ? 0 : b[p2] - '0';
        int sum = num1 + num2 + carry;
        carry = sum / 10;
        ans += (sum % 10) + '0';
        p1--;
        p2--;
    }
    reverse(ans.begin(), ans.end());
    int output = stoi(ans);
    return output;
}
int dealWithNegative(string a, string b) {
    if (a[0] == '-' && b[0] == '-') {
        return (-1) * addingTwoNum(a.substr(1), b.substr(1));
    }
    else if (a[0] != '-' && b[0] != '-') {
        return addingTwoNum(a, b);
    }
    else if (a[0] == '-') {
        string temp = a; 
        a = b;
        b = temp;
    }
    b = b.substr(1);
    int compareAns = compareNums(a, b);
    if (compareAns == 0) return 0;
    else if (compareAns == 1) return minusTwoNum(a, b);
    else return  (-1)* minusTwoNum(b, a);
}


int main() {
    string a = "-1234";
    string b = "-5";
    
    
    cout << addingTwoNum(a,b) << endl; 
    cout << multipleTwoNum(a,b) << endl;
    cout << dealWithNegative(a,b) << endl;
}


// Work for positive and negative Sum and minus!!!!!
class Solution {
public:
string addStrings(string num1, string num2) {
    bool neg1 = num1[0] == '-';
    bool neg2 = num2[0] == '-';
    if (neg1) num1 = num1.substr(1);
    if (neg2) num2 = num2.substr(1);
    if (neg1 && neg2) {
        return "-" + Sum(num1, num2, true);
    } else if (!neg1 && !neg2) {
        return Sum(num1, num2, true);
    }
    int m = num1.size(), n = num2.size();
    if (m < n || (m == n && num1[0] < num2[0])) {
        string sum = Sum(num2, num1, false);
        return neg1 ? sum : "-" + sum;
    }
    return Sum(num1, num2, false);
}
private:
string Sum(string num1, string num2, bool plus) {
    int m = num1.size(), n = num2.size();
    int i = m - 1, j = n - 1;
    int c = 0;
    string result;
    while (i >= 0 || j >= 0) {
        int a = i >= 0 ? num1[i--] - '0' : 0;
        int b = j >= 0 ? num2[j--] - '0' : 0;
        int sum = plus ? a + b + c : a - b + c;
        if (sum < 0) c = -1, sum += 10;
        else if (sum >= 10) c = 1, sum -= 10;
        else c = 0;
        result.push_back('0' + sum);
    }
    if (c > 0) result.push_back('0' + c);
    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }
    reverse(result.begin(), result.end());
    return result;
}
};