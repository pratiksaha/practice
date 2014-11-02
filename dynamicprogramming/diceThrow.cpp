//Dice throw problem
#include<iostream>
#include<cstring>
using namespace std;

int findWays(int faces, int dices, int sum) {
    if (faces*dices <= sum) //sum is very high
        return (faces*dices == sum);
    if (dices >= sum) //sum is very low
        return (dices == sum);

    int table[dices+1][sum+1]; //table[i][j] = no of ways to reach j using i dices
    memset(table, 0, sizeof(table));
    int i,j,k;
    for (j=1; j<=faces && j<=sum; j++)
        table[1][j] = 1;

    for (i=2; i<=dices; i++)
        for (j=1; j<=sum; j++)
            for (k=1; k<=faces && k<j; k++)
                table[i][j] += table[i-1][j-k];
    
    return table[dices][sum];
}

int main() {
    cout<<"No of ways to reach 1 with 2 dices of 4 faces each = "<<findWays(4, 2, 1)<<endl;
    cout<<"No of ways to reach 3 with 2 dices of 2 faces each = "<<findWays(2, 2, 3)<<endl;
    cout<<"No of ways to reach 8 with 3 dices of 6 faces each = "<<findWays(6, 3, 8)<<endl;
    cout<<"No of ways to reach 5 with 2 dices of 4 faces each = "<<findWays(4, 2, 5)<<endl;
    cout<<"No of ways to reach 5 with 3 dices of 4 faces each = "<<findWays(4, 3, 5)<<endl;
    return 0;
}
