//Jolly Jumper Sequence
#include<bits/stdc++.h>
using namespace std;

bool jollyJumperSequence(int a[], int n) {
    vector<bool> hash(n, false);
    for (int i=0; i < n-1 ; i++) {
        int d = abs(a[i]-a[i+1]);
        if (d == 0 || d > n-1 || hash[d])
            return false;
        hash[d] = true;
    }
    return true;
}

int main() {
    int a[] = {11, 7, 4, 2, 1, 6};
    int n = sizeof(a)/ sizeof(a[0]);
    cout<<"Given List is"<<(jollyJumperSequence(a, n) ? " " : " not ")<<"a jolly jumper sequence\n";
    return 0;
}
