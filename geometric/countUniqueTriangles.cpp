//to find number of unique Triangles
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include <bits/stdc++.h>
using namespace std;

struct triangle {
    int a, b, c;
};

typedef triangle Triangle;

int sort3nos(int &a, int &b, int &c) {
    if (a > b)
        swap(a, b);
    if (b > c)
        swap(b, c);
    if (a > b)
        swap(a, b);
}

int countUniqueTriangles(Triangle arr[], int n) {
    set < pair< int, pair<int, int> > > s;
    for (int i=0; i<n; i++) {
        int a = arr[i].a, b = arr[i].b, c = arr[i].c;
        sort3nos(a, b, c);
        s.insert({a, {b, c}});
    }
    return s.size();
}

int main() {
    Triangle arr[] = {{3, 2, 2}, {3, 4, 5}, {1, 2, 2}, {2, 2, 3}, {5, 4, 3}, {6, 4, 5}};
    int n = sizeof(arr)/sizeof(Triangle);
    cout<<"Number of Unique Triangles are "<<countUniqueTriangles(arr, n)<<endl;
    return 0;
}
