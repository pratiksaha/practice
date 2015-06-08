//HopCroft Tarjan algorithm to find biconnected components
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<iostream>
#include<stack>
#include<list>
#include<tuple>
using namespace std;

class Graph {
    int V;
    list<int> *adj;
    void bccHopcroftTarjan(int, int*, int*, int*, int*, int*, stack<tuple <int, int> >*);
public:
    Graph(int);
    void addEdge(int, int);
    int bccHopcroftTarjan();
};
   
Graph:: Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}
   
void Graph:: addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph:: bccHopcroftTarjan(int u, int* disc, int* low, int* parent, int* time, int* count, stack<tuple <int, int> >* st) {
    *time += 1;
    disc[u] = low[u] = *time;
    int children = 0;
    for (list<int>::iterator it=adj[u].begin(); it!=adj[u].end(); it++) {
        int v = *it;
        if (disc[v] == -1) { //tree edge
            children++;
            parent[v] = u;
            st->push(make_tuple(u,v));
            bccHopcroftTarjan(v, disc, low, parent, time, count, st);
            low[u]  = min(low[u], low[v]);
            if ((disc[u]==1 && children>1) || (disc[u]>1 && low[v]>=disc[u])) { //if u is an articulation point
                tuple<int, int> temp = st->top();
                while(get<0>(temp) != u || get<1>(temp) != v) { //pop all edges from stack till u--v   
                    cout<<" "<<get<0>(temp)<<"--"<<get<1>(temp);
                    st->pop();
                    temp = st->top();
                }
                cout<<" "<<get<0>(temp)<<"--"<<get<1>(temp);
                st->pop();
                cout<<endl;
                *count += 1;
            }
        } else if(v!=parent[u] && disc[v]<low[u]) { //back edge but not cross edge
            low[u] = min(low[u], disc[v]);
            st->push(make_tuple(u, v));
        }
    }
}

int Graph::bccHopcroftTarjan() {
    int *parent = new int[V]; //parents of current vertex
    int *disc = new int[V]; //discovery times of visited vertices
    int *low = new int[V]; //earliest visited vertex (the vertex with minimum discovery time) that can be reached from subtree rooted with current vertex
    for (int i=0; i<V; i++) {
        disc[i] = -1;
        low[i] = -1;
        parent[i] = -1;
    }
    int time = 0; //time of vertex visit
    int count = 0; //count of biconnected components
    stack<tuple<int, int> > st; //visited edges
    for (int i=0; i<V; i++) {
        if (disc[i] == -1)
            bccHopcroftTarjan(i, disc, low, parent, &time, &count, &st);
        bool flag = false;
        while(!st.empty()) {
            flag = true;
            tuple<int, int> temp = st.top();
            cout<<" "<<get<0>(temp)<<"--"<<get<1>(temp);
            st.pop();
        }
        if(flag) {
            cout<<endl;
            count++;
        }
    }
    return count;
}

int main() {
    Graph g(12);
    g.addEdge(0,1);
    g.addEdge(1,0);
    g.addEdge(1,2);
    g.addEdge(2,1);
    g.addEdge(1,3);
    g.addEdge(3,1);
    g.addEdge(2,3);
    g.addEdge(3,2);
    g.addEdge(2,4);
    g.addEdge(4,2);
    g.addEdge(3,4);
    g.addEdge(4,3);
    g.addEdge(1,5);
    g.addEdge(5,1);
    g.addEdge(0,6);
    g.addEdge(6,0);
    g.addEdge(5,6);
    g.addEdge(6,5);
    g.addEdge(5,7);
    g.addEdge(7,5);
    g.addEdge(5,8);
    g.addEdge(8,5);
    g.addEdge(7,8);
    g.addEdge(8,7);
    g.addEdge(8,9);
    g.addEdge(9,8);
    g.addEdge(10,11);
    g.addEdge(11,10);
    cout<<"Above are "<<g.bccHopcroftTarjan()<<" biconnected components in graph"<<endl;
    return 0;
}
