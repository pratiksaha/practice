//to count number of subsets with given GCDs
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<iostream>
#include<unordered_map>
using namespace std;

void countSubsetGCD(int arr[], int n, int gcd[], int m) {
    unordered_map<int, int> freq;
    unordered_map<int, int> subsets;
    int arrMax = 0;
    for (int i=0; i<n; i++) {
        arrMax = max(arrMax, arr[i]);
        freq[arr[i]]++;
    }
    for (int i=arrMax; i>=1; i--) {
        int sub = 0;
        int add = freq[i];
        for (int j=2; j*i<=arrMax; j++) {
            add += freq[j*i];
            sub += subsets[j*i];
        }   
        subsets[i] = (1<<add) - 1 - sub;
    }
    for (int i=0; i<m; i++)
      cout<<"Number of subsets with gcd "<<gcd[i]<<" is "<<subsets[gcd[i]]<<endl;
}

int main() {
    int gcd[] = {2, 3};
    int arr[] = {9, 6, 2};
    countSubsetGCD(arr, sizeof(arr)/sizeof(arr[0]), gcd, sizeof(gcd)/sizeof(gcd[0]));
    return 0;
}
