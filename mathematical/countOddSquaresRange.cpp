//to count number of odd squares in given range
#include<bits/stdc++.h>
using namespace std;
 
int countOddSquaresRange(int n, int m) {
   return (int)pow(m,0.5) - (int)pow(n-1,0.5);
}

int main() {
    int n = 5, m = 100;
    cout<<"Count is "<<countOddSquaresRange(n, m)<<endl;
    return 0;
}
