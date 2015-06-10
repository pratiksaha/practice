//to check whether a graph is tree or not
#include<iostream>
#include<list>
using namespace std;

class Graph {
private:
    int V;
    list<int> *adj;
    bool isCyclic(int, bool*, int);
public:
    Graph(int);
    ~Graph();
    void addEdge(int, int);
    bool isTree();
};
 
Graph:: Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

Graph:: ~Graph() {
    delete[] adj;
}
 
void Graph:: addEdge(int v, int w) { //undirected graph
    adj[v].push_back(w);
    adj[w].push_back(v);
}

bool Graph:: isCyclic(int v, bool* visited, int parent) {
    visited[v] = true;
    for (list<int>::iterator it=adj[v].begin(); it!=adj[v].end(); it++) {
        if (!visited[*it]) { //recur
            if (isCyclic(*it, visited, v))
                return true;
        } else if (*it != parent) { //there is a cycle if an adjacent is visited and not parent of current vertex
           return true;
        }
    }
    return false;
}

bool Graph:: isTree() {
    bool *visited = new bool[V];
    for (int i=0; i<V; i++)
        visited[i] = false;       
    if (isCyclic(0, visited, -1))
        return false; //graph is not a tree if there is a cycle
    for (int u=0; u<V; u++)
        if (!visited[u])
            return false; //graph is not a tree is any vertex is not reachable
    return true; //else graph is a tree
}

int main() {
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isTree()?cout<<"Graph is Tree\n":cout<<"Graph is not Tree\n";
    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.isTree()?cout<<"Graph is Tree\n":cout<<"Graph is not Tree\n";
    return 0;
}
