//reversible number
#include<bits/stdc++.h>
using namespace std;

void checkReversible (int n) {
    int rev = 0, rem;
    int flag = n;
    while (flag) {
        rem = flag % 10;
        rev *= 10;
        rev += rem;
        flag /= 10;
    }
    int sum = rev + n;
    while (sum && (rem % 2 != 0)) {
        rem = sum % 10;
        sum /= 10;
    }
 
    if (sum == 0)
        cout<<n<<" is a Reversible Number\n";
    else
        cout<<n<<" is not a Reversible Number\n";
}

void countReversible (int n) {
    int count = 0; 
    for ( int i = 1; i <= n; i++) {
        switch (i % 4) {
            case 0:
            case 2:
                count += 20 * pow( 30, ( i / 2 - 1));
                break;
            case 3:
                count += 100 * pow ( 500, i / 4 );
                break;
            case 1:
                break;
        }
    }
    cout<<"No of reversible digits upto "<<n<<" digits is "<<count<<endl;
}
 
int main() {
    checkReversible(36);
    countReversible(9);
    return 0;
}
