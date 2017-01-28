//kaprekar constant
#include<bits/stdc++.h>
using namespace std;

int kaprekarConstant(int n, int &prev) {
    if (n == 0)
       return 0;
    prev = n;
    int digits[4];
    for (int i=0; i<4; i++) {
       digits[i] = n%10;
       n = n/10;
    }
    sort(digits, digits+4);
    int asc = 0;
    for (int i=0; i<4; i++)
       asc = asc*10 + digits[i];
    sort(digits, digits+4, std::greater<int> ());
    int desc = 0;
    for (int i=0; i<4; i++)
       desc = desc*10 + digits[i];
    int diff = abs(asc - desc);
    if (diff == prev)
        return diff;
    return kaprekarConstant(diff, prev);
}

int kaprekarConstant(int n) {
    int prev = 0;
    return kaprekarConstant(n, prev);
}

int main() {
    cout<<kaprekarConstant(1000)<<endl;
    cout<<kaprekarConstant(1112)<<endl;
    cout<<kaprekarConstant(9812)<<endl;
    return 0;
}
