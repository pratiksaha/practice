//max occurred element in all ranges
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000

int maxOccuringNRanges(int L[], int R[], int n) {
    int arr[MAX];
    memset(arr, 0, sizeof arr);
    for (int i = 0; i < n; i++) {
        arr[L[i]] += 1;
        arr[R[i] + 1] -= 1;
    }
    int maxsum = arr[0], index;
    for (int i = 1; i < MAX; i++) {
        arr[i] += arr[i-1];
        if (maxsum < arr[i]) {
            maxsum = arr[i];
            index = i;
        }
    }
    return index;
}

int main() {
    int L[] = { 1, 4, 9, 13, 21 };
    int R[] = { 15, 8, 12, 20, 30 };
    int n = sizeof(L)/sizeof(L[0]);
    cout<<maxOccuringNRanges(L, R, n)<<endl;
    return 0;
}
