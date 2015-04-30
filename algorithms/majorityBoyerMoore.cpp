//Boyer Moore Voting Algorithm to find majority element
#include<iostream>
using namespace std;

int findCandidate(int arr[], int n) {
    int idx = 0, count = 1;
    for (int i=1; i<n; i++) {
        if (arr[idx]==arr[i])
            count++;
        else
            count--;
        if (count==0) {
            idx = i;
            count = 1;
        } 
    }
    return arr[idx];
}

bool isMajority(int arr[], int n, int key) {
    int count = 0;
    for(int i=0; i<n; i++)
        if (arr[i]==key)
            count++;
    if (count > n/2)
        return true;
    else
        return false;
}

void majorityBoyerMoore(int arr[], int n) {
    int key = findCandidate(arr, n);
    if (isMajority(arr, n, key))
        cout<<key<<" is the majority element\n";
    else
        cout<<"No majority element\n";
}

int main() {
    int a[] = {1, 3, 3, 1, 3, 3, 2};
    majorityBoyerMoore(a, sizeof(a)/sizeof(a[0]));
    return 0;
}
