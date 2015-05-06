//merge k sorted arrays
#include<iostream>
#include<cstdlib>
#include<climits>
using namespace std;

#define M 3
#define N 4

struct node {
    int val, i, j;
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


void buildMinHeap(struct node harr[], int n) {
    int i = (n-1)/2;
    while (i>=0) {
        minHeapify(harr, i, n);
        i--;
    }
}

int* mergeKSortedArray(int arr[M][N]) {
    int *output = new int[M*N];
    struct node *harr = new struct node[M];
    for (int i=0; i<M; i++) {
        harr[i].val = arr[i][0];
        harr[i].i = i;
        harr[i].j = 1;
    }
    buildMinHeap(harr, M);
    for (int count=0; count<M*N; count++) {
        struct node hr = harr[0];
        output[count] = hr.val;
        if (hr.j < N) {
            hr.val = arr[hr.i][hr.j];
            hr.j += 1;
        } else {
            hr.val = INT_MAX;
        }
        harr[0] = hr;
        minHeapify(harr, 0, M);
    }
    delete []harr;
    return output;
}


int main() {
    int arr[M][N] = {{2, 6, 12, 34},
                    {1, 9, 20, 1000},
                    {23, 34, 90, 2000}};
    int *output = mergeKSortedArray(arr);
    cout<<"Merged array is :";
    for (int i=0; i<M*N; i++)
        cout<<" "<<output[i];
    cout<<endl;
    delete []output;
    return 0;
}
