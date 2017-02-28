//to find absolute distinct count of an array
#include<bits/stdc++.h>
using namespace std;

int absoluteDistinctCount(int arr[], int n) {
    int count = n;
    int i = 0, j = n - 1, sum = 0;
    while (i < j) {
        while (i != j && arr[i] == arr[i + 1])
            count--, i++;
        while (i != j && arr[j] == arr[j - 1])
            count--, j--;
        if (i == j)
            break;
        sum = arr[i] + arr[j];
 
        if (sum == 0)
            count--, i++, j--;
        else if(sum < 0)
            i++;
        else
            j--;
    }
    return count;
}
 
int main() {
    int arr[] = {-2, -1, 0, 1, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Count of absolute distinct values is "<<absoluteDistinctCount(arr, n)<<endl;
    return 0;
}
