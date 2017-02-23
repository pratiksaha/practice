//to find minimum number which divide n to make it a perfect square
#include<bits/stdc++.h>
using namespace std;
 
int minNoToDivideToMakePerfectSquare(int n) {
    int count = 0, ans = 1;
    while (n%2 == 0) {
        count++;
        n /= 2;
    }
    if (count%2)
        ans *= 2;
    for (int i = 3; i <= sqrt(n); i += 2) {
        count = 0;
        while (n%i == 0) {
            count++;
            n /= i;
        }
        if (count%2)
            ans *= i;
    }
    if (n > 2)
        ans *= n;
    return ans;
}
 
int main() {
    int n = 72;
    cout<<"minimum number which divide "<<n<<" to make it a perfect square is "<<minNoToDivideToMakePerfectSquare(n)<<endl;
    return 0;
}
