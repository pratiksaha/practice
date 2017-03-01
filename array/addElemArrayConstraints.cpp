//to add two arrays following given constraints
#include<bits/stdc++.h>
using namespace std;
 
void split(int num, vector<int> *out) {
    vector<int> arr;
    while (num) {
        arr.push_back(num%10);
        num = num/10;
    }
    out->insert(out->end(), arr.rbegin(), arr.rend());
}

void addElemArrayConstraints(int arr1[], int arr2[], int m, int n) {
    vector<int> out;
    int i = 0;
    while (i < m && i < n) {
        int sum = arr1[i] + arr2[i];
        if (sum < 10)
            out.push_back(sum);
        else
            split(sum, &out);
        i++;
    }
    while (i < m)
        split(arr1[i++], &out);
    while (i < n)
        split(arr2[i++], &out);
    for (vector<int>::iterator it = out.begin(); it != out.end(); it++)
        cout<<" "<<*it;
    cout<<endl;
}

int main() {
    int arr1[] = {9343, 2, 3, 7, 9, 6};
    int arr2[] = {34, 11, 4, 7, 8, 7, 6, 99};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    addElemArrayConstraints(arr1, arr2, m, n);
    return 0;
}
