//to find maximum possible value K such that array has atleast K elements that are greatee than or equals to K
#include <bits/stdc++.h>
using namespace std;
 
int maxKAltleastKElemsValueAtleastK(int arr[], int n) {
    vector<int> freq(n+1, 0);
    for (int i = 0; i < n; i++) {
        if (arr[i] < n)
            freq[arr[i]]++;
        else
            freq[n]++;
    }
    int sum = 0;
    for (int i = n; i > 0; i--) {
        sum += freq[i];
        if (sum >= i)
            return i;
    }
}

int main() {
    int arr[] = {1, 2, 3, 8, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<maxKAltleastKElemsValueAtleastK(arr, n)<<endl;
    return 0;
}
