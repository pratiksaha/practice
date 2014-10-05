//To find the hamiltonian cycle
#include<iostream>
using namespace std;
#define V 5

bool isSafe(int g[V][V], int p[], int ver_cnt, int next_ver){
    //if(ver == next_ver)
     //   return false;
    if(!g[p[ver_cnt-1]][next_ver])
        return false; //if next vertex is an adjacent vertex of the previously added vertex
    for(int i=0; i<ver_cnt; i++)
        if(p[i] == next_ver)
            return false;//if next_ver is already included in the path
    return true; // all conditions passed, return true         
}

bool hamCycle(int g[V][V], int p[], int v){
    if (v == V)//If reached the last vertex
    {       
        if (g[p[v-1]][p[0]]) // And if there is an edge from the last included vertex to the first vertex 
           return true;
        else
          return false;
    }
    for (int vt=0; vt<V; vt++) { //Try different vertices
        if (isSafe(g, p, v, vt)) //Check for safety
        {
            p[v] = vt; //Consider current path
            if (hamCycle(g, p, v+1)) //recur
                return true;
            p[v] = -1; //backtrack
        }
    }
    return false;
}

int main(){
    int graph1[V][V] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0}};
    int graph2[V][V] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 0},
                      {0, 1, 1, 0, 0}};
    int path[V]; //stores the path
    int i;
    for(i=0; i<V; i++)
        path[i] = -1;//initialize
    int start = 0; //Start from 0
    path[0] = start;
    if(hamCycle(graph1, path, 1)){ //Consider next
        for(i=0; i<V; i++)
            cout<<path[i]<<" ";
        cout<<start<<endl;
    } else {
        cout<<"No hamiltonian cycle\n";
    }    
    for(i=0; i<V; i++)
        path[i] = -1;//reinitialize
    path[0] = start; //Start from 0
    if(hamCycle(graph2, path, 1)){ //Consider next
        for(i=0; i<V; i++)
            cout<<path[i]<<" ";
        cout<<start<<endl;
    } else {
        cout<<"No hamiltonian cycle\n";
    }
    return 0;
}
