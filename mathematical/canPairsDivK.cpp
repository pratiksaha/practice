//to check if an array can be divided in pairs such that every pair is divisible by k
//Using features of C++ Standard (2011) Compile using g++ -std=c++1
#include<iostream>
#include<unordered_map>
using namespace std;

bool canPairsDivK(int arr[], int n, int k) {
    if (n&1)
        return false;
    unordered_map<int, int> freq;
    for (int i=0; i<n; i++)
        freq[arr[i] % k]++;
    for (int i=0; i<n; i++) {
        int rem = arr[i] % k;
        if  (2*rem == k)
            if (freq[rem] % 2 != 0)
                return false;
        else if (freq[rem] != freq[k - rem])
            return false;
    }
    return true;
}
int main() {
    int arr[] = {92, 75, 65, 48, 45, 35};
    int k = 10;
    canPairsDivK(arr, sizeof(arr)/sizeof(arr[0]), k)?cout<<"True\n":cout<<"False\n";
    return 0;
}
