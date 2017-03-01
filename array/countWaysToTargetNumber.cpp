//to count the number of ways to calculate a target number using only array elements and addition or subtraction operator
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
using namespace std;
 
int countWaysToTargetNumber(vector<int> arr, int i, int k) {
    if (i >= arr.size() && k != 0)
        return 0;
    if (k == 0)
        return 1;
    return countWaysToTargetNumber(arr, i + 1, k) + countWaysToTargetNumber(arr, i + 1, k - arr[i]) + countWaysToTargetNumber(arr, i + 1, k + arr[i]);
}

int main() {
    vector<int> arr = {-3, 1, 3, 5, 7};
    int k = 6;
    cout<<countWaysToTargetNumber(arr, 0, k)<<endl;
    return 0;
}
