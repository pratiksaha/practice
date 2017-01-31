//to find the minimum distance from a 1 in binary matrix
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

int dist[MAX][MAX];

void nearestOneForZero(int mat[][MAX], int m, int n) {
    int newx[] = {-1, 0, 1, 0};
    int newy[] = {0, -1, 0, 1};
    queue< pair<int,int> > q;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            dist[i][j] = INT_MAX;
            if (mat[i][j] == 1) {
                dist[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    }
    pair<int ,int> poped;
    while (!q.empty()) {
        poped = q.front();
        q.pop();
        int x = poped.first;
        int y = poped.second;
        for (int i=0; i<4; i++) {
            int adjx = x + newx[i];
            int adjy = y + newy[i];
            if (adjx>=0 && adjx<m && adjy>=0 && adjy<n && dist[adjx][adjy] > dist[x][y] + 1) {
                dist[adjx][adjy] = dist[x][y] + 1;
                q.push(make_pair(adjx,adjy));
            }
        }
    }
}
 
int main() {
    int m = 3, n = 4;
    int mat[][MAX] = {
        {0, 0, 0, 1},
        {0, 0, 1, 1},
        {0, 1, 1, 0}
    };
    nearestOneForZero(mat, m, n);
    cout<<"Distance Matrix :\n";
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++)
            cout<<" "<<dist[i][j];
        cout<<endl;
    }
    return 0;
}
