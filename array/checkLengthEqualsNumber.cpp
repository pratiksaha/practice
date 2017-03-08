//to check if size of string is appended at the end correctly or not
#include<bits/stdc++.h>
using namespace std;

bool checkLengthEqualsNumber(string str) {
    int n = str.length();
    int num = 0, x = 1, i = n-1;
    for (i=n-1; i>=0; i--) {
        if ('0' <= str[i] &&  str[i]  <= '9') {
            num = (str[i] - '0')*x + num;
            x = x * 10;
        } else {
            break;
        }
    }
    return num == i+1;
}

int main() {
    string str = "pratiksaha10";
    checkLengthEqualsNumber(str) ? cout<<"Yes\n" : cout<<"No\n";
    return 0;
}
