//m Coloring problem
#include<iostream>
using namespace std;
#define V 4

bool isSafe(int g[V][V], int c[], int cl, int v){//check if vertex v is safe to color cl
    for(int i=0; i<V; i++)
        if(g[v][i] && cl == c[i])
            return false;
    return true;
}

 
bool graphColoring(int g[V][V], int c[], int m, int v){
    if(v == V)
        return true; //complete if all vertices have been colored
    for(int cl=1; cl<=m; cl++){ //try every color
        if (isSafe(g, c, cl, v)){
            c[v] = cl;//assign current color
            if(graphColoring(g, c, m, v+1))//recurse for remainning
                return true;
            c[v] = 0;//backtrack
        }
    }
    return false;
}

int main(){
    int graph[V][V] = { {0, 1, 1, 1},
                        {1, 0, 1, 0},
                        {1, 1, 0, 1},
                        {1, 0, 1, 0}}; //Adjacency matrix represenataion of a graph
    int m = 3; // Number of colors
    int color[V] = {0}; //Initialize all colors as 0
    if(graphColoring(graph, color, m, 0)){ //Start from vertex 0
        for(int i=0; i<V; i++)
            cout<<"Vertix "<<i<<" is colored "<<color[i]<<endl;
    } else {
        cout<<"No solution exist"<<endl;
    }
    return 0;
}
