#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
int orOfAllSubarrays(const vector<int>& A) {
    unordered_set<int> orResults; 
    int n = A.size();
    
    for (int i = 0; i < n; i++) {
        int currentOR = 0; 
        for (int j = i; j < n; j++) {
            currentOR |= A[j]; 
            orResults.insert(currentOR); 
        }
    }

    int finalResult = 0;
    for (int val : orResults) {
        finalResult |= val; 
    }

    return finalResult; 
}

int main() {
    vector<int> A1 = {1, 4, 6};
    cout << "Output: " << orOfAllSubarrays(A1) << endl; // Expected Output: 7

    vector<int> A2 = {10, 100, 1000};
    cout << "Output: " << orOfAllSubarrays(A2) << endl; // Expected Output: 1006

    return 0;
}
