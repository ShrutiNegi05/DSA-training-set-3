#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


string numberToText(int n) {
   
    string ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    string tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    
   
    if (n == 100) return "hundred";
    
    if (n < 10) return ones[n];
    if (n >= 10 && n < 20) return teens[n - 10];
    if (n >= 20) {
        return tens[n / 10] + (n % 10 != 0 ? " " + ones[n % 10] : "");
    }
    return "";
}

int countVowels(const string &text) {
    int vowelCount = 0;
    for (char c : text) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowelCount++;
        }
    }
    return vowelCount;
}

int main() {
    int N;
    cin >> N; 
    vector<int> numbers(N);
    
    
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    
   
    int D = 0;
    for (int num : numbers) {
        string text = numberToText(num);  
        D += countVowels(text);  
    }

    unordered_map<int, int> frequencyMap;
    int pairCount = 0;
    
    for (int num : numbers) {
        frequencyMap[num]++;
    }
    

    for (int num : numbers) {
        int complement = D - num;
        
        if (complement >= num) {  
            if (frequencyMap.find(complement) != frequencyMap.end()) {
                if (complement == num) {
                    pairCount += frequencyMap[num] - 1;  
                } else {
                    pairCount += frequencyMap[complement];
                }
            }
        }
    }
    
    pairCount /= 2;
   
    if (pairCount > 100) {
        cout << "greater 100" << endl;
    } else {
        
        string ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", 
                         "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", 
                         "seventeen", "eighteen", "nineteen"};
        string tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
        
        if (pairCount < 20) {
            cout << ones[pairCount] << endl;
        } else {
            cout << tens[pairCount / 10];
            if (pairCount % 10 != 0) {
                cout << " " << ones[pairCount % 10];
            }
            cout << endl;
        }
    }
    
    return 0;
}
