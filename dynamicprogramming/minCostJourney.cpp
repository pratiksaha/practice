//to find min cost to reach station N-1 from station 0.
#include<iostream>
#include<climits>
#include<stack>
using namespace std;

#define N 4

void minCostJourney(int cost[N][N]) {
    int i, j, dist[N]; //dist[i] = min cost to reach station i from station 0
    for (i=0; i<N; i++)
       dist[i] = INT_MAX;
    dist[0] = 0;
    for (i=0; i<N; i++)
        for (j=i+1; j<N; j++)
            if (dist[j] > dist[i] + cost[i][j])
                dist[j] = dist[i] + cost[i][j];
    int mincost = dist[N-1];
    cout<<"Min Cost = "<<mincost<<" Path :";
    j = N-1;
    stack<int> path;
    path.push(j);
    while (j>0 && mincost>0) {
        int curr_min = cost[0][j];
        int idx = 0;
        for (i=1; i<j; i++) {
            if (cost[i][j] < curr_min) {
                curr_min = cost[i][j];
                idx = i;
            }
        }
        path.push(idx);
        mincost = mincost - curr_min;
        j = idx;
    }
    while (!path.empty()) {
        cout<<" "<<path.top();
        path.pop();
    }
    cout<<endl;
}

int main() {
    int cost[N][N] = {  {0, 15, 80, 90},
                        {INT_MAX, 0, 40, 50},
                        {INT_MAX, INT_MAX, 0, 70},
                        {INT_MAX, INT_MAX, INT_MAX, 0}
                    };
    minCostJourney(cost);
    return 0;
}
