//to check if vertex d is reachable from s
#include<iostream>
#include<list>
using namespace std;

class Graph {
private:
    int V;
    list<int> *adj;
public:
    Graph(int V);
    ~Graph();
    void addEdge(int v, int w);
    bool checkReachable(int s, int d);
};
 
Graph:: Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

Graph:: ~Graph() {
    delete[] adj;
}

void Graph:: addEdge(int v, int w) {
    adj[v].push_back(w);
}

bool Graph:: checkReachable(int s, int d) {
    if (s == d) { //base case
        return true;
    } else {
        bool visited[V];
        for (int i=0; i<V; i++)
            visited[i] = false;
        list<int> queue;
        visited[s] = true;
        queue.push_back(s);
        while (!queue.empty()) {
            int curr = queue.front();
            queue.pop_front();
            for (list<int>::iterator it=adj[curr].begin(); it!=adj[curr].end(); it++) {
                if (*it == d) { //destination reached
                    return true;
                } else if (!visited[*it]) { //continue with bfs
                    visited[*it] = true;
                    queue.push_back(*it);
                }
            }
        }
        return false;
    }
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    int u = 1, v = 3;
    if(g.checkReachable(u, v))
        cout<<"There is a path from "<<u<<" to "<<v<<endl;
    else
        cout<<"There is no path from "<<u<<" to "<<v<<endl;
    u = 3, v = 1;
    if(g.checkReachable(u, v))
        cout<<"There is a path from "<<u<<" to "<<v<<endl;
    else
        cout<<"There is no path from "<<u<<" to "<<v<<endl;
    return 0;
}
