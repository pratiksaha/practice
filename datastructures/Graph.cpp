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
public:
    Graph();
    ~Graph();
    void addVertex(int);
    void removeVertex(int);
    void addEdge(int, int);
    void removeEdge(int, int);
    void printGraph();
    void depthFirstTraversal();
    void breadthFirstTraversal();
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

}

void Graph::depthFirstTraversal() {
    bool *visited = new bool[nodes.size()];
    for (int i=0; i<nodes.size(); i++)
        visited[i] = false;
    cout<<"DFS :";
    for (int i=0; i<nodes.size(); i++) {
        if(!visited[i]) {
            stack<int> t;
            t.push(i);
            while(!t.empty()) {
                int curr = t.top();
                t.pop();
                visited[curr] = true;
                cout<<" "<<curr;
                for (list<int>::iterator it = nodes[curr].adj.begin(); it != nodes[curr].adj.end(); it++)
                    if(!visited[*it])
                        t.push(*it);
            }
        }
    }
    cout<<endl;
}

void Graph::breadthFirstTraversal() {
    bool *visited = new bool[nodes.size()];
    for (int i=0; i<nodes.size(); i++)
        visited[i] = false;
    cout<<"BFS :";
    for (int i=0; i<nodes.size(); i++) {
        if(!visited[i]) {
            queue<int> t;
            t.push(i);
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
        }
    }
    cout<<endl;
}

void Graph::topologicalSort() {

}

int main () {
    Graph G;
    G.addVertex(1);
    G.addVertex(0);
    G.addVertex(1);
    G.addVertex(1);
    G.addVertex(2);
    G.addVertex(3);
    G.printGraph();
    G.addEdge(0, 1);
    G.addEdge(0, 2);
    G.addEdge(1, 2);
    G.addEdge(2, 0);
    G.addEdge(2, 3);
    G.addEdge(3, 3);
    G.printGraph();
    G.breadthFirstTraversal();
    G.depthFirstTraversal();
    return 0;
}
