#include <bits/stdc++.h>
#include <iostream>
#include <string> 
using namespace std;


/*
 * Complete the 'computeLisp' function below.
 *
 * The function is expected to return a FLOAT.
 * The function accepts STRING lisp_expression as parameter.
 */
string getToken(const string& s, int& pos) {        
    string token;
    while (pos < s.length()) {            
        if (s[pos] == ')' || s[pos] == ' ') break;
        token += s[pos++];
    }
    return token;
}

float getValue(const string& symbol, deque<unordered_map<string, float>>& scopes_) {
    for (const auto& scope : scopes_)        
        if (scope.count(symbol)) return scope.at(symbol);
    return 0;
}

float eval(const string& s, int& pos, deque<unordered_map<string, float>>& scopes_) {
    scopes_.push_front(unordered_map<string, float>());
    float value = 0; // The return value of current expr        
    if (s[pos] == '(') ++pos;

    // command, variable or number
    string token = getToken(s, pos);

    if (token == "+") {
        float v1 = eval(s, ++pos,scopes_);
        float v2 = eval(s, ++pos,scopes_);
        value = v1 + v2;
    } 
    else if (token == "*") {
        float v1 = eval(s, ++pos,scopes_);
        float v2 = eval(s, ++pos,scopes_);
        value = v1 * v2;
    } 
    else if (token == "-") {
        float v1 = eval(s, ++pos,scopes_);
        float v2 = eval(s, ++pos,scopes_);
        value = v1 - v2;
    } 
    else if (token == "/") {
        float v1 = eval(s, ++pos,scopes_);
        float v2 = eval(s, ++pos,scopes_);
        value = v1 / v2;
    }
    else {            
        value = (float)stoi(token); // number
    }
    if (s[pos] == ')') ++pos;        
    scopes_.pop_front();  
    return value;
}

float computeLisp(const string lisp_expression) {
    deque<unordered_map<string, float>> scopes_; 
    scopes_.clear();
    int pos = 0;
    return eval(lisp_expression, pos, scopes_);
}




int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string lisp_expression;
    getline(cin, lisp_expression);

    float result = computeLisp(lisp_expression);

    fout << result << "\n";

    fout.close();

    return 0;
}





