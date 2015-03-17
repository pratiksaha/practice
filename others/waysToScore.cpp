// to count number of possible ways a given score can be reached in a game where a move can earn 3 or 5 or 10
#include<iostream>
#include<cstring>
using namespace std;

int waysToScore(int n) {
    int table[n+1]; // table[i] = count of solns for value i
    memset(table, 0, sizeof(table));
    table[0] = 1;
    int i;
    for (i=3; i<=n; i++)
       table[i] += table[i-3];
    for (i=5; i<=n; i++)
       table[i] += table[i-5];
    for (i=10; i<=n; i++)
       table[i] += table[i-10];
    return table[n];
}

int main() {
    cout<<"Count for "<<20<<" is "<<waysToScore(20)<<endl;
    cout<<"Count for "<<13<<" is "<<waysToScore(13)<<endl;
    return 0;
}
