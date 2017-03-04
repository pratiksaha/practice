//to remove duplicates
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &vect) {
    unordered_set<int> s(vect.begin(), vect.end());
    vect.assign(s.begin(), s.end());
}

int main() {
    vector<int> vect{3, 5, 7, 2, 2, 5, 7, 7};
    removeDuplicates(vect);
    for (int i=0; i<vect.size(); i++)
        cout<<" "<<vect[i];
    cout<<endl;
    return 0;
}
