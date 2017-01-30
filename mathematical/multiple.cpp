#include<bits/stdc++.h>
using namespace std;

int countMultiplesOf3Or7OrBoth(int n) {
   return n/3 + n/7 -n/21;
}

bool isMultipleOf4(long long n) {
    if (n==0)
        return true;
    return (((n>>2)<<2) == n);
}

int main(){
    int n;
    n = 25;
    cout<<"No of multiples of 3 or 7 or both is "<<countMultiplesOf3Or7OrBoth(n)<<endl;
    for(int i =0; i<n; i++) {
        cout<<i<<" is"<<(isMultipleOf4(i)? " " : " not ")<<"a multiple of 4\n";
    }
    return 0;
}
