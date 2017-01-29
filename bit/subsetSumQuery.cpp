//to answer subset sum queries
#include<bits/stdc++.h>
using namespace std;
# define MAXSUM 10000

void preProcess(bitset<MAXSUM> &bit, int arr[], int n) {
    bit.reset();
    bit[0] = 1;
    for (int i=0; i<n; i++)
        bit |= (bit << arr[i]);
}
 
void subsetSumQuery(int query[], int nq, bitset<MAXSUM> bit) {
    for (int i=0; i<nq; i++) {
        int x = query[i];
        if (x >= MAXSUM) {
            cout<<x<<" => NA\n";
            continue;
        }
        cout<<x<<" => "<<(bit[x] ? "Yes" : "No")<<endl;
    }
}
int main() {
    int arr[] = {3, 1, 5};
    int query[] = {8, 7};
    int n  = sizeof(arr) / sizeof(arr[0]);
    int nq = sizeof(query) / sizeof(query[0]);
    bitset<MAXSUM> bit;
    preProcess(bit, arr, n);
    subsetSumQuery(query, nq,  bit);
    return 0;
}
