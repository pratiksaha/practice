//to sort an array according to count of set bits
#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n) {
    for (int i=0; i<n; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

int countBits(int a) {
    int count = 0;
    while (a) {
        if (a & 1 )
            count+= 1;
        a = a>>1;
    }
    return count;
}

int cmp(int a,int b) {
    int count1 = countBits(a);
    int count2 = countBits(b);
    if (count1 <= count2)
        return false;
    return true;
}

void sortBySetBitCount(int arr[], int n) {
    stable_sort(arr, arr+n, cmp);
}

void sortBySetBitCountLinear(int arr[],int n) {
    vector<vector<int> > count(32);
    int setbitcount = 0;
    for (int i=0; i<n; i++) {
        setbitcount = countBits(arr[i]);
        count[setbitcount].push_back(arr[i]);
    }
    int j = 0;
    for (int i=31; i>=0; i--) {
        vector<int> v1 = count[i];
        for (int i=0; i<v1.size(); i++)
            arr[j++] = v1[i];
    }
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    sortBySetBitCount(arr1, n1);
    printArray(arr1, n1);
    int arr2[] = {1, 2, 3, 4, 5, 6};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    sortBySetBitCountLinear(arr2, n2);
    printArray(arr2, n2);
    return 0;
}
