/**

**/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <string>
#include <queue>
using namespace std;

int string_operate( string& str1,  string& str2 ){
    queue<char> q;
    int ans = 1;
    for (auto& c : str2) q.push(c);
    int i = 0;
    while(!q.empty()){
        if( i >= str1.size() ){
            i = 0;
            ans++;
        } 
        if(q.front() == str1[i]) q.pop();
        i++;
    }
    return ans;
    
}

int main(){

    string str1 = "ABCD";
    string str2 = "CADA";

    int out = string_operate(str1,str2);
    cout << out;
    return 0;
}
