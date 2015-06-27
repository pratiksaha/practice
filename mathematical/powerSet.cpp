//power set : revisit
#include <iostream>
#include<cmath>
using namespace std;
 
void powerSet(char *set, int n) {
    int size = pow(2, n);
    for (int i=0; i<size; i++) {
        for (int j=0; j<n; j++) {
            if (i & (1<<j))
                cout<<" "<<set[j];
        }
        cout<<endl;
    }
}

int main() {
    char set[] = {'a','b','c'};
    powerSet(set, sizeof(set)/sizeof(set[0]));
    return 0;
}
