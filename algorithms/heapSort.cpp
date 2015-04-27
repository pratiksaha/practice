//Heap Sort
#include<iostream>
#include<cstdlib>
using namespace std;

struct MaxHeap {
    int size;
    int* array;
};

struct MinHeap {
    int size;
    int* array;
};

void maxHeapify(struct MaxHeap* maxHeap, int idx) {
    int left = 2*idx+1;
    int right = 2*idx+2;
    int largest = idx; //pick the largest among idx, left and right
    if (left < maxHeap->size && maxHeap->array[left] > maxHeap->array[largest])
        largest = left;
    if (right < maxHeap->size && maxHeap->array[right] > maxHeap->array[largest])
        largest = right;
    if (largest != idx) { //swap and heapify only if largest is not idx
        swap(maxHeap->array[largest], maxHeap->array[idx]);
        maxHeapify(maxHeap, largest);
    }
}

void minHeapify(struct MinHeap* minHeap, int idx) {
    int left = 2*idx+1;
    int right = 2*idx+2;
    int smallest = idx; //pick the smallest among idx, left and right
    if (left < minHeap->size && minHeap->array[left] < minHeap->array[smallest])
        smallest = left;
    if (right < minHeap->size && minHeap->array[right] < minHeap->array[smallest])
        smallest = right;
    if (smallest != idx) { //swap and heapify only if smallest is not idx
        swap(minHeap->array[smallest], minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

struct MaxHeap* createAndBuildMaxHeap(int *array, int size) {
    struct MaxHeap* maxHeap = (struct MaxHeap*) malloc(sizeof(struct MaxHeap));
    maxHeap->size = size;
    maxHeap->array = array;
    for (int i=(maxHeap->size-2)/2; i>=0; i--)
        maxHeapify(maxHeap, i);
    return maxHeap;
}

struct MinHeap* createAndBuildMinHeap(int *array, int size) {
    struct MinHeap* minHeap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap->size = size;
    minHeap->array = array;
    for (int i=(minHeap->size-2)/2; i>=0; i--)
        minHeapify(minHeap, i);
    return minHeap;
}

void heapSortIncr(int* array, int size) {
    struct MaxHeap* maxHeap = createAndBuildMaxHeap(array, size);
    while (maxHeap->size > 1) {
        swap(maxHeap->array[0], maxHeap->array[maxHeap->size-1]); //replace largest elem of heap with the last item of the heap
        maxHeap->size--;  //reduce heap size
        maxHeapify(maxHeap, 0);
    }
}

void heapSortDecr(int* array, int size) {
    struct MinHeap* minHeap = createAndBuildMinHeap(array, size);
    while (minHeap->size > 1) {
        swap(minHeap->array[0], minHeap->array[minHeap->size-1]); //replace smallest elem of heap with the last item of the heap
        minHeap->size--;  //reduce heap size
        minHeapify(minHeap, 0);
    }
}

void printArray(int* arr, int size) {
    for (int i=0; i<size; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

int main() {
    int arr1[] = {12, 11, 13, 5, 6, 7};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {12, 11, 13, 5, 6, 7};
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    cout<<"Input Array :";
    printArray(arr1, size1);
    heapSortIncr(arr1, size1);
    cout<<"Incr Sorted Array :";
    printArray(arr1, size1);
    cout<<"Input Array :";
    printArray(arr2, size2);
    heapSortDecr(arr2, size2);
    cout<<"Decr Sorted Array :";
    printArray(arr2, size2);
    return 0;
}
