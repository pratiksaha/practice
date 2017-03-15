//to find the max sum path ending with each position x such that all path step positions divide x
#include<bits/stdc++.h>
using namespace std;
 
void maxSumpathUnderDivisbility(int arr[], int n) {
    int dp[n];
    memset(dp, 0, sizeof dp);
    for (int i=0; i<n; i++) {
        dp[i] = arr[i];
        int maxi = 0;
        for (int j=1; j<=sqrt(i+1); j++) {
            if (((i + 1)%j == 0) && (i + 1) != j) {
                if (dp[j-1] > maxi)
                    maxi = dp[j-1];
                if (dp[(i+1)/j - 1] > maxi && j != 1)
                    maxi = dp[(i+1)/j - 1];
            }
        }
        dp[i] += maxi;
    }
    for (int i = 0; i < n; i++)
        cout<<" "<<dp[i];
    cout<<endl;
}

int main() {
    int arr[] = { 2, 3, 1, 4, 6, 5 };
    int n = sizeof(arr)/sizeof(arr[0]);
    maxSumpathUnderDivisbility(arr, n);
    return 0;
}
