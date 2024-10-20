#include <iostream>
#include <string>
using namespace std;

bool checkValidString(string s) {
    int low = 0;  
    int high = 0; 

    for (char c : s) {
        if (c == '(') {
            low++; 
            high++;
        } else if (c == ')') {
            if (low > 0) low--; 
            high--; 
        } else { 
            if (low > 0) low--; 
            high++; 
        }
        if (high < 0) return false;
    }
    return low == 0;
}

int main() {
    string s1 = "()";
    cout << checkValidString(s1) << endl;  

    string s2 = "(())";
    cout << checkValidString(s2) << endl;  

    string s3 = ")(";
    cout << checkValidString(s3) << endl;  

    string s4 = "()*";
    cout << checkValidString(s4) << endl; 

    string s5 = "(*))";
    cout << checkValidString(s5) << endl; 

    return 0;
}
