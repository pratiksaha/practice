//to find the number of ways n can be written as sum of two or more positive integers
#include<bits/stdc++.h>
using namespace std;

int waysToWriteAsSum(int n) {
    int table[n+1];
    memset(table, 0, sizeof(table));
    table[0] = 1;
    for (int i=1; i<n; i++)
        for (int j=i; j<=n; j++)
            table[j] += table[j-i];
    return table[n];
}

int main() {
    int n = 7;
    cout<<"No if ways to write "<<n<<" as sum of two or more positive integers is "<<waysToWriteAsSum(n)<<endl;
    return 0;
}
