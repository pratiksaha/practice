// Kosaraju's algorithm for strongly connected components
#include<iostream>
#include<list>
#include<stack>
using namespace std;
 
class Graph {
private:
    int V;
    list<int> *adj;
    void DFS_visit(int, bool*);
    void fillOrder(int, bool*, stack<int>*);
public:
    Graph(int);
    void addEdge(int, int);
    Graph getTranspose();
    void sccKosaraju();
};
 
Graph:: Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph:: addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph:: DFS_visit(int v, bool* visited) {
    visited[v] = true;
    cout<<" "<<v;
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
 
void Graph:: fillOrder(int v, bool* visited, stack<int>* st) {
    visited[v] = true;
    for(list<int>::iterator it=adj[v].begin(); it!=adj[v].end(); it++)
        if(!visited[*it])
            fillOrder(*it, visited, st);
    st->push(v); //push v to stack after v is finsed expanding in DFS
}

void Graph:: sccKosaraju() {
    stack<int> st;
    bool *visited = new bool[V];
    for(int i=0; i<V; i++)
        visited[i] = false; //initialize all vertices of g as not visited
    for(int i=0; i<V; i++)
        if(visited[i] == false)
            fillOrder(i, visited, &st);
    Graph gr = getTranspose();
    for(int i=0; i<V; i++)
        visited[i] = false; //initialize all vertices of g' as not visited
    while (!st.empty()) {
        int v = st.top();
        st.pop();
        if (!visited[v]) {
            gr.DFS_visit(v, visited);
            cout<<endl;
        }
    }
    delete []visited;
}

int main() {
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    cout<<"Strongly Connected Components in given graph :\n";
    g.sccKosaraju();
    return 0;
}
