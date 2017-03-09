//to find longest prefix with equal numbers of X and Y
#include<bits/stdc++.h>
using namespace std;

int longestPrefixEqualXY(int arr[], int X, int Y, int n) {
    int nx = 0,ny = 0;
    int result = -1;
    for (int i=0; i<n; i++) {
        if (arr[i]==X)
            nx++;
        if (arr[i]==Y)
            ny++;
        if ((nx==ny) && (nx!=0 && ny!=0))
            result = i;
    }
    return result;
}

int main() {
    int arr[] = {7, 42, 5, 6, 42, 8, 7, 5, 3, 6, 7};
    int X = 7, Y = 42;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Ending index of longest prefix with equal nos of "<<X<<" & "<<Y<<" is "<<longestPrefixEqualXY(arr, X, Y, n)<<endl;
    return 0;
}
