//to find height using parent array
#include<iostream>
#include<cstring>
using namespace std;

void fillDepth(int parent[], int i, int depth[]) {
    if (!depth[i]) { //if depth not already filled
        if (parent[i] == -1) { //node is root
            depth[i] = 1;
        } else {
            if (depth[parent[i]] == 0)
                fillDepth(parent, parent[i], depth);
            depth[i] = depth[parent[i]]  + 1;
        }
    }
}

int heightParent(int parent[], int n) {
    int depth[n];
    memset(depth, 0, sizeof(depth));
    for (int i=0; i<n; i++)
        fillDepth(parent, i, depth);
    int height = depth[0]; //height of binary tree is maximum of all depths
    for (int i=1; i<n; i++)
        if (height < depth[i])
            height = depth[i];
    return height;
}

int main() {
    // int parent[] = {1, 5, 5, 2, 2, -1, 3};
    int parent[] = {-1, 0, 0, 1, 1, 3, 5};
    cout<<"Height is "<<heightParent(parent, sizeof(parent)/sizeof(parent[0]))<<endl;
    return 0;
}
