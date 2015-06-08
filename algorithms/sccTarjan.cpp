//Tarjan's algorithm for strongly connected components
#include<iostream>
#include<list>
#include<stack>
using namespace std;

class Graph {
private:
    int V;
    list<int> *adj;
    void sccTarjan(int, int*, stack<int>*, int*, int*, bool*);
public:
    Graph(int);
    ~Graph();
    void addEdge(int, int);
    void sccTarjan();
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

void Graph:: sccTarjan(int u, int *time, stack<int>* st, int* disc, int* low, bool* stackMember) {
    *time += 1;
    disc[u] = low[u] = *time;
    st->push(u);
    stackMember[u] = true;
    for (list<int>::iterator it=adj[u].begin(); it!=adj[u].end(); it++) { //for all adjacent vertices of u
        int v = *it;
        if (disc[v] == -1) { //tree edge
            sccTarjan(v, time, st, disc, low, stackMember);
            low[u]  = min(low[u], low[v]); //check if the subtree rooted with 'v' has a connection to one of the ancestors of 'u'
        } else if (stackMember[v]) { //back edge
            low[u]  = min(low[u], disc[v]);
        }
    }

    if (low[u] == disc[u]) { //print scc if head node found
        while (st->top() != u) {
            int w = st->top();
            cout<<" "<<w;
            stackMember[w] = false;
            st->pop();
        }
        int w = st->top();
        cout<<" "<<w<<endl;
        stackMember[w] = false;
        st->pop();
    }
}

void Graph:: sccTarjan() {
    int *disc = new int[V]; //discovery times of visited vertices
    int *low = new int[V]; //earliest visited vertex (the vertex with minimum discovery time) that can be reached from subtree rooted with current vertex
    stack<int> *st = new stack<int>(); //all the connected ancestors (could be part of scc)
    bool *stackMember = new bool[V]; //index array for faster check whether a node is in stack
    int time = 0; //time of vertex visit
    
    for (int i=0; i<V; i++) {
        disc[i] = -1;
        low[i] = -1;
        stackMember[i] = false;
    }
    
    for (int i=0; i<V; i++)
        if (disc[i] == -1)
            sccTarjan(i, &time, st, disc, low, stackMember);
    
    delete[] disc;
    delete[] low;
    delete st;
    delete[] stackMember;
}

int main() {
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    cout<<"Strongly Connected Components in given graph :\n";
    g1.sccTarjan();
    
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    cout<<"Strongly Connected Components in given graph :\n";
    g2.sccTarjan();

    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    cout<<"Strongly Connected Components in given graph :\n";
    g3.sccTarjan();

    Graph g4(11);
    g4.addEdge(0,1);
    g4.addEdge(0,3);
    g4.addEdge(1,2);
    g4.addEdge(1,4);
    g4.addEdge(2,0);
    g4.addEdge(2,6);
    g4.addEdge(3,2);
    g4.addEdge(4,5);
    g4.addEdge(4,6);
    g4.addEdge(5,6);
    g4.addEdge(5,7);
    g4.addEdge(5,8);
    g4.addEdge(5,9);
    g4.addEdge(6,4);
    g4.addEdge(7,9);
    g4.addEdge(8,9);
    g4.addEdge(9,8);
    cout<<"Strongly Connected Components in given graph :\n";
    g4.sccTarjan();

    Graph g5(5);
    g5.addEdge(0,1);
    g5.addEdge(1,2);
    g5.addEdge(2,3);
    g5.addEdge(2,4);
    g5.addEdge(3,0);
    g5.addEdge(4,2);
    cout<<"Strongly Connected Components in given graph :\n";
    g5.sccTarjan();
 
    return 0;
}
