//to find all symmetric pairs in a given array of pairs
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<iostream>
#include<unordered_map>
using namespace std;

void findSymmetricPairs(int arr[][2], int n) {
    unordered_map<int, int> hash;
    cout<<"Symmetric Pairs :";
    for (int i=0; i<n; i++) {
        int first = arr[i][0];
        int sec = arr[i][1];
        unordered_map<int, int>::iterator it;
        it = hash.find(sec);
        if (it!=hash.end() && it->second==first)
            cout<<" ("<<sec<<","<<first<<")";        
        else
            hash.insert(make_pair(first,sec));
    }
    cout<<endl;  
}

int main() {
    int arr[5][2];
    arr[0][0] = 11; arr[0][1] = 20;
    arr[1][0] = 30; arr[1][1] = 40;
    arr[2][0] = 5;  arr[2][1] = 10;
    arr[3][0] = 40;  arr[3][1] = 30;
    arr[4][0] = 10;  arr[4][1] = 5;
    findSymmetricPairs(arr, 5);
    return 0;
}
