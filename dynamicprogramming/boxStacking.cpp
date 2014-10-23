//Box Stacking Problem
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

struct box {
    int h, w, d; 
};

typedef struct box Box;

int compare(const void *a, const void * b) {//used by qsort
    return ((*(Box *)b).d*(*(Box *)b).w)-((*(Box *)a).d*(*(Box *)a).w);
}

int maxStackHeight(Box arr[], int n) {
    Box rot[3*n];
    int i, j;
    int index = 0;
    for (i = 0; i < n; i++) {    
        rot[index] = arr[i];
        index++;
      
        rot[index].h = arr[i].w;
        rot[index].d = max(arr[i].h, arr[i].d);
        rot[index].w = min(arr[i].h, arr[i].d);
        index++;
 
        rot[index].h = arr[i].d;
        rot[index].d = max(arr[i].h, arr[i].w);
        rot[index].w = min(arr[i].h, arr[i].w);
        index++;
    }

    n = 3*n;
    qsort (rot, n, sizeof(Box), compare);

    int msh[n];
    for (int i = 0; i < n; i++ )
        msh[i] = rot[i].h;
 
    for (i=1; i<n; i++)
        for (j=0; j<i; j++)
            if (rot[i].w<rot[j].w && rot[i].d<rot[j].d && msh[i]<(msh[j]+rot[i].h))
                msh[i] = msh[j]+rot[i].h;

    int max_height = msh[0];
    for (i=1; i<n; i++)
        if (max_height<msh[i])
            max_height = msh[i];
    return max_height;
}

int main() {
  Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
  cout<<"The maximum possible height of stack is "<<maxStackHeight(arr, sizeof(arr)/sizeof(arr[0]))<<endl;
  return 0;
}
