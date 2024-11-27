#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValid(string s) {
    stack<char> stk; 
    unordered_map<char, char> matching_bracket = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };
    
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
           
            stk.push(c);
        } else {
            
            if (stk.empty() || stk.top() != matching_bracket[c]) {
                return false; 
            }
            stk.pop(); 
        }
    }
    
    
    return stk.empty();
}

int main() {
    // Test cases
    cout << isValid("()") << endl;        
    cout << isValid("()[]{}") << endl;    
    cout << isValid("(]") << endl;        
    cout << isValid("([])") << endl;     
    cout << isValid("{[()]}") << endl;    
    cout << isValid("([)]") << endl;     

    return 0;
}
