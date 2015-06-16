//to check if a given directed graph is strongly connected or not
#include<iostream>
#include<list>
#include<stack>
using namespace std;
 
class Graph {
private:
    int V;
    list<int> *adj;
    void DFS_visit(int , bool*);
public:
    Graph(int);
    ~Graph();
    void addEdge(int, int);
    Graph getTranspose();
    bool checkConnectivity();
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
}

void Graph:: DFS_visit(int v, bool* visited) {
    visited[v] = true;
    for (list<int>::iterator it=adj[v].begin(); it!=adj[v].end(); it++)
        if (!visited[*it])
            DFS_visit(*it, visited);
}

Graph Graph:: getTranspose() {
    Graph g(V);
    for (int v = 0; v < V; v++)
        for(list<int>::iterator it=adj[v].begin(); it!=adj[v].end(); it++)
            g.adj[*it].push_back(v); //reverse all edges
    return g;
}

bool Graph:: checkConnectivity() { //for a directed graph; for undirected do a traversal and if all vertices in traversal return true
    stack<int> st;
    bool visited[V];
    for(int i=0; i<V; i++)
        visited[i] = false; //initialize all vertices of g as not visited
    DFS_visit(0, visited);
    Graph gr = getTranspose();
    for(int i=0; i<V; i++)
        visited[i] = false; //initialize all vertices of g' as not visited
    gr.DFS_visit(0, visited);
    for (int i=0; i<V; i++)
        if (!visited[i])
            return false; //return false if all vertices are not visited in second DFS
    return true;
}

int main() {
    Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 0);
    g1.addEdge(2, 4);
    g1.addEdge(4, 2);
    (g1.checkConnectivity())?cout<<"Connected\n":cout<<"Not Connected\n";
 
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    (g2.checkConnectivity())?cout<<"Connected\n":cout<<"Not Connected\n";
    return 0;
}
