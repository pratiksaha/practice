//to check if a given array is cyclic or not under given constraints
#include<bits/stdc++.h>
using namespace std;

bool checkCycleConstraints(int v, vector<int>adj[], vector<bool> &visited, vector<bool> &recur) {
    visited[v] = true;
    recur[v] = true;
    for (int i=0; i<adj[v].size(); i++) {
        if (visited[adj[v][i]] == false) {
            if (checkCycleConstraints(adj[v][i], adj, visited, recur))
                return true;
        } else if (visited[adj[v][i]] == true && recur[adj[v][i]] == true) {
            return true;
        }
    }
    recur[v] = false;
    return false;
}

bool checkCycleConstraints(int arr[], int n) {
    vector<int>adj[n];
    for (int i=0; i<n; i++)
        adj[i].push_back((i+arr[i]+n)%n);
    vector<bool> visited(n, false);
    vector<bool> recur(n, false);
    for (int i=0; i<n; i++)
        if (visited[i]==false)
            if (checkCycleConstraints(i, adj, visited, recur))
                return true;
    return true;
}

int main(void) {
    int arr[] = {2, -1, 1, 2, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    checkCycleConstraints(arr, n) ? cout<<"Yes\n" : cout<<"No\n";
    return 0;
}
