//check if a no is harshad
#include<bits/stdc++.h>
using namespace std;

bool harshadNumber(int n) {
    int sum = 0;
    for (int temp=n; temp>0; temp /= 10)
        sum += temp % 10;
    return (n%sum == 0);
}

int main() {
    int n;
    n = 12;
    cout<<n<<" is"<<(harshadNumber(n)? " " : " not ")<<"a harshad no\n";
    n = 15;
    cout<<n<<" is"<<(harshadNumber(n)? " " : " not ")<<"a harshad no\n";
    return 0;
}
