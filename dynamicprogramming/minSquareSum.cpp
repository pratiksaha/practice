//to find minimum number of squares whose sum is equal to a given number
#include<iostream>
using namespace std;

int minSquareSum(int n) {
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i <= n; i++) {
        dp[i] = i; //max value is i as i can always be represented as 1*1 + 1*1 + ...
        for (int x=1; x<=i; x++) {
            int temp = x*x;
            if (temp>i)
                break;
            else
                dp[i] = min(dp[i], 1+dp[i-temp]);
        }
    }
    return dp[n];
}

int main() {
    int n = 6;
    cout<<"Minimum no of squares whose sum is "<<n<<" = "<<minSquareSum(6)<<endl;
    return 0;
}
