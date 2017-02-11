//to get Nth character in concatenated decimal string
#include<bits/stdc++.h>
using namespace std;

char getDigit(int N, int d) {
    string str;
    stringstream ss;
    ss << N;
    ss >> str;
    return str[d - 1];
}

char getNthCharConcatenatedDecimalString(int N) {
    int sum = 0, nine = 9;
    int dist = 0, len;
    for (len = 1; ; len++) {
        sum += nine*len;
        dist += nine;
        if (sum >= N) {
            sum -= nine*len;
            dist -= nine;
            N -= sum;
            break;
        }
        nine *= 10;
    }
    int diff = ceil((double)N / len);
    int d = N % len;
    if (d == 0)
        d = len;
    return getDigit(dist + diff, d);
}
 
int main() {
    int N = 251;
    cout<<getNthCharConcatenatedDecimalString(N) << endl;
    return 0;
}
