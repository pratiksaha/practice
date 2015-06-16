//to check for biconnectivity, bridges and articultion points (cut-vertices) in a graph (revisit)
#include<iostream>
#include<list>
#include<stack>
using namespace std;
 
class Graph {
private:
    int V;
    list<int> *adj;
    bool checkBiConnectivity(int, bool*, int*, int*, int*);
    void bridge(int, bool*, int*, int*, int*);
    void articulationPoint(int, bool*, int*, int*, int*);
public:
    Graph(int);
    ~Graph();
    void addEdge(int, int);
    bool checkBiConnectivity();
    void bridge();
    void articulationPoint();
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

/*
visited[i] = true is i is visited
parent[i] = parent of vertex i
disc[i] = discovery time of vertex i
low[i] = min(disc[i], disc[j]) where j is a parent of i and there is a back edge from some descendant of i to j
*/

bool Graph:: checkBiConnectivity(int u, bool visited[], int disc[],int low[],int parent[]) {
    static int ct = 0;
    int children = 0;
    visited[u] = true;
    disc[u] = low[u] = ++ct;
    for (list<int>::iterator it=adj[u].begin(); it!=adj[u].end(); it++) {
        int v = *it;
        if (!visited[v]) { //make v a child of u if v is not visited yet and recur
            children++;
            parent[v] = u;
            if (checkBiConnectivity(v, visited, disc, low, parent)) //check if subgraph rooted with v has an articulation point
                return true;
            low[u]  = min(low[u], low[v]); //check if the subtree rooted with v has a connection to one of the ancestors of u
            if (parent[u] == -1 && children > 1)
                return true;//u is an articulation point if u is root of DFS tree and has two or more children
            if (parent[u] != -1 && low[v] >= disc[u])
                return true;//u is an articulation point if u is not root and low value of one of its child is more than discovery value of u
        } else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]); //update low value of u for parent function calls
        }
    }
    return false;
}

bool Graph:: checkBiConnectivity() {
    bool visited[V];
    int disc[V];
    int low[V];
    int parent[V];
    for (int i=0; i<V; i++) {
        parent[i] = -1;
        visited[i] = false;
    }
    if (checkBiConnectivity(0, visited, disc, low, parent) == true)
        return false; //graph is not biconnected if there are no articulation points
    for (int i=0; i<V; i++)
        if (!visited[i])
            return false; //graph is not biconnected if there are articulation points but the graph is not connected
    return true;
}

void Graph:: bridge(int u, bool visited[], int disc[],int low[],int parent[]) {
    static int bt = 0;
    visited[u] = true;
    disc[u] = low[u] = ++bt;
    for (list<int>::iterator it=adj[u].begin(); it!=adj[u].end(); it++) {
        int v = *it;
        if (!visited[v]) { //make v a child of u if v is not visited yet and recur
            parent[v] = u;
            bridge(v, visited, disc, low, parent);
            low[u]  = min(low[u], low[v]); //check if the subtree rooted with v has a connection to one of the ancestors of u
            if (low[v] > disc[u]) //u-v is a bridge if the lowest vertex reachable from subtree under v is below u in DFS tree
                cout<<" "<<u<<"-"<<v;
        } else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]); //update low value of u for parent function calls
        }
    }
}

void Graph:: bridge() {
    bool visited[V];
    int disc[V];
    int low[V];
    int parent[V];
    for (int i=0; i<V; i++) {
        parent[i] = -1;
        visited[i] = false;
    }
    for (int i=0; i<V; i++)
        if (!visited[i])
            bridge(0, visited, disc, low, parent);
    cout<<endl;
}

void Graph:: articulationPoint(int u, bool visited[], int disc[],int low[],int parent[]) {
    static int at = 0;
    int children = 0;
    visited[u] = true;
    disc[u] = low[u] = ++at;
    for (list<int>::iterator it=adj[u].begin(); it!=adj[u].end(); it++) {
        int v = *it;
        if (!visited[v]) { //make v a child of u if v is not visited yet and recur
            children++;
            parent[v] = u;
            articulationPoint(v, visited, disc, low, parent);
            low[u]  = min(low[u], low[v]); //check if the subtree rooted with v has a connection to one of the ancestors of u
            if (parent[u] == -1 && children > 1)
                cout<<" "<<u;//u is an articulation point if u is root of DFS tree and has two or more children
            if (parent[u] != -1 && low[v] >= disc[u])
                cout<<" "<<u;//u is an articulation point if u is not root and low value of one of its child is more than discovery value of u
        } else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]); //update low value of u for parent function calls
        }
    }
}

void Graph:: articulationPoint() {
    bool visited[V];
    int disc[V];
    int low[V];
    int parent[V];
    for (int i=0; i<V; i++) {
        parent[i] = -1;
        visited[i] = false;
    }
    for (int i=0; i<V; i++)
        if (!visited[i])
            articulationPoint(0, visited, disc, low, parent);
    cout<<endl;
}

int main() {
    cout<<"1st Graph : ";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    (g1.checkBiConnectivity())?cout<<"Biconnected Graph\n":cout<<"Not a Biconnected Graph\n";
    cout<<"Bridges :";
    g1.bridge();
    cout<<"Articulation Points :";
    g1.articulationPoint();
    
    Graph g2(4);
    cout<<"2nd Graph : ";
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    (g2.checkBiConnectivity())?cout<<"Biconnected Graph\n":cout<<"Not a Biconnected Graph\n";
    cout<<"Bridges :";
    g2.bridge();
    cout<<"Articulation Points :";
    g2.articulationPoint();

    Graph g3(7);
    cout<<"3rd Graph : ";
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    (g3.checkBiConnectivity())?cout<<"Biconnected Graph\n":cout<<"Not a Biconnected Graph\n";
    cout<<"Bridges :";
    g3.bridge();
    cout<<"Articulation Points:";
    g3.articulationPoint();
 
    return 0;
}
