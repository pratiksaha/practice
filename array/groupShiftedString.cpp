//to print groups of shifted strings together
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
using namespace std;
#define ALPHA 26;

string getDiffString(string str){
    string shift = "";
    for (int i = 1; i < str.length(); i++) {
        int dif = str[i] - str[i-1];
        if (dif < 0)
            dif += ALPHA;
        shift += (dif + 'a');
    }
    return shift;
}

void groupShiftedString(string str[], int n) {
    unordered_map<string, vector<int>> hash;
    for (int i = 0; i < n; i++) {
        string diffStr = getDiffString(str[i]);
        hash[diffStr].push_back(i);
    }
    for (unordered_map<string, vector<int>>::iterator it=hash.begin(); it != hash.end(); it++) {
        vector<int> v = it->second;
        for (int i = 0; i < v.size(); i++)
            cout<<" "<<str[v[i]];
        cout<<endl;
    }
}

int main() {
    string str[] = {"acd", "dfg", "wyz", "yab", "mop", "bdfh", "a", "x", "moqs"};
    int n = sizeof(str)/sizeof(str[0]);
    groupShiftedString(str, n);
    return 0;
}
