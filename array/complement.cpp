//to print 1's and 2's complement of a binary number
#include <bits/stdc++.h>
using namespace std;

char flip(char c) {
    return (c == '0')? '1': '0';
}

void complement(string bin) {
    int n = bin.length();
    int i;
    string ones, twos;
    ones = twos = "";
    for (i=0; i<n; i++)
        ones += flip(bin[i]);
    twos = ones;
    for (i=n-1; i>=0; i--) {
        if (ones[i] == '1') {
            twos[i] = '0';
        } else {
            twos[i] = '1';
            break;
        }
    }
    if (i==-1)
        twos = '1' + twos;
    cout<<"For "<<bin<<" 1's complement is "<<ones<<" and 2's complement is "<<twos<<endl;
}

int main() {
    string bin = "1100";
    complement(bin);
    return 0;
}
