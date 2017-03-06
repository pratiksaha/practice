//to rearrange a given list such that it consists of alternating minimum maximum elements
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
using namespace std;

void alternateSortMinMax(list<int>& inp) {
    inp.sort();
    list<int>::iterator it = inp.begin();
    it++;
    for (int i=1; i<(inp.size() + 1)/2; i++) {
        int val = inp.back();
        inp.pop_back();
        inp.insert(it, val);
        ++it;
    }
}
 
int main() {
    list<int> inp({ 1, 3, 8, 2, 7, 5, 6, 4 });
    alternateSortMinMax(inp);
    for (list<int>::iterator it = inp.begin(); it != inp.end(); it++)
        cout<<" "<<*it;
    cout<<endl;
    return 0;
}
