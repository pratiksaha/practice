//Graph
#include<iostream>
#include<cstdlib>
#include<vector>
#include<list>
#include<stack>
#include<queue>
using namespace std;

class Graph;

class Node {
friend class Graph;
private:
    int vertex;
    bool valid;
    list<int> adj;
public:
    Node(int v) {
        vertex = v;
        valid = true;    
    }
};

class Graph {
private:
    vector<Node> nodes;
    void topologicalSort(int , bool*, stack<int>*);
public:
    Graph();
    ~Graph();
    void addVertex(int);
    void removeVertex(int);
    void addEdge(int, int);
    void removeEdge(int, int);
    void printGraph();
    void depthFirstTraversal(int);
    void breadthFirstTraversal(int);
    void topologicalSort();
};

Graph:: Graph() {
    //nodes = new vector<struct node>();
    cout<<"Graph Created\n";
}

Graph:: ~Graph() {
    cout<<"Graph Destroyed\n";
}

void Graph::printGraph() {
    cout<<"Graph :\n";
    for (vector<Node>::iterator itv = nodes.begin(); itv != nodes.end(); itv++) {
        if (itv->valid) {
            cout<<"Vertex : "<<itv->vertex<<" Edges :";
            for (list<int>::iterator itl = itv->adj.begin(); itl != itv->adj.end(); itl++)
                cout<<" "<<*itl;
            cout<<endl;
        }
    }
}

void Graph::addVertex(int v) {
    if (v<nodes.size()) {
        cout<<"Vertex "<<v<<" is already added\n";
    } else if (v>nodes.size()) {
        cout<<"Error: next vertex to be added is "<<nodes.size()<<endl;
    } else {
        Node temp(v);
        nodes.push_back(temp);
    }
}

void Graph::removeVertex(int v) {
    for (vector<Node>::iterator itv = nodes.begin(); itv != nodes.end(); itv++) {
        if (itv->valid) {
            if (itv - nodes.begin() == v) {
                itv->adj.clear();
                itv->valid = false;
            } else {
                removeEdge(itv->vertex, v);
            }
        }
    }
}

void Graph::addEdge(int u, int v) {
    if (u>nodes.size()) {
        cout<<"Cannot add vertex "<<u<<endl;
        return;
    } else if(u==nodes.size()) {
        addVertex(u);
    } else {
        if (!nodes[u].valid)
            nodes[u].valid = true; //mark the vertex as valid
    }
    if (v>nodes.size()) {
        cout<<"Cannot add vertex "<<v<<endl;
        return;
    } else if(v==nodes.size()) {
        addVertex(v);
    } else {
        if (!nodes[v].valid)
            nodes[v].valid = true; //mark the vertex as valid
    }
    nodes[u].adj.push_back(v);
}

void Graph::removeEdge(int u, int v) {
    for (vector<Node>::iterator itv = nodes.begin(); itv != nodes.end(); itv++) {
        if (u == itv - nodes.begin() ) {
            for (list<int>::iterator itl = itv->adj.begin(); itl != itv->adj.end(); itl++) {
                if (*itl == v) {
                    itv->adj.erase(itl);
                    return;
                }
            }
        }
    }
}

void Graph::depthFirstTraversal(int v) {
    bool *visited = new bool[nodes.size()];
    for (int i=0; i<nodes.size(); i++)
        visited[i] = false;
    cout<<"DFS :";
    stack<int> t;
    t.push(v);
    while(!t.empty()) {
        int curr = t.top();
        t.pop();
        if(!visited[curr]) {
            visited[curr] = true;
            cout<<" "<<curr;
            for (list<int>::iterator it = nodes[curr].adj.begin(); it != nodes[curr].adj.end(); it++)
                if(!visited[*it])
                    t.push(*it);
        }
    }
    cout<<endl;
}

void Graph::breadthFirstTraversal(int v) {
    bool *visited = new bool[nodes.size()];
    for (int i=0; i<nodes.size(); i++)
        visited[i] = false;
    cout<<"BFS :";
    queue<int> t;
    t.push(v);
    while(!t.empty()) {
        int curr = t.front();
        t.pop();
        if(!visited[curr]) {
            cout<<" "<<curr;
            visited[curr] = true;
            for (list<int>::iterator it = nodes[curr].adj.begin(); it != nodes[curr].adj.end(); it++)
                if(!visited[*it])
                    t.push(*it);
        }
    }
    cout<<endl;
}
void Graph::topologicalSort(int i, bool *visited, stack<int> *tsort) {
    visited[i] = true;
    for (list<int>::iterator it = nodes[i].adj.begin(); it != nodes[i].adj.end(); it++)
        if (!visited[*it])
            topologicalSort(*it, visited,tsort);
    tsort->push(i);
}

void Graph::topologicalSort() {
    bool *visited = new bool[nodes.size()];
    for (int i=0; i<nodes.size(); i++)
        visited[i] = false;
    stack<int> tsort;
    for (int i=0; i<nodes.size(); i++)
        if(!visited[i] && nodes[i].valid)
            topologicalSort(i, visited, &tsort);
    cout<<"Topological Sort :";
    while(!tsort.empty()) {
        cout<<" "<<tsort.top();
        tsort.pop();
    }
    cout<<endl;
}

int main () {
    Graph g1;
    g1.addVertex(1);
    g1.addVertex(0);
    g1.addVertex(1);
    g1.addVertex(1);
    g1.addVertex(2);
    g1.addVertex(3);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(2, 0);
    g1.addEdge(2, 3);
    g1.addEdge(3, 3);
    g1.printGraph();
    g1.breadthFirstTraversal(2);
    g1.depthFirstTraversal(2);
    g1.removeEdge(1,2);
    g1.printGraph();
    g1.removeVertex(3);
    g1.printGraph();
    Graph g2;
    g2.addVertex(0);
    g2.addVertex(1);
    g2.addVertex(2);
    g2.addVertex(3);
    g2.addVertex(4);
    g2.addVertex(5);
    g2.addEdge(5, 2);
    g2.addEdge(5, 0);
    g2.addEdge(4, 0);
    g2.addEdge(4, 1);
    g2.addEdge(2, 3);
    g2.addEdge(3, 1);
    g2.printGraph();
    g2.topologicalSort();
    return 0;
}
