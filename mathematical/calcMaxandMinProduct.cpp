//to find max and min product from an array
#include<bits/stdc++.h>
using namespace std;
 
pair<int, int> calcMaxandMinProduct(int arr[], int n) {
    int curMaxProduct = arr[0];
    int curMinProduct = arr[0];
    int prevMaxProduct = arr[0];
    int prevMinProduct = arr[0];
    int maxProduct = arr[0];
    int minProduct = arr[0];
    for (int i = 1; i < n; i++) {
        curMaxProduct = max(prevMaxProduct * arr[i], max(prevMinProduct * arr[i], arr[i]));
        curMaxProduct = max(curMaxProduct, prevMaxProduct);
        curMinProduct = min(prevMaxProduct * arr[i], min(prevMinProduct * arr[i], arr[i]));
        curMinProduct = min(curMinProduct, prevMinProduct);
        maxProduct = max(maxProduct, curMaxProduct);
        minProduct = min(minProduct, curMinProduct);
        prevMaxProduct = curMaxProduct;
        prevMinProduct = curMinProduct;
    }
    return make_pair(minProduct, maxProduct);
}
int main() {
    int arr[] = {-4, -2, 3, 7, 5, 0, 1};
    int n = sizeof(arr) / sizeof(int);
    pair<int, int> product = calcMaxandMinProduct(arr, n);
    cout<<"Minimum product is "<<product.first<<" and Maximum product is "<<product.second<<endl;
    return 0;
}
