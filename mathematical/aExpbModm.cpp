//(a^b) mod m
#include<bits/stdc++.h>
using namespace std;
 
unsigned int aModM(string s, unsigned int mod) {
    unsigned int number = 0;
    for (unsigned int i = 0; i < s.length(); i++) {
        number = (number*10 + (s[i] - '0'));
        number %= mod;
    }
    return number;
}
 
unsigned int aExpbModm(string &a, unsigned int b, unsigned int m) {
    unsigned int ans = aModM(a, m);
    unsigned int mul = ans;
    for (unsigned int i=1; i<b; i++)
        ans = (ans*mul) % m;
    return ans;
}

int main() {
    string a = "987584345091051645734583954832576";
    unsigned int b=3, m=11;
    cout<<"( "<<a<<" ^ "<<b<<" ) mod "<<m<<" = "<<aExpbModm(a, b, m)<<endl;
    return 0;
}
