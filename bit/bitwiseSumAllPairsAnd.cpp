//to compute sum of bitwise AND of all pairs
#include<bits/stdc++.h>
using namespace std;

int bitwiseSumAllPairsAnd(int arr[], int n) {
    int ans = 0;
    for (int i=0; i<32; i++) {
        int k = 0;
        for (int j=0; j<n; j++)
            if ((arr[j]&(1<<i)))
                k++;
        ans += (1<<i)*(k*(k-1)/2);
    }
    return ans;
}

int main() {
    int arr[] = {5, 10, 15};
    cout<<"Bitwise sum of AND of all pairs is "<<bitwiseSumAllPairsAnd(arr, sizeof(arr)/sizeof(arr[0]))<<endl;
    return 0;
}
