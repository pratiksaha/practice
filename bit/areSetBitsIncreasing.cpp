//to check if counts of consecutive 1s are increasing order.
#include<bits/stdc++.h>
using namespace std;

bool areSetBitsIncreasing(int n) {
    int prev_count = INT_MAX;
    while (n > 0) {
        while (n > 0 && n % 2 == 0)
            n = n/2;
        int curr_count = 1;
        while (n > 0 && n % 2 == 1) {
            n = n/2;
            curr_count++;
        }
        if (curr_count >= prev_count)
            return false;
        prev_count = curr_count;
    }
    return true;
}

int main() {
    int n = 10;
    cout<<"For "<<n<<" set bits are"<<(areSetBitsIncreasing(n)? " " : " not ")<<"increasing\n";
    n = 183;
    cout<<"For "<<n<<" set bits are"<<(areSetBitsIncreasing(n)? " " : " not ")<<"increasing\n";
    return 0;
}
