//to find first repeating no
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<iostream>
#include<unordered_set>
using namespace std;

void firstRepeating(int *a, int n) {
    unordered_set<int> hash;
    bool found = false;
    int res;
    for (int i=0; i<n; i++) {
        unordered_set<int>::iterator it;
        it = hash.find(*(a+i));
        if (it != hash.end()) {
            found = true;
            res = *(a+i);
            break;
        } else {
            hash.insert(*(a+i));
        }
    }
    if (found)
        cout<<"First repeating no is "<<res<<endl;
    else
        cout<<"No repeating nos\n";
}

int main() {
    int a1[] = {78, 45, 56, 12, 45, 67};
    int a2[] = {78, 45, 56, 12, 67};
    firstRepeating(a1, sizeof(a1)/sizeof(a1[0]));
    firstRepeating(a2, sizeof(a2)/sizeof(a2[0]));
    return 0;
}
