//check if all bits can be made same by single flip
#include <bits/stdc++.h>
using namespace std;
 
bool isOneFlipSame(string str) {
    int sum = 0;
    int n = str.length();
    for (int i=0; i<n; i++)
        sum += str[i] - '0';
    return (sum == n-1 || sum == 1);
}

int main() {
    string s = "101111111111";
    cout<<s<<" is"<<(isOneFlipSame(s)? " " : " not ")<<"one flip away from being with all bits same\n";
    s = "1000000000";
    cout<<s<<" is"<<(isOneFlipSame(s)? " " : " not ")<<"one flip away from being with all bits same\n";
    s = "1011111100111";
    cout<<s<<" is"<<(isOneFlipSame(s)? " " : " not ")<<"one flip away from being with all bits same\n";
    return 0;
}
