//to match pairs Nut-Bolt or Lock-Key problem
#include<iostream>
#include<cstdlib>
#include<cassert>
using namespace std;

int partition(char *arr, int low, int high, char pivot) {
    int i = low;
    for (int j=low; j<high; j++) {
        if (arr[j]<pivot) {
            swap(arr[i], arr[j]);
            i++;
        } else if (arr[j] == pivot) {
            swap(arr[j], arr[high]);
            j--;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

void matchPairs(char *a, char *b, int low, int high) {
    if (low < high) {
        int pivot = partition(a, low, high, b[high]); // choose last char of b for partition of a
        partition(b, low, high, a[pivot]); //use partition of a for partition of b
        matchPairs(a, b, low, pivot-1);
        matchPairs(a, b, pivot+1, high);
    }
}

void printMatches(char *a, char *b, int n) {
    for (int i=0; i<n; i++)
        cout<<a[i]<<"=>"<<b[i]<<endl;
}

int main() {
    char x[] = {'@', '#', '$', '%', '^', '&'};
    char y[] = {'$', '%', '&', '^', '@', '#'};
    int m = sizeof(x)/sizeof(x[0]);
    int n = sizeof(y)/sizeof(y[0]);
    assert(m==n);
    matchPairs(x, y, 0, n-1);
    printMatches(x, y, n);
    return 0;
}
