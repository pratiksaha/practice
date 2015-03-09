//sort a nearly sorted array
#include<iostream>
#include<algorithm>
using namespace std;

bool comp(const int& a, const int& b) { //to create a min heap; without this a max heap is created
    return a>b;
}

void sortNearly(int arr[], int size, int k) {
    int *heap = new int[k+1];
    for (int i = 0; i<=k && i<size; i++)
        heap[i] = arr[i];
    make_heap(heap, heap+k+1, comp); //create a min heap of entire array
    for(int i=k+1, ti=0; ti<size; i++, ti++) { //i is index for remainning elem and ti is target index of for curr min elem in heap
        if (i < size) { //if there are remaining elems
            pop_heap(heap, heap+k+1, comp); //move lowest val to last -1
            arr[ti] = heap[k];
            heap[k] = arr[i];
            push_heap(heap, heap+k+1, comp); //push the next elem to heap
        } else {
            pop_heap(heap,heap+k+1, comp);
            arr[ti] = heap[k];
            k--; //decrease  the size for next iteration
        }
    }
    delete []heap;
}

void printArray(int arr[], int size) {
    for (int i=0; i < size; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

int main() {
    int k = 3;
    int arr[] = {2, 6, 3, 12, 56, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Input Array :", printArray(arr, n);
    sortNearly(arr, n, k);
    cout<<"Output Array :", printArray(arr, n);
    return 0;
}
