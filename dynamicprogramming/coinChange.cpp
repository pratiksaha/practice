//Coin Change Problem
#include<iostream>
#include<cstring>
using namespace std;
 
int count(int coins[], int size, int value ) {
    int table[value+1];//table[i] = no of sols for value i
    memset(table, 0, sizeof(table));
    table[0] = 1;
    for(int i=0; i<size; i++)
        for(int j=coins[i]; j<=value; j++)
            table[j] += table[j-coins[i]];
    return table[value];
}

int main() {
    int arr[] = {1, 2, 3};
    int N = 4;
    cout<<count(arr, sizeof(arr)/sizeof(arr[0]), N)<<endl;
    return 0;
}
