//to find longest common subarray of two binary arrays with same sum
#include<bits/stdc++.h>
using namespace std;

int longestSpanSameSum(bool arr1[], bool arr2[], int n) {
    int maxlen = 0, presum1 = 0, presum2 = 0;
    int aux[2*n+1];
    memset(aux, -1, sizeof(aux));
    for (int i=0; i<n; i++) {
        presum1 += arr1[i];
        presum2 += arr2[i];
        int currdiff = presum1 - presum2;
        int diffindex = n + currdiff;
        if (currdiff == 0) {
            maxlen = i+1;
        } else if ( aux[diffindex] == -1) {
            aux[diffindex] = i;
        } else {
            int currlen = i - aux[diffindex];
            if (currlen > maxlen)
                maxlen = currlen;
        }
    }
    return maxlen;
}

int main() {
    bool arr1[] = {0, 1, 0, 1, 1, 1, 1};
    bool arr2[] = {1, 1, 1, 1, 1, 0, 1};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    cout<<"Length of the longest common span with same sum is "<<longestSpanSameSum(arr1, arr2, n)<<endl;
    return 0;
}
