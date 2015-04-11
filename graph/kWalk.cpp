//to count walks from u to v with exactly k edges
#include <iostream>
using namespace std;
#define V 4

int kWalk(int graph[][V], int u, int v, int k){
    int count[V][V][k+1]; //count[i][j][e] = count of possible walks from i to j with exactly k edges
    for (int e=0; e<=k; e++) {
        for (int i=0; i<V; i++) {
            for (int j=0; j<V; j++) {
                count[i][j][e] = 0;
                if ((e==0 && i==j) || (e==1 && graph[i][j]))
                    count[i][j][e] = 1;
                if (e>1)
                    for (int a=0; a<V; a++)
                        if (graph[i][a])
                            count[i][j][e] += count[a][j][e-1];
           }
        }
    }
    return count[u][v][k];
}

int main() {
    int graph[V][V] = { {0, 1, 1, 1},
                        {0, 0, 0, 1},
                        {0, 0, 0, 1},
                        {0, 0, 0, 0}
                      };
    int u = 0, v = 3, k = 2;
    cout<<"Possible paths from "<<u<<" to "<<v<<" with exactly "<<k<<" edges = "<<kWalk(graph, u, v, k)<<endl;
    return 0;
}
