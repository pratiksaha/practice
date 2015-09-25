//to find minimum of coins to make a given change V TODO: print soln
#include<iostream>
#include<climits>
using namespace std;

int minCoins(int coins[], int n, int V) {
    int table[V+1];
    table[0] = 0;
    for (int i=1; i<=V; i++)
        table[i] = INT_MAX;
    for (int i=1; i<=V; i++) {
        for (int j=0; j<n; j++) { //go through all coins smaller than i
            if (coins[j] <= i) {
                int sub_res = table[i-coins[j]];
                if (sub_res != INT_MAX && sub_res + 1 < table[i])
                    table[i] = sub_res + 1;
            }
        }
    }
    return table[V];
}

int main() {
    int coins[] =  {9, 6, 5, 1};
    int V = 11;
    cout<<"Minimum coins required to make "<<V<<" is "<<minCoins(coins, sizeof(coins)/sizeof(coins[0]), V)<<endl;
    return 0;
}
