//vertex cover problem
#include<iostream>
#include<list>
#include<cstring>
using namespace std;

class Graph {
private:
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    void vertexCover();
};
 
Graph:: Graph(int vertices) {
    V = vertices;
    adj = new list<int>[V];
}
 
void Graph:: addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph:: vertexCover() {
    bool visited[V];
    memset(visited, false, V);
    for (int u=0; u<V; u++) {
        if (!visited[u]) { //for each unvisited vertex
            for (list<int>::iterator it = adj[u].begin(); it != adj[u].end(); it++) {
                if (!visited[*it]) { //pick the first adjacent vertex of u which is not yet visited 
                    visited[u] = true;
                    visited[*it] = true;
                    break; //mark both vertices as visited and continue with the next vertex
                }
            }
        }
    }
    cout<<"Vertices in the cover :";
    for (int i=0; i<V; i++)
        if (visited[i])
            cout<<" "<<i;
    cout<<endl;
}

int main() {
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.vertexCover();
    return 0;
}
