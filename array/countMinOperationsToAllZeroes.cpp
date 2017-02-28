//to count minimum number of operations to get all zeroes
#include<bits/stdc++.h>
using namespace std;

int countMinOperationsToAllZeroes(int target[], int n) {
    int result = 0;
    while (1) {
        int zero_count = 0;
        int i;
        for (i=0; i<n; i++) {
            if (target[i] & 1)
                break;
            else if (target[i] == 0)
                zero_count++;
        }
        if (zero_count == n)
            return result;
        if (i == n) {
            for (int j=0; j<n; j++)
                target[j] = target[j]/2;
            result++;
        }
        for (int j=i; j<n; j++) {
            if (target[j] & 1) {
                target[j]--;
                result++;
           }
        }
    }
}

int main() {
    int arr[] = {16, 16, 16};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Minimum number of steps required to get the given target array of all zeroes is "<<countMinOperationsToAllZeroes(arr, n)<<endl;
    return 0;
}
