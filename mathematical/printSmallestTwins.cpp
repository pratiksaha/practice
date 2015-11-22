//to find the smallest twin in given range
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
 
void printSmallestTwins(int low, int high) {
    bool prime[high+1];
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int p=2; p<=floor(sqrt(high))+1; p++)
        if (prime[p])
            for (int i=p*2; i<=high; i += p)
                prime[i] = false;
    for (int i=low; i<=high; i++) {
        if (prime[i] && prime[i+2]) {
            cout<<"Smallest twins in range ["<<low<<","<<high<<"] is ("<<i<<","<<i+2<<")"<<endl;
            break;
        }
    }
}

int main() {
    printSmallestTwins(10, 100);
    return 0;
}
