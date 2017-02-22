//to find three element from different three arrays such that that a + b + c is equal to given sum
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
using namespace std;
 
bool findTripletSum(int a1[], int a2[], int a3[], int n1, int n2, int n3, int sum) {
    unordered_set <int> s;
    for (int i=0; i<n1; i++)
        s.insert(a1[i]);
    for (int i=0; i<n2; i++) {
        for (int j=0; j<n3; j++) {
            if (s.find(sum - a2[i] - a3[j]) != s.end())
                return true;
        }
    }
    return false;
}
 
int main() {
    int a1[] = { 1 , 2 , 3 , 4 , 5 };
    int a2[] = { 2 , 3 , 6 , 1 , 2 };
    int a3[] = { 3 , 2 , 4 , 5 , 6 };
    int sum = 9;
    int n1 = sizeof(a1)/sizeof(a1[0]);
    int n2 = sizeof(a2)/sizeof(a2[0]);
    int n3 = sizeof(a3)/sizeof(a3[0]);
    cout<<"For sum = "<<sum<<" there is "<<(findTripletSum(a1, a2, a3, n1, n2, n3, sum) ? "a" : "no")<<" triplet\n";
    return 0;
}
