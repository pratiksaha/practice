//to check if it is possible to reach (a, b) from (x, y).
#include<bits/stdc++.h>
using namespace std;

int gcd(int i, int j) {
    if (i == j)
        return i;
    if (i > j)
        return gcd(i - j, j);
    return gcd(i, j - i);
}

bool checkPossibleMove(int x, int y, int a, int b) {
    x = abs(x), y = abs(y), a = abs(a), b = abs(b);
    return (gcd(x, y) == gcd(a, b));
}

int main() {
    int x = 35, y = 15;
    int a = 20, b = 25;
    cout<<(checkPossibleMove(x, y, a, b)?"Yes":"No")<<endl;
    return 0;
}
