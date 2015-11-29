//to collect maximum number of coins before hitting a dead end
#include<iostream>
#include<cstring>
using namespace std;
#define R 5
#define C 5

bool isValid(int i, int j) {
    return (i >=0 && i < R && j >=0 && j < C);
}

int collectMaxCoinsBeforeDeadEnd(char arr[R][C],  int i, int j, int dir, int dp[R][C][2]) {
    if (!isValid(i,j) || arr[i][j] == '#')
        return 0;
    if (dp[i][j][dir] != -1)
       return dp[i][j][dir];
    dp[i][j][dir] = (arr[i][j] == 'C')? 1: 0;
    if (dir == 1) //direction is right
        dp[i][j][dir] += max(collectMaxCoinsBeforeDeadEnd(arr, i+1, j, 0, dp), collectMaxCoinsBeforeDeadEnd(arr, i, j+1, 1, dp));
    if (dir == 0) //direction is left
        dp[i][j][dir] += max(collectMaxCoinsBeforeDeadEnd(arr, i+1, j, 1, dp), collectMaxCoinsBeforeDeadEnd(arr, i, j-1, 0, dp));
    return dp[i][j][dir];
}

int collectMaxCoinsBeforeDeadEnd(char arr[R][C]) {
    int dp[R][C][2];
    memset(dp, -1, sizeof dp);
    return collectMaxCoinsBeforeDeadEnd(arr, 0, 0, 1, dp); //initially direction is right and cell is (0,0)
}

int main() {
    char arr[R][C] = { {'E', 'C', 'C', 'C', 'C'},
                       {'C', '#', 'C', '#', 'E'},
                       {'#', 'C', 'C', '#', 'C'},
                       {'C', 'E', 'E', 'C', 'E'},
                       {'C', 'E', '#', 'C', 'E'}
                     };
    cout<<"Maximum number of collected coins before hitting dead end is "<<collectMaxCoinsBeforeDeadEnd(arr)<<endl;
    return 0;
}
