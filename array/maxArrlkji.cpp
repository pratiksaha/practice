//to find maximum value of arr[l] - arr[k] + arr[j] - arr[i] and i < j < k < l
#include <bits/stdc++.h>
using namespace std;

int maxArrlkji(int arr[], int n) {
    if (n < 4)
        return INT_MIN;
    int table1[n + 1], table2[n], table3[n - 1], table4[n - 2];
    for (int i=0; i<=n; i++)
        table1[i] = table2[i] = table3[i] = table4[i] =  INT_MIN;
    for (int i = n - 1; i >= 0; i--)
        table1[i] = max(table1[i + 1], arr[i]);
    for (int i = n - 2; i >= 0; i--)
        table2[i] = max(table2[i + 1], table1[i + 1] - arr[i]);
    for (int i = n - 3; i >= 0; i--)
        table3[i] = max(table3[i + 1], table2[i + 1] + arr[i]);
    for (int i = n - 4; i >= 0; i--)
        table4[i] = max(table4[i + 1], table3[i + 1] - arr[i]);
    return table4[0];
}
 
int main() {
    int arr[] = { 4, 8, 9, 2, 20 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<maxArrlkji(arr, n)<<endl;
    return 0;
}
