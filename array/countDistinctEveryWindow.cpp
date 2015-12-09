//to count distinct elements in every window of size k
//compile with --std=c+=11
#include<bits/stdc++.h>
using namespace std;

void countDistinctEveryWindow(int a[], int n, int k) {
    unordered_map<int, int> hash;
    unordered_map<int, int>::iterator it;
    int curr = 0;
    int last;
    while(curr<k) {
        it = hash.find(a[curr]);
        if (it==hash.end()) {
            hash.insert(make_pair(a[curr], 1));
        } else {
            it->second++;
        } 
        curr++;
    }
    cout<<hash.size()<<endl;
    while (curr<n) {
        last = curr-k;
        it = hash.find(a[last]);
        assert(it!=hash.end()); //otherwise it is an unexpected error
        if (it->second > 1)
            it->second--;
        else
            hash.erase(it);
        it = hash.find(a[curr]);
        if (it==hash.end()) {
            hash.insert(make_pair(curr, 1));
        } else {
            it->second++;
        }
        cout<<hash.size()<<endl;
        curr++;
    }   
}

int main() {
    int arr[] = {1, 2, 1, 3, 4, 2, 3};
    int k = 4;
    int n = sizeof(arr)/sizeof(arr[0]);
    countDistinctEveryWindow(arr, n, k);
    return 0;
}
