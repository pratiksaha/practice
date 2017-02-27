//to count pairs with distance equal to english alphabet distance
#include<bits/stdc++.h>
using namespace std;
#define MAX_CHAR 26
 
int countPairsWithEngAlphDistance(string str) {
    int result = 0;
    int n = str.length();
    for (int i=0; i<n ; i++)
        for (int j=1; (i+j)<n && j<=MAX_CHAR; j++)
            if ((abs(str[i+j] - str[i]) == j))
                result++;
    return result;
}
 
int main() {
    string str = "geeksforgeeks" ;
    cout<<countPairsWithEngAlphDistance(str)<<endl;
    return 0;
}
