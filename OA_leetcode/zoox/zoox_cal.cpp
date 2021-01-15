#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s;
    cin >> s;
  
    stack<int> st;
    char operator_ = '+';
    long num = 0, ans = 0;
    for (int i = 0 ; i < s.size() ; ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + s[i] - '0';
        }
        // Operator && last digit
        if (s[i] < '0' || i == s.size() - 1) {
            if (operator_ == '+') {
                st.push(num);
            }
            if (operator_ == '*') {
                int tmp = st.top() * num;
                st.pop();
                st.push(tmp);                    
            }
            operator_ = s[i];
            num = 0;
        }
    }
    while (!st.empty()) {
      ans += st.top();
      st.pop();
    }
    cout<<ans;
    return 0;
}