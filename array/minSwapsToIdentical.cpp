//to make an array same to anotherusing minimum number of swaps
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
using namespace std;

int minSwapsToSort(int arr[], int n) {
    pair<int, int> arrPos[n];
    for (int i = 0; i < n; i++) {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }
    sort(arrPos, arrPos + n);
    vector<bool> vis(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i] || arrPos[i].second == i)
            continue;
        int cycle_size = 0;
        int j = i;
        while (!vis[j]) {
            vis[j] = 1;
            j = arrPos[j].second;
            cycle_size++;
        }
        ans += (cycle_size - 1);
    }
    return ans;
}

int minSwapsToIdentical(int a[], int b[], int n) {
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[b[i]] = i;
    for (int i = 0; i < n; i++)
        b[i] = mp[a[i]];
    return minSwapsToSort(b, n);
}

int main() {
    int a[] = {3, 6, 4, 8};
    int b[] = {4, 6, 8, 3};
    int n = sizeof(a) / sizeof(int);
    cout<<minSwapsToIdentical(a, b, n)<<endl;
    return 0;
}
