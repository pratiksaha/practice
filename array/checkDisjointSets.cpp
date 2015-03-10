//to check if two sets are disjoint
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool checkDisjointSets(vector<int> a, vector<int> b) {
    unordered_map<int, int> hash;
    vector<int>::iterator it;
    for(it=a.begin(); it!=a.end(); it++)
        hash.insert(make_pair(*it, 1));
    for(it=b.begin(); it!=b.end(); it++)
        if (hash.find(*it) != hash.end())
            return false;
    return true;
}

void printVector(vector<int> v) {
    vector<int>::iterator it;
    for(it=v.begin(); it!=v.end(); it++)
        cout<<" "<<*it;
}

int main() {
    int a1[] = {12, 34, 11, 9, 3}, a2[] = {7, 2, 1, 5}, a3[] = {7, 2, 11, 5};
    vector<int> v1 (a1, a1+sizeof(a1)/sizeof(a1[0]));
    vector<int> v2 (a2, a2+sizeof(a2)/sizeof(a2[0]));
    vector<int> v3 (a3, a3+sizeof(a3)/sizeof(a3[0]));
    cout<<"Sets {", printVector(v1), cout<<" } & {", printVector(v2), cout<<" } are "<<(checkDisjointSets(v1, v2)?"":"not ")<<"disjoint"<<endl;
    cout<<"Sets {", printVector(v1), cout<<" } & {", printVector(v3), cout<<" } are "<<(checkDisjointSets(v1, v3)?"":"not ")<<"disjoint"<<endl;
    return 0;
}
