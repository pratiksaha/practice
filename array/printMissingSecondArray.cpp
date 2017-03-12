//to find elements which are not present in second array
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
using namespace std;

void printMissingSecondArray(int a[], int b[], int n, int m) {
    unordered_set <int> s;
    for (int i = 0; i < m; i++)
        s.insert(b[i]);
    for (int i = 0;  i < n; i++)
        if (s.find(a[i]) == s.end())
            cout<<" "<<a[i];
    cout<<endl;
}

int main() {
    int a[] = { 1, 2, 6, 3, 4, 5 };
    int b[] = { 2, 4, 3, 1, 0 };
    int n = sizeof(a)/sizeof(a[0]);
    int m = sizeof(b)/sizeof(b[1]);
    printMissingSecondArray(a, b, n, m);
    return 0;
} 
