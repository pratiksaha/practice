//to take numbers from different arrays and print them in sorted order
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define N 3
#define M 3

bool comp(const int& a, const int& b) { //to create a min heap; without this a max heap is created
    return a>b;
}

void externalSort(int array[N][M]) {
    vector<int> minHeap;
    cout<<"For given nos :\n";
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cout<<" "<<array[i][j];
            minHeap.push_back(array[i][j]);
            push_heap(minHeap.begin(), minHeap.end(), comp);
        }
        cout<<endl;
    }
    cout<<"External Sort :";
    while(!minHeap.empty()) {
        cout<<" "<<minHeap.front();
        pop_heap(minHeap.begin(), minHeap.end(), comp);
        minHeap.pop_back();
    }
    cout<<endl;
}

int main() {
    int array[N][M] = { {30, 40, 50},
                        {10, 35, 45},
                        {15, 60, 70}
                      };
    externalSort(array);
    return 0;
}
