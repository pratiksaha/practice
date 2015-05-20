//to sort by frequency
#include<iostream>
#include<cstdlib>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

struct data_freq {
    int data, freq;
};

bool compare(struct data_freq a, struct data_freq b) {
    return (b.freq < a.freq);
}

void frequencySort(int *arr, int n) {
    map<int, int> hash; //in c++ STL map is implemented as a balanced binary search tree
    map<int, int>::iterator it;
    int i;
    for (i=0; i<n; i++) {
        it = hash.find(*(arr+i));
        int count = 0;
        if (it != hash.end())
            count = it->second;
        hash[*(arr+i)] = count + 1;
    }
    vector<struct data_freq> v;
    vector<struct data_freq>::iterator vi;
    for (it = hash.begin(); it != hash.end(); it++) {
        struct data_freq df;
        df.data = it->first;
        df.freq = it->second;
        v.push_back(df);
    }
    sort(v.begin(), v.end(), compare);
    i = 0;
    for (vi = v.begin(); vi != v.end(); vi++) {
        for (int freq = vi->freq; freq>0; freq--)
            arr[i++] = vi->data;
    }
}

void printArray(int *arr, int n) {
    for (int i=0; i<n; i++)
        cout<<" "<<*(arr+i);
    cout<<endl;
}

int main() {
    int arr[] = {2, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    frequencySort(arr, n);
    printArray(arr, n);
    return 0;
}
