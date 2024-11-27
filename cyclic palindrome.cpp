#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string &str) {
    int left = 0, right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}


int minCyclicShiftsToPalindrome(const string &s) {
    int n = s.length();
   
    for (int i = 0; i < n; ++i) {
        string shifted = s.substr(i) + s.substr(0, i); 
        if (isPalindrome(shifted)) {
            return i; 
        }
    }
    
    return -1; 
}

int main() {
    int T;
    cin >> T;  
    while (T--) {
        string s;
        cin >> s;  
        int result = minCyclicShiftsToPalindrome(s);
        cout << result << endl;
    }
    return 0;
}
