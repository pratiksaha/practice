//to count number of ways to group digits under constraints
#include<bits/stdc++.h>
using namespace std;
#define MAX 40

int dp[MAX][9*MAX + 1];
 
int countGroupsUnderConstraints(int position, int previous_sum, int length, char *num) {
    if (position == length)
        return 1;
    if (dp[position][previous_sum] != -1)
        return dp[position][previous_sum];
    dp[position][previous_sum] = 0;
    int res = 0;
    int sum = 0;
    for (int i = position; i < length; i++) {
        sum += (num[i] - '0');
        if (sum >= previous_sum)
           res += countGroupsUnderConstraints(i + 1, sum, length, num);
    }
    dp[position][previous_sum] = res;
    return res;
}
int main() {
    char num[] = "1119";
    int len = strlen(num);
    memset(dp, -1, sizeof(dp));
    cout<<countGroupsUnderConstraints(0, 0, len, num)<<endl;
    return 0;
}
