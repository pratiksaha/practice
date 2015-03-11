//find longest even substring with same sum of digits in left and right half
#include<iostream>
#include<cstring>
using namespace std;
 
void longestSubStrEqHalf(char *str) {
    int n = strlen(str);
    int maxlen = 0, ind = 0, jnd = 0;
    int sum[n][n]; //sum[i][j] = sum of digits from str[i] to str[j]
    for (int i =0; i<n; i++) //fill the diagonal values for substr of length 1
        sum[i][i] = str[i]-'0';
    for (int len=2; len<=n; len++) { //fill entries for substr of length 2 to n
        for (int i=0; i<n-len+1; i++) { //pick i and j for curr substr
            int j = i+len-1;
            int k = len/2;
            sum[i][j] = sum[i][j-k] + sum[j-k+1][j];
            if (len%2 == 0 && sum[i][j-k] == sum[(j-k+1)][j] && len > maxlen) { //if len is even and more than maxlen with same left and right sums
                maxlen = len;
                ind = i;
                jnd = j;
            }
        }
    }
    cout<<"Max even substring with same sum of digits in left and right halves is of size "<<maxlen<<" : ";
    for (int i=ind; i<=jnd; i++)
        cout<<str[i];
    cout<<endl;
}

int main() {
    char str[] = "153803";
    longestSubStrEqHalf(str);
    return 0;
}
