//count of setuplets from an array that satisfy an equation
#include<bits/stdc++.h>
using namespace std;

int countSextupletSolutions(int arr[], int n) {
    int index = 0;
    int RHS[n*n*n + 1];
    for (int i = 0; i < n; i++)
        if (arr[i])
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    RHS[index++] = arr[i] * (arr[j] + arr[k]);
    sort(RHS, RHS + n);
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                int val = arr[i] * arr[j] + arr[k];
                result += (upper_bound(RHS, RHS + index, val) - lower_bound(RHS, RHS + index, val));
            }
        }
    }
    return result;
}

int main() {
    int arr[] = {2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<countSextupletSolutions(arr, n)<<endl;
    return 0;
}
