//find the shortest and longest path in a DAG
#include<iostream>
#include<list>
#include<stack>
#include<climits>
using namespace std;

class Graph;

class Node {
friend Graph;
private:
    int vertex;
    int weight;
public:
    Node(int x, int y)  {
        vertex = x;  
        weight = y;
    }
};

class Graph {
private:
    int V;
    list<Node> *adj;
    void topologicalSort(int , bool*, stack<int>*);
public:
    Graph(int);
    ~Graph();
    void addEdge(int, int, int);
    bool checkReachable(int, int);
    void shortestPath(int);
    void longestPath(int);
};
 
Graph:: Graph(int V) {
    this->V = V;
    adj = new list<Node>[V];
}

Graph:: ~Graph() {
    delete[] adj;
}

void Graph:: addEdge(int u, int v, int w) {
    Node n(v, w);
    adj[u].push_back(n);
}

void Graph:: topologicalSort(int i, bool *visited, stack<int> *tsort) {
    visited[i] = true;
    for (list<Node>::iterator it=adj[i].begin(); it!=adj[i].end(); it++)
        if (!visited[it->vertex])
            topologicalSort(it->vertex, visited, tsort);
    tsort->push(i);
}

void Graph:: shortestPath(int s) {
    bool visited[V];
    for (int i=0; i<V; i++)
        visited[i] = false;
    stack<int> st;
    for (int i=0; i<V; i++)
        if (!visited[i])
            topologicalSort(i, visited, &st);
    int dist[V];
    for (int i=0; i<V; i++)
        dist[i] = INT_MAX;
    dist[s] = 0;
    while (!st.empty()) {       
        int curr = st.top();
        st.pop();
        if (dist[curr] != INT_MAX) {
            for (list<Node>::iterator it=adj[curr].begin(); it!=adj[curr].end(); it++)
                if (dist[it->vertex] > dist[curr] + it->weight)
                    dist[it->vertex] = dist[curr] + it->weight;
        }
    }
    for (int i=0; i<V; i++)
        (dist[i] == INT_MAX) ? cout<<i<<" : INFINITY\n" : cout<<i<<" : "<<dist[i]<<endl;
}

void Graph:: longestPath(int s) {
    bool visited[V];
    for (int i=0; i<V; i++)
        visited[i] = false;
    stack<int> st;
    for (int i=0; i<V; i++)
        if (!visited[i])
            topologicalSort(i, visited, &st);
    int dist[V];
    for (int i=0; i<V; i++)
        dist[i] = INT_MIN;
    dist[s] = 0;
    while (!st.empty()) {       
        int curr = st.top();
        st.pop();
        if (dist[curr] != INT_MIN) {
            for (list<Node>::iterator it=adj[curr].begin(); it!=adj[curr].end(); it++)
                if (dist[it->vertex] < dist[curr] + it->weight)
                    dist[it->vertex] = dist[curr] + it->weight;
        }
    }
    for (int i=0; i<V; i++)
        (dist[i] == INT_MIN) ? cout<<i<<" : INFINITY\n" : cout<<i<<" : "<<dist[i]<<endl;
}

int main() {
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    int s = 1;
    cout<<"Following are shortest distances from "<<s<<" :\n";
    g.shortestPath(s);
    cout<<"Following are longest distances from "<<s<<" :\n";
    g.longestPath(s);
    return 0;
}
