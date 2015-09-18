//to count non-decreasing numbers with n digits
#include<iostream>
using namespace std;
 
long long int countNonDecreasing(int n) {
    int N = 10;
    long long count = 1;
    for (int i=1; i<=n; i++) { //compute value of N*(N+1)/2*(N+2)/3* ....*(N+n-1)/n
        count *= (N+i-1);
        count /= i;
    }
    return count;
}

int main() {
    int n = 3;
    cout<<"No of non-decreasing nos with "<<n<<" digits is "<<countNonDecreasing(n)<<endl;
    return 0;
}
