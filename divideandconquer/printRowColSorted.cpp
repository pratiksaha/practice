//print in sorted asc & desc in a row col sorted matrix
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<iostream>
#include<cstdlib>
#include<climits>
using namespace std;

#define M 4
#define N 4

struct node {
    int val, r, c;
};

void minHeapify(struct node harr[], int i, int size) {
    int l = i*2+1;
    int r = i*2+2;
    int smallest = i;
    if (l<size && harr[l].val<harr[i].val)
        smallest = l;
    if (r<size && harr[r].val<harr[smallest].val)
        smallest = r;
    if (smallest != i) {
        swap(harr[i], harr[smallest]);
        minHeapify(harr, smallest, size);
    }
}

void maxHeapify(struct node harr[], int i, int size) {
    int l = i*2+1;
    int r = i*2+2;
    int largest = i;
    if (l<size && harr[l].val>harr[i].val)
        largest = l;
    if (r<size && harr[r].val>harr[largest].val)
        largest = r;
    if (largest != i) {
        swap(harr[i], harr[largest]);
        maxHeapify(harr, largest, size);
    }
}

void buildMinHeap(struct node harr[], int n) {
    int i = (n-1)/2;
    while (i>=0) {
        minHeapify(harr, i, n);
        i--;
    }
}

void buildMaxHeap(struct node harr[], int n) {
    int i = (n-1)/2;
    while (i>=0) {
        maxHeapify(harr, i, n);
        i--;
    }
}

void printAsc(int mat[M][N]) {
    struct node harr[N];
    for (int i=0; i<N; i++)
        harr[i] =  {mat[0][i], 0, i};
    buildMinHeap(harr, N);
    cout<<"In Ascending order :";
    for (int i=0; i<M*N; i++) {
        struct node hr = harr[0];
        cout<<" "<<hr.val;
        int nextval = (hr.r<M-1)? mat[hr.r+1][hr.c]: INT_MAX;
        harr[0] =  {nextval, hr.r+1, hr.c};
        minHeapify(harr, 0, N);
    }
    cout<<endl;
}
void printDesc(int mat[M][N]) {
    struct node harr[N];
    for (int i=0; i<N; i++)
        harr[i] =  {mat[M-1][i], M-1, i};
    buildMaxHeap(harr, N);
    cout<<"In Descending order :";
    for (int i=0; i<M*N; i++) {
        struct node hr = harr[0];
        cout<<" "<<hr.val;
        int nextval = (hr.r>0)? mat[hr.r-1][hr.c]: INT_MIN;
        harr[0] =  {nextval, hr.r-1, hr.c};
        maxHeapify(harr, 0, N);
    }
    cout<<endl;
}

int main() {
    int mat[4][4] ={{10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {25, 29, 37, 48},
                    {32, 33, 39, 50},
                   };
    printAsc(mat);
    printDesc(mat);
    return 0;
}
