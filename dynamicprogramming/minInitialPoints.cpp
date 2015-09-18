// C++ program to find minimum initial points to reach destination
#include<iostream>
#include<cmath>
#define R 3
#define C 3
using namespace std;
 
int minInitialPoints(int points[R][C]) {
    int dp[R][C];
    int m = R, n = C;
    dp[m-1][n-1] = points[m-1][n-1] > 0? 1: abs(points[m-1][n-1]) + 1;
    for (int i=m-2; i>=0; i--)
         dp[i][n-1] = max(dp[i+1][n-1]-points[i][n-1], 1);
    for (int j=n-2; j>=0; j--)
         dp[m-1][j] = max(dp[m-1][j+1]-points[m-1][j], 1);
    for (int i=m-2; i>=0; i--)
        for (int j=n-2; j>=0; j--)
            dp[i][j] = max(min(dp[i+1][j], dp[i][j+1])- points[i][j], 1);
     return dp[0][0];
}

int main() {
    int points[R][C] = {{-2,-3,3},
                        {-5,-10,1},
                        {10,30,-5}};
    cout<<"Minimum Initial Points required is "<<minInitialPoints(points)<<endl;
    return 0;
}
