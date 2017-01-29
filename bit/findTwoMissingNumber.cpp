//to find two Missing Numbers
#include <bits/stdc++.h>
using namespace std;

void findTwoMissingNumber(int arr[], int n) {
    vector<bool> mark(n+1, false);
    for (int i = 0; i < n-2; i++)
        mark[arr[i]] = true;
    cout<<"Two Missing Nos are :";
    for (int i=1; i<=n; i++)
        if (! mark[i])
            cout<<" "<<i;
    cout<<endl;
}

void findTwoMissingNumbersXOR(int arr[], int n) {
    int XOR = arr[0];
    for (int i = 1; i < n-2; i++)
        XOR ^= arr[i];
    for (int i = 1; i <= n; i++)
        XOR ^= i;
    int set_bit_no = XOR & ~(XOR-1);
    int x = 0, y = 0;
    for (int i=0; i<n-2; i++) {
        if (arr[i] & set_bit_no)
            x = x ^ arr[i];
        else
            y = y ^ arr[i];
    }
    for (int i=1; i<=n; i++) {
        if (i & set_bit_no)
            x = x ^ i;
        else
            y = y ^ i;
    }
    cout<<"Two Missing Nos are : "<<x<<" & "<<y<<endl;
}

int main() {
    int arr[] = {1, 3, 5, 6};
    int n = 2 + sizeof(arr)/sizeof(arr[0]);
    findTwoMissingNumber(arr, n);
    findTwoMissingNumbersXOR(arr, n);
    return 0;
}
