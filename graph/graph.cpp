//adjacency list representation of graphs
#include<iostream>
#include<cstdlib>
using namespace std;

struct AdjListNode{
    int dest;
    AdjListNode* next;
};

struct AdjList{
    AdjListNode *head; //pointer to head node of list
};

struct Graph{
    int V; //size of array = no of vertices
    AdjList* array;
};
 

struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* temp = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    temp->dest = dest;
    temp->next = NULL;
    return temp;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*)malloc(V*sizeof(struct AdjList));
    for (int i=0; i<V; i++)
        graph->array[i].head = NULL; //initialize
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct AdjListNode* temp = newAdjListNode(dest);
    temp->next = graph->array[src].head;
    graph->array[src].head = temp;
    temp = newAdjListNode(src); //for undirected graph add a corresponding back node
    temp->next = graph->array[dest].head;
    graph->array[dest].head = temp;
}

void printGraph(struct Graph* graph) {
    for (int i=0; i<graph->V; i++) {
        struct AdjListNode* temp = graph->array[i].head;
        cout<<"Adjacency list of vertex "<<i<<" head";
        while (temp) {
            cout<<"->"<<temp->dest;
            temp = temp->next;
        }
        cout<<endl;
    }
}

int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printGraph(graph);
    return 0;
}
