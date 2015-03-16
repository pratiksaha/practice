//median of elements read from a data stream
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int getBalance(int x, int y) { //returns the balance: 0 -1 or 1
    if (x == y)
        return 0;
    else
        return x<y?-1:1;
}

int average(int x, int y) { //returns the average of x and y
    return (x+y)/2;
}

bool comp(const int& a, const int& b) { //to create a min heap; without this a max heap is created
    return a>b;
} 

int getMedian(int curr, int *median, vector<int> *maxHeap, vector<int> *minHeap) {
    int balance = getBalance(maxHeap->size(), minHeap->size());
    switch(balance) {
        case 0: //min and max heaps contain same no of elements
            if (curr<*median) { // curr fits in max heap
                maxHeap->push_back(curr);
                push_heap(maxHeap->begin(), maxHeap->end());
                *median = maxHeap->front();
            } else { // curr fits in min heap
                minHeap->push_back(curr);
                push_heap(minHeap->begin(), minHeap->end(), comp);
                *median = minHeap->front();
            }
            break;
        case 1: //more elements in max heap
            if (curr < (*median)) {
                minHeap->push_back(maxHeap->front());
                push_heap(minHeap->begin(), minHeap->end(), comp);
                pop_heap(maxHeap->begin(), maxHeap->end());
                maxHeap->pop_back();
                maxHeap->push_back(curr);
                push_heap(maxHeap->begin(), maxHeap->end());
            } else {
                minHeap->push_back(curr);
                push_heap(minHeap->begin(), minHeap->end(), comp);
            }
            *median = average(maxHeap->front(), minHeap->front());
            break;
        case -1: // more elements in min heap
            if (curr<*median) {
                maxHeap->push_back(curr);
                push_heap(maxHeap->begin(), maxHeap->end());;
            } else {
                maxHeap->push_back(minHeap->front());
                push_heap(maxHeap->begin(), maxHeap->end());
                pop_heap(minHeap->begin(), minHeap->end(), comp);
                minHeap->pop_back();
                minHeap->push_back(curr);
                push_heap(minHeap->begin(), minHeap->end(), comp);
            }
            *median = average(maxHeap->front(), minHeap->front());
            break;
    }
}
 
void medianInfinite(int *stream, int size) {
    vector<int> maxHeap;
    vector<int> minHeap;
    int median = 0;
    for(int i=0; i<size; i++) {
        getMedian(stream[i], &median, &maxHeap, &minHeap);
        cout<<"Till "<<i<<"th number: "<<stream[i]<<" median is "<<median<<endl;
    }
}

int main() {
    int arr[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Input Array :";
    for (int i=0; i<n; i++)
        cout<<" "<<arr[i];
    cout<<endl;
    medianInfinite(arr,n);
    return 0;
}
