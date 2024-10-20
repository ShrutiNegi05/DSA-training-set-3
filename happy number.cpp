#include <iostream>
#include <unordered_set>

using namespace std;

int sumOfSquares(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10; 
        sum += digit * digit; 
        n /= 10; 
    }
    return sum;
}

bool isHappy(int n) {
    unordered_set<int> seen; 
    while (n != 1 && seen.find(n) == seen.end()) {
        seen.insert(n); 
        n = sumOfSquares(n); 
    }
    return n == 1;
}

int main() {
    int n1 = 19; 
    int n2 = 2;  

    cout << "Is " << n1 << " a happy number? " << (isHappy(n1) ? "true" : "false") << endl; // Output: true
    cout << "Is " << n2 << " a happy number? " << (isHappy(n2) ? "true" : "false") << endl; // Output: false

    return 0;
}
