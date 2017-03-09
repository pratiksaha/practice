//queries for same characters in a repeated string
#include<bits/stdc++.h>
using namespace std;

void queryCharInRepeatedString(char s[], int i, int j) {
    int n = strlen(s);
    i %= n;
    j %= n;
    (s[i]==s[j])? cout<<"Yes"<<endl : cout<<"No"<<endl;
}

int main() {
    char X[] = "pratiksaha";
    queryCharInRepeatedString(X, 0, 10);
    queryCharInRepeatedString(X, 2, 7);
    queryCharInRepeatedString(X, 6, 15);
    return 0;
}
