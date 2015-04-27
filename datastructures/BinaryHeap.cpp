//Binary Heap
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<iostream>
#include<climits>
#include<cstdlib>
using namespace std;

class BinaryHeap {
protected:
    int *harr; //pointer to array of elems in heap
    int capacity; //max possible size of heap
    int heap_size; //curr no of elems in heap
public:
    BinaryHeap(int cap); //constructor
    int parent(int i); //to get index of parent of node at index i
    int left(int i); //to get index of left child of node at index i
    int right(int i); //to get index of right child of node at index i
    int getRoot(); //to get the value at root of heap
};

class MinHeap: public BinaryHeap {
public:
    using BinaryHeap::BinaryHeap; //inheriting constructor
    int heapMin(); //returns the minimum key from min heap
    void minHeapInsert(int k); // Inserts a new key 'k'
    void minHeapDelete(int i); // Deletes a key stored at index i
    int minHeapExtractMin(); // to extract the root which is the minimum element
    void heapDecreaseKey(int i, int new_val); //decreases key value of key at index i to new_val
    void minHeapify(int ); //to heapify a subtree with root at given index
    void minHeapFix(int i); //to fix the heap if the heap property is violated
};

class MaxHeap: public BinaryHeap {
public:
    using BinaryHeap::BinaryHeap; //inheriting constructor
    int heapMax(); //returns the minimum key from max heap
    void maxHeapInsert(int k); // Inserts a new key 'k'
    void maxHeapDelete(int i); // Deletes a key stored at index i
    int maxHeapExtractMax(); // to extract the root which is the maximum element
    void heapIncreaseKey(int i, int new_val); //increases key value of key at index i to new_val
    void maxHeapify(int ); //to heapify a subtree with root at given index
    void maxHeapFix(int i); //to fix the heap if the heap property is violated
};

BinaryHeap :: BinaryHeap(int cap) {
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

int BinaryHeap :: parent(int i) {
    return (i-1)/2;
}

int BinaryHeap :: left(int i) {
    return 2*i+1;
}

int BinaryHeap :: right(int i) {
    return 2*i+2;
};

int BinaryHeap :: getRoot() {
    return harr[0]; 
}

int MinHeap :: heapMin() {
    return getRoot();
}

int MaxHeap :: heapMax() {
    return getRoot();
}

void MinHeap :: minHeapInsert(int k) {
    if (heap_size == capacity) {
        cout<<"Overflow: Could not insert "<<k<<endl;
    } else {
        heap_size++;
        int i = heap_size-1;
        harr[i] = k;
        minHeapFix(i);
    }
}

void MaxHeap :: maxHeapInsert(int k) {
    if (heap_size == capacity) {
        cout<<"Overflow: Could not insert "<<k<<endl;
    } else {
        heap_size++;
        int i = heap_size-1;
        harr[i] = k;
        maxHeapFix(i);
    }
}

void MinHeap :: minHeapDelete(int i) {
    heapDecreaseKey(i, INT_MIN);
    minHeapExtractMin();
}

void MaxHeap :: maxHeapDelete(int i) {
    heapIncreaseKey(i, INT_MAX);
    maxHeapExtractMax();
}

void MinHeap :: heapDecreaseKey(int i, int new_val) {
    harr[i] = new_val;
    minHeapFix(i);
}

void MaxHeap :: heapIncreaseKey(int i, int new_val) {
    harr[i] = new_val;
    maxHeapFix(i);
}
 
int MinHeap :: minHeapExtractMin() {
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)  {
        heap_size--;
        return harr[0];
    }
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    minHeapify(0);
    return root;
}

int MaxHeap :: maxHeapExtractMax() {
    if (heap_size <= 0)
        return INT_MIN;
    if (heap_size == 1)  {
        heap_size--;
        return harr[0];
    }
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    maxHeapify(0);
    return root;
}

void MinHeap :: minHeapFix(int i) {
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

void MaxHeap :: maxHeapFix(int i) {
    while (i != 0 && harr[parent(i)] < harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap :: minHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i; //pick the smallest among i, l and r
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i) { //swap and heapify only if smallest is not i
        swap(harr[i], harr[smallest]);
        minHeapify(smallest);
    }
}

void MaxHeap :: maxHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int largest = i; //pick the largest among i, l and r
    if (l < heap_size && harr[l] > harr[i])
        largest = l;
    if (r < heap_size && harr[r] > harr[largest])
        largest = r;
    if (largest != i) { //swap and heapify only if largest is not i
        swap(harr[i], harr[largest]);
        maxHeapify(largest);
    }
}



int main() {
    cout<<"Minheap :";
    MinHeap h1(11);
    h1.minHeapInsert(3);
    h1.minHeapInsert(2);
    h1.minHeapDelete(1);
    h1.minHeapInsert(15);
    h1.minHeapInsert(5);
    h1.minHeapInsert(4);
    h1.minHeapInsert(45);
    cout<<" "<<h1.minHeapExtractMin();
    cout<<" "<<h1.heapMin();
    h1.heapDecreaseKey(2, 1);
    cout<<" "<<h1.heapMin()<<endl;
    cout<<"Maxheap :";
    MaxHeap h2(11);
    h2.maxHeapInsert(3);
    h2.maxHeapInsert(2);
    h2.maxHeapDelete(1);
    h2.maxHeapInsert(15);
    h2.maxHeapInsert(5);
    h2.maxHeapInsert(4);
    h2.maxHeapInsert(45);
    cout<<" "<<h2.maxHeapExtractMax();
    cout<<" "<<h2.heapMax();
    h2.heapIncreaseKey(2, 16);
    cout<<" "<<h2.heapMax()<<endl;
    return 0;
}
