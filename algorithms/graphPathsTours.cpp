//paths and tours in a graph
#include<iostream>
#include<cstring>
#include<algorithm>
#include<list>
using namespace std;

class Graph {
private:
    int V;
    list<int> *adj;
    int getEulerianType();
    void DFS_visit(int, bool*);
    int DFS_count(int, bool*);
    void eulerPathFleury(int);
    bool isValidNextEdge(int, int);
public:
    Graph(int);
    ~Graph();
    void addEdge(int, int);
    void rmvEdge(int, int);
    bool isConnected();
    void testEulerian();
    void eulerPathFleury();
};

Graph:: Graph(int v) {
    this->V = v;
    adj = new list<int>[V];
}

Graph:: ~Graph() {
    delete[] adj;
}

void Graph:: addEdge(int u, int v) {
    adj[u].push_back(v);
}

void Graph:: rmvEdge(int u, int v) {
    list<int>::iterator it = find(adj[u].begin(), adj[u].end(), v);
    *it = -1;
}

void Graph:: DFS_visit(int v, bool* visited) {
    visited[v] = true;
    for (list<int>::iterator it=adj[v].begin(); it!=adj[v].end(); it++)
        if (!visited[*it])
            DFS_visit(*it, visited);
}

bool Graph:: isConnected() {
    bool visited[V];
    int i;
    for (i=0; i<V; i++)
        visited[i] = false;
    for (i=0; i<V; i++)
        if (adj[i].size() != 0)
            break; //get the first vertex with zero degree
    if (i == V) { //if there are no edges in the graph
        return true;
    } else {
        DFS_visit(i, visited);
        for (i = 0; i < V; i++)
            if (visited[i] == false && adj[i].size() > 0)
                return false; //if all non-zero degree vertices are not visited
        return true; //all non-zero degree vertices are visited
    }
}

int Graph:: getEulerianType() {
    if (!isConnected())
        return 0;
    int odd_count = 0;
    for (int i=0; i<V; i++)
        if (adj[i].size() & 1)
            odd_count++;
    if (odd_count == 2)
        return 2;
    else if (odd_count == 0)
        return 1;
    else
        return 0;
}

void Graph:: testEulerian() {
    int res = getEulerianType();
    if (res == 2)
        cout<<"Graph has a Euler path\n";
    else if (res == 1)
        cout<<"Graph has a Euler cycle\n";
    else
        cout<<"Graph is not Eulerian\n";
}

int Graph:: DFS_count(int v, bool* visited) {
    visited[v] = true;
    int count = 1;
    for (list<int>::iterator it=adj[v].begin(); it!=adj[v].end(); it++)
        if (*it != -1 && !visited[*it])
            count += DFS_count(*it, visited);
    return count;
}
 
bool Graph:: isValidNextEdge(int u, int v) {
    int adj_count = 0;
    for (list<int>::iterator it=adj[u].begin(); it!=adj[u].end(); it++)
        if (*it != -1)
            adj_count++;
    if (adj_count == 1) { //only one adjacent vertex i.e. u-v is a bridge (no other option)
        return true;
    } else {
        bool visited[V];
        memset(visited, false, V);
        int count_incl = DFS_count(u, visited);
        rmvEdge(u, v);
        rmvEdge(v, u);
        memset(visited, false, V);
        int count_excl = DFS_count(u, visited);
        addEdge(u, v);
        addEdge(v, u);
        return (count_incl > count_excl)? false: true; //u-v is a bridge if count_incl > count_excl (we do not want to burn bridges)
    }
}

void Graph:: eulerPathFleury(int u) {
    for (list<int>::iterator it=adj[u].begin(); it!=adj[u].end(); it++) {
        int v = *it;
        if (v != -1 && isValidNextEdge(u, v)) {
            cout<<" "<<u<<"-"<<v;
            rmvEdge(u, v);
            rmvEdge(v, u);
            eulerPathFleury(v);
        }
    }
}

void Graph:: eulerPathFleury() {
    cout<<"Euler Path :";
    int u = 0;
    for (int i=0; i<V; i++) {
        if (adj[i].size() & 1) {
            u = i;
            break; //find the first vertex with odd degree
        }
    }
    eulerPathFleury(u);
    cout<<endl;
}

int main() {

    Graph ept1(5);
    ept1.addEdge(1, 0);
    ept1.addEdge(0, 2);
    ept1.addEdge(2, 1);
    ept1.addEdge(0, 3);
    ept1.addEdge(3, 4);
    ept1.addEdge(0, 1);
    ept1.addEdge(2, 0);
    ept1.addEdge(1, 2);
    ept1.addEdge(3, 0);
    ept1.addEdge(4, 3);
    ept1.testEulerian();
 
    Graph ept2(5);
    ept2.addEdge(1, 0);
    ept2.addEdge(0, 2);
    ept2.addEdge(2, 1);
    ept2.addEdge(0, 3);
    ept2.addEdge(3, 4);
    ept2.addEdge(4, 0);
    ept2.addEdge(0, 1);
    ept2.addEdge(2, 0);
    ept2.addEdge(1, 2);
    ept2.addEdge(3, 0);
    ept2.addEdge(4, 3);
    ept2.addEdge(0, 4);
    ept2.testEulerian();
 
    Graph ept3(5);
    ept3.addEdge(1, 0);
    ept3.addEdge(0, 2);
    ept3.addEdge(2, 1);
    ept3.addEdge(0, 3);
    ept3.addEdge(3, 4);
    ept3.addEdge(1, 3);
    ept3.addEdge(0, 1);
    ept3.addEdge(2, 0);
    ept3.addEdge(1, 2);
    ept3.addEdge(3, 0);
    ept3.addEdge(4, 3);
    ept3.addEdge(3, 1);
    ept3.testEulerian();

    Graph ept4(3);
    ept4.addEdge(0, 1);
    ept4.addEdge(1, 2);
    ept4.addEdge(2, 0);
    ept4.addEdge(1, 0);
    ept4.addEdge(2, 1);
    ept4.addEdge(0, 2);
    ept4.testEulerian();

    Graph ept5(3);
    ept5.testEulerian();

    Graph ep1(4);
    ep1.addEdge(0, 1);
    ep1.addEdge(0, 2);
    ep1.addEdge(1, 2);
    ep1.addEdge(2, 3);
    ep1.addEdge(1, 0);
    ep1.addEdge(2, 0);
    ep1.addEdge(2, 1);
    ep1.addEdge(3, 2);
    ep1.eulerPathFleury();
 
    Graph ep2(3);
    ep2.addEdge(0, 1);
    ep2.addEdge(1, 2);
    ep2.addEdge(2, 0);
    ep2.addEdge(1, 0);
    ep2.addEdge(2, 1);
    ep2.addEdge(0, 2);
    ep2.eulerPathFleury();
 
    Graph ep3(5);
    ep3.addEdge(1, 0);
    ep3.addEdge(0, 2);
    ep3.addEdge(2, 1);
    ep3.addEdge(0, 3);
    ep3.addEdge(3, 4);
    ep3.addEdge(3, 2);
    ep3.addEdge(3, 1);
    ep3.addEdge(2, 4);
    ep3.addEdge(0, 1);
    ep3.addEdge(2, 0);
    ep3.addEdge(1, 2);
    ep3.addEdge(3, 0);
    ep3.addEdge(4, 3);
    ep3.addEdge(2, 3);
    ep3.addEdge(1, 3);
    ep3.addEdge(4, 2);
    ep3.eulerPathFleury();
 
  return 0;
}
