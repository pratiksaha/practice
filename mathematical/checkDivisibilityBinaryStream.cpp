//check divisbility in a binary stream
#include<bits/stdc++.h>
using namespace std;

void checkDivisibilityBinaryStream(int n) {
    cout<<"press any key other than 0 and 1 to terminate\n";
    cout<<"checking divisibility by "<<n<<endl;
    int remainder = 0;
    while (true) {
        int incomingBit;
        cin>>incomingBit;
        if (incomingBit == 1)
            remainder = (remainder * 2 + 1) % n;
        else if (incomingBit == 0)
            remainder = (remainder * 2) % n;
        else
            break;
        if (remainder % n == 0)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
}
 
int main() {
    checkDivisibilityBinaryStream(3);
    return 0;
}
