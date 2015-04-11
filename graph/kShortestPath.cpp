//to find shortest path with exactly k edges
#include<iostream>
#include<climits>
using namespace std;
#define V 4

int kShortestPath(int graph[][V], int u, int v, int k) {
    int sp[V][V][k+1]; //sp[i][j][e] = weight of the shortest path from i to j with exactly k edges
    for (int e=0; e<=k; e++) {
        for (int i=0; i<V; i++) {
            for (int j = 0; j < V; j++) {
                sp[i][j][e] = INT_MAX;
                if (e==0 && i==j)
                    sp[i][j][e] = 0;
                if (e==1 && graph[i][j]!=INT_MAX)
                    sp[i][j][e] = graph[i][j];
                if (e > 1)
                    for (int a=0; a<V; a++)
                        if (graph[i][a]!=INT_MAX && i!=a && j!=a && sp[a][j][e-1]!=INT_MAX) //there should be an edge from i to a and a should not be same as either i or j
                            sp[i][j][e] = min(sp[i][j][e], graph[i][a]+sp[a][j][e-1]);
           }
        }
    }
    return sp[u][v][k];
}

int main() {
    int graph[V][V] = { {0, 10, 3, 2},
                        {INT_MAX, 0, INT_MAX, 7},
                        {INT_MAX, INT_MAX, 0, 6},
                        {INT_MAX, INT_MAX, INT_MAX, 0}
                      };
    int u=0, v=3, k=2;
    cout<<"Weight of shortest path from "<<u<<" to "<<v<<" with exactly "<<k<<" edges = "<<kShortestPath(graph, u, v, k)<<endl;
    return 0;
}
