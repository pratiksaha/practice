//to count number of occurrences of each element in the array in less than O(n) time where all elements are less than M
#include<bits/stdc++.h>
using namespace std;
 
void findFrequencyRangeTillM(int arr[], int low, int high, vector<int>& freq) {
    if (arr[low] == arr[high])  {
        freq[arr[low]] += high - low + 1;
    } else {
        int mid = (low + high) / 2;
        findFrequencyRangeTillM(arr, low, mid, freq);
        findFrequencyRangeTillM(arr, mid + 1, high, freq);
    }
}

void findFrequencyRangeTillM(int arr[], int n) {
    vector<int> freq(arr[n - 1] + 1, 0);
    findFrequencyRangeTillM(arr, 0, n - 1, freq);
    for (int i = 0; i <= arr[n - 1]; i++)
        if (freq[i] != 0)
            cout<<"Element "<<i<<" occurs "<<freq[i]<<" times\n";
}
 
int main() {
    int arr[] = { 1, 1, 1, 2, 3, 3, 5, 5, 8, 8, 8, 9, 9, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
    findFrequencyRangeTillM(arr, n);
    return 0;
}
