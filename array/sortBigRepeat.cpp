//sort a big array with repeatations
#include<iostream>
#include<map>
using namespace std;

void sortBigRepeat(int arr[], int n) {
    map<int, int> hash;
    for (int i=0; i<n; i++) {
        map<int, int>::iterator it = hash.find(arr[i]);
        if (it == hash.end())
            hash.insert(make_pair(arr[i], 1));
        else
            it->second = it->second + 1;
    }
    int i = 0;
    for (map<int, int>::iterator it=hash.begin(); it!=hash.end(); it++) {
        int val = it->first;
        int cnt = it->second;
        while (cnt--) {
            arr[i] = val;
            i++;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i=0; i<n; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

int main() {
    int arr[] = {100, 12, 100, 1, 1, 12, 100, 1, 12, 100, 1, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Input array is :";
    printArray(arr, n);
    sortBigRepeat(arr, n);
    cout<<"Sorted array is :";
    printArray(arr, n);
    return 0;
}
