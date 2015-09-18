//to find number of ways to wear unique caps
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

vector<int> capList[101];
int dp[1025][101];
int allmask;

long long int countUniqueCaps(int mask, int i) {
    if (mask == allmask) //1 way if all persons are wearing a cap
        return 1;
    if (i > 100) //0 way if not everyone is wearing a cap and there are no more caps left to process
        return 0;
    if (dp[mask][i] != -1)
        return dp[mask][i];
    long long int ways = countUniqueCaps(mask, i+1);
    int size = capList[i].size();
    for (int j = 0; j < size; j++) { //assign one by one ith cap to all the possible persons and recur for remaining caps
        if (mask & (1 << capList[i][j])) //already wearing a cap
            continue;
        else //assign cap and recur 
            ways += countUniqueCaps(mask | (1 << capList[i][j]), i+1);
    }
    dp[mask][i] = ways;
    return dp[mask][i];
}

int main() { 
    int n = 3;
    capList[5].push_back(0);
    capList[100].push_back(0);
    capList[1].push_back(0);
    capList[2].push_back(1);
    capList[5].push_back(2);
    capList[100].push_back(2);
    allmask = (1 << n) - 1;
    memset(dp, -1, sizeof(dp));
    cout<<countUniqueCaps(0, 1)<<endl;
    return 0;
}
