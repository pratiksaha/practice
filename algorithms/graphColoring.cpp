//graph coloring problem
#include<iostream>
#include<list>
using namespace std;

class Graph { //undirected
private:
    int V;
    list<int> *adj;
public:
    Graph(int);
    ~Graph();
    void addEdge(int, int);
    void graphColoring();
};
 
Graph:: Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

Graph:: ~Graph() {
    delete [] adj;
}
   
void Graph:: addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph:: graphColoring() {
    int result[V];
    result[0] = 0; //1st color to 1st vertex
    for (int u=1; u<V; u++)
        result[u] = -1;  //no color for other vertices
    bool color[V]; //at most V colors are required
    for (int clr=0; clr<V; clr++)
        color[clr] = false;     
    for (int u=1; u<V; u++) {
        for (list<int>::iterator it=adj[u].begin(); it!=adj[u].end(); it++)
            if (result[*it] != -1)
                color[result[*it]] = true;
        int clr;
        for (clr=0; clr<V; clr++)
            if (!color[clr])
                break; //get the first available color
        result[u] = clr;
        for (list<int>::iterator it=adj[u].begin(); it!=adj[u].end(); it++)
            if (result[*it] != -1)
                color[result[*it]] = false; //reset
    }
    for (int u = 0; u < V; u++)
        cout<<"Vertex "<<u<<" --->  Color "<<result[u]<<endl;
}

int main() {
    Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 3);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
    cout<<"Coloring of Graph :\n";
    g1.graphColoring();
 
    Graph g2(5);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(1, 2);
    g2.addEdge(1, 4);
    g2.addEdge(2, 4);
    g2.addEdge(4, 3);
    cout<<"Coloring of Graph :\n";
    g2.graphColoring();
 
    return 0;
}
