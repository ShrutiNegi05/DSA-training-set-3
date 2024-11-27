#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

int main() {
 
    vector<int> arr = {198, 76, 544, 123, 154, 675};
    int k = 2;

    sort(arr.begin(), arr.end());

    long long product = 1;
    for (int i = 0; i < k; i++) {
        product *= arr[i];
    }

    cout << "Minimum product of " << k << " integers: " << product << endl;

    return 0;
}
