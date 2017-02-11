//to convert n into negative base form
#include <bits/stdc++.h>
using namespace std;

string toString(int n) {
    string str;
    stringstream ss;
    ss << n;
    ss >> str;
    return str;
}

string convNegativeBase(int n, int negBase) {
    if (n == 0)
        return "0";
    string converted = "";
    while (n != 0) {
        int remainder = n % negBase;
        n /= negBase;
        if (remainder < 0) {
            remainder += (-negBase);
            n += 1;
        }
        converted = toString(remainder) + converted;
    }
    return converted;
}
 
int main() {
    int n = 13;
    int negBase = -2;
    cout<<n<<" in negative base "<<negBase<<" is "<<convNegativeBase(n, negBase)<<endl;
    return 0;
}
