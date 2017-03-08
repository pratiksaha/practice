//to count pairs whose product exist in array
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
using namespace std;

int countPairsWithProductExisting(int arr[] , int n) {
    int result = 0;
    unordered_set< int > Hash;
    for (int i = 0 ; i < n; i++)
        Hash.insert(arr[i]);
    for (int i = 0 ; i < n; i++) {
        for (int j = i + 1; j<n ; j++) {
            int product = arr[i]*arr[j];
            if (Hash.find(product) != Hash.end())
                result++;
        }
    }
    return result;
}

int main() {
    int arr[] = {6 ,2 ,4 ,12 ,5 ,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<countPairsWithProductExisting(arr, n)<<endl;
    return 0;
}
