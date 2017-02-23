//to find total elements to be removed to make two sets disjoint
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
using namespace std;
 
int makeDisjointSets(int set1[], int set2[], int n, int m) {
    unordered_set <int> s;
    for (int i = 0; i < n; i++)
        s.insert(set1[i]);
    int result = 0;
    for (int i = 0;  i < m; i++)
        if (s.find(set2[i]) != s.end())
            result++;
    return result;
}
 
int main() {
    int set1[] = {20, 21, 22};
    int set2[] =  {22, 23, 24, 25, 20};
    int n = sizeof(set1)/sizeof(set1[0]);
    int m = sizeof(set2)/sizeof(set2[1]);
    cout<<"No of elements to be removed to make two sets disjoint is "<<makeDisjointSets(set1, set2, n, m)<<endl;
    return 0;
}
