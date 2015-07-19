//rerrange a string such that same chars are k distance away
//Using features of C++ Standard (2001) Compile using g++ -std=c++11
#include<iostream>
#include<cstring>
#include<unordered_map>
#include<utility>
#include<algorithm>
using namespace std;


bool comp(pair<char,int> a, pair<char,int> b) {
    return a.second < b.second;
}

void rearrangeKDist(char str[], int d) {
    int n = strlen(str);
    unordered_map<char, int> table;
    for (int i=0; i<n; i++) {
        unordered_map<char, int>::iterator it = table.find(str[i]);   
        if (it == table.end()) {
            table.insert(make_pair(str[i], 1));
        } else {
            it->second = it->second+1;
        }
    }
    vector<pair<char, int> > heap;
    for (unordered_map<char, int>::iterator it=table.begin(); it!=table.end(); it++)
        heap.push_back(*it);
    sort(heap.begin(), heap.end(), comp);
    for (int i=0; i<n; i++)
        str[i] = '\0';
    for (int i=0; i<d; i++) {
        pair<char, int> x = heap.back();
        heap.pop_back();
        int p = i;
        while (str[p] != '\0')
            p++;
        for (int k=0; k<x.second; k++) {
            if (p+d*k >= n) {
                cout << "Cannot be rearranged";
                exit(0);
            }
            str[p+d*k] = x.first;
        }
    }
    
}

int main() {
    char str[] = "aabbcc";
    int k = 3;
    cout<<str<<endl;
    rearrangeKDist(str, k);
    cout<<str<<endl;
    return 0;
}
