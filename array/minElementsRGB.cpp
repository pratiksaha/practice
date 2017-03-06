//to find count of minimum elements after considering all possible transformations
#include<bits/stdc++.h>
using namespace std;

int minElementsRGB(char arr[], int n) {
    int b_count = 0, g_count = 0, r_count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 'B')
            b_count++;
        if (arr[i] == 'G')
            g_count++;
        if (arr[i] == 'R')
            r_count++;
    }
    if (b_count==n || g_count==n || r_count==n)
        return n;
    if ((r_count&1 && g_count&1 && b_count&1) )
        return 2;
    if (!(r_count & 1) && !(g_count & 1) && !(b_count & 1) )
        return 2;
    return 1;
}

int main() {
    char arr[] = {'R', 'G', 'B', 'R'};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<minElementsRGB(arr, n)<<endl;
    return 0;
}
