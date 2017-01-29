//to count all pair with given XOR
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
using namespace std;

int xorPairCount(int arr[], int n, int x) {
    int result = 0;
    unordered_set<int> s;
    for (int i=0; i<n; i++) {
        if (s.find(x^arr[i]) != s.end())
            result++;
        s.insert(arr[i]);
    }
    return result;
}

int main() {
    int arr[] = {5 , 4 ,10, 15, 7, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 5;
    cout<<"Count of pairs with XOR value "<<x<<" is "<<xorPairCount(arr, n, x)<<endl;
    return 0;
}
