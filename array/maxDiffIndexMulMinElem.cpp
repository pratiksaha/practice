//max value of abs(i - j) * min(arr[i], arr[j]) in array
#include<bits/stdc++.h>
using namespace std;

int maxDiffIndexMulMinElem(int arr[], int n) {
    int maxProduct = INT_MIN;
    int currProduct;
    int Left = 0, right = n-1;
    while (Left < right) {
        if (arr[Left] < arr[right]) {
            currProduct = arr[Left]*(right-Left);
            Left++;
        } else {
            currProduct = arr[right]*(right-Left);
            right--;
        }
        maxProduct = max(maxProduct, currProduct);
    }
    return maxProduct;
}

int main() {
    int arr[] = {8, 1, 9, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxDiffIndexMulMinElem(arr,n)<<endl;
    return 0;
}
