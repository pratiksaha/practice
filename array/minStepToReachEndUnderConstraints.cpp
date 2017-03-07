//to find minimum jumps to reach end of array
#include<bits/stdc++.h>
using namespace std;

int minStepToReachEndUnderConstraints(int arr[], int N) {
    bool visit[N];
    int distance[N];
    vector<int> digit[10];
    memset(visit, false, sizeof(visit));
    for (int i = 1; i < N; i++)
        digit[arr[i]].push_back(i);
    distance[0] = 0;
    visit[0] = true;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int idx = q.front();
        q.pop();
        if (idx == N-1)
            break;
        int d = arr[idx];
        for (int i = 0; i<digit[d].size(); i++) {
            int nextidx = digit[d][i];
            if (!visit[nextidx]) {
                visit[nextidx] = true;
                q.push(nextidx);
                distance[nextidx] = distance[idx] + 1;
            }
        }
        digit[d].clear();
        if (idx-1 >= 0 && !visit[idx - 1]) {
            visit[idx - 1] = true;
            q.push(idx - 1);
            distance[idx - 1] = distance[idx] + 1;
        }
        if (idx + 1 < N && !visit[idx + 1]) {
            visit[idx + 1] = true;
            q.push(idx + 1);
            distance[idx + 1] = distance[idx] + 1;
        }
    }
    return distance[N - 1];
}

int main() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 5, 4, 3, 6, 0, 1, 2, 3, 4, 5, 7};
    int n = sizeof(arr) / sizeof(int);
    cout<<minStepToReachEndUnderConstraints(arr, n)<<endl;
    return 0;
}
