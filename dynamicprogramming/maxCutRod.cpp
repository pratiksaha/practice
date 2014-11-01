// A DP based sol for Rod cutting problem
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int cutRod(int price[], int n) {
    int val[n+1];
    val[0] = 0;
    for (int i=1; i<=n; i++) {
        int max_val = INT_MIN;
        for (int j=0; j < i; j++)
            max_val = max(max_val, price[j] + val[i-j-1]);
        val[i] = max_val;
    }
    return val[n];
}

int main() {
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    cout<<"Maximum Obtainable Value is "<<cutRod(arr, sizeof(arr)/sizeof(arr[0]))<<endl;
    return 0;
}
