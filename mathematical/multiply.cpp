//multiplication of two nos
#include<bits/stdc++.h>
using namespace std;

int multiply(int n, int m) {  
    int ans = 0, count = 0;
    while (m) {
        if (m % 2 == 1)              
            ans += n << count;
        count++;
        m /= 2;
    }
    return ans;
}
 
int main() {
    int n = 20 , m = 13;
    cout<<n<<" * "<<m<<" = "<<multiply(n, m)<<endl;
    return 0;
}
