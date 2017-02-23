//to find all distinct subsets of given set
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
using namespace std;
 
vector<string> split(const string &s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim))
        elems.push_back(item);
    return elems;
}
 
void distinctSubsets(int arr[], int n) {
    vector<string> list;
    for (int i = 0; i < (int) pow(2, n); i++) {
        string subset = "";
        for (int j = 0; j < n; j++)
            if ((i & (1 << j)) != 0)
                subset += to_string(arr[j]) + "|";
        if (find(list.begin(), list.end(), subset) == list.end())
            list.push_back(subset);
    }
    for (vector<string>::iterator it = list.begin(); it != list.end(); it++) {
        string subset = *it;
        vector<string> arr = split(subset, '|');
        for (vector<string>::iterator jt = arr.begin(); jt != arr.end(); jt++)
            cout<<" "<<*jt;
        cout<<endl;
    }
}
 
int main() {
    int arr[] = { 10, 12, 12 };
    int n = sizeof(arr)/sizeof(arr[0]);
    distinctSubsets(arr, n);
    return 0;
}
