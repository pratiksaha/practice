//to print first n numbers with exactly two set bits
#include<bits/stdc++.h>
using namespace std;

void twoSetBitNumber(int n) {
    cout<<n<<" nos with 2 set bits :";
    int x = 1;
    while (n > 0) {
        int y = 0;
        while (y < x) {
            cout<<" "<<(1<<x)+(1<<y);
            n--;
            if (n == 0) {
                cout<<endl;
                return;
            }
            y++;
        }
        x++;
    }
    cout<<endl;
}
 
int main() {
    twoSetBitNumber(4);
    return 0;
}
