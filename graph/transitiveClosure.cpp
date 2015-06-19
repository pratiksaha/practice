//to find transitive closure of a graph
#include<iostream>
using namespace std;
#define V 4

void printMatrix(int mat[V][V]) {
    for (int i=0; i<V; i++) {
        for (int j=0; j<V; j++) {
            cout<<" "<<mat[i][j];
        }
        cout<<endl;
    }
}


void transitiveClosure(int graph[V][V]) {
    int reach[V][V];
    for (int i=0; i<V; i++)
        for (int j=0; j<V; j++)
            reach[i][j] = graph[i][j];
    for (int k=0; k<V; k++) //pick all vertices as intermediate
        for (int i=0; i<V; i++) //pick all vertices as source
            for (int j=0; j<V; j++) //pick all vertices as destination
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
    cout<<"For the graph :\n";
    printMatrix(graph);
    cout<<"Transitive Closure is :\n";
    printMatrix(reach);
}

int main() {
    int graph[V][V] = { {1, 1, 0, 1},
                        {0, 1, 1, 0},
                        {0, 0, 1, 1},
                        {0, 0, 0, 1}
                      };
    transitiveClosure(graph);
    return 0;
}
