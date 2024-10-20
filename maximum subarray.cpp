#include <iostream>
using namespace std;

void printMaxInSubarrays(int arr[], int n, int K) {
    for (int i = 0; i <= n - K; i++) {
        int maxVal = arr[i];
        for (int j = 1; j < K; j++) {
            if (arr[i + j] > maxVal)
                maxVal = arr[i + j];
        }
        cout << maxVal << " ";
    }
    cout << endl;
}

int main() {
    int arr1[] = {1, 2, 3, 1, 4, 5};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int K1 = 3;
    printMaxInSubarrays(arr1, n1, K1);  

    int arr2[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    int K2 = 4;
    printMaxInSubarrays(arr2, n2, K2);  

    int arr3[] = {20, 10, 30};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    int K3 = 1;
    printMaxInSubarrays(arr3, n3, K3);  

    return 0;
}
