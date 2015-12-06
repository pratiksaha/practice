//to count number of ways to represent n as sum of four numbers
#include<bits/stdc++.h>
using namespace std;
int dp[5001][5001][5];

int divideNo4parts(int n, int parts, int nextPart) {
    if (parts == 0 && n == 0)
        return 1;
    if (n <= 0 || parts <= 0)
        return 0;
    if (dp[n][nextPart][parts] != -1)
        return dp[n][nextPart][parts];
    int ans = 0;
    for (int i = nextPart; i <= n; i++)
        ans += divideNo4parts(n-i, parts-1, i);
    return (dp[n][nextPart][parts] = ans);
}

int divideNo4parts(int n) {
    memset(dp, -1, sizeof(dp));
    return divideNo4parts(n, 4, 1);
}

int main() {
    int n = 8;
    cout<<"No of ways "<<n<<" can be divided into 4 parts is "<<divideNo4parts(n)<<endl;
    return 0;
}
