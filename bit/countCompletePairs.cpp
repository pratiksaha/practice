//to find count of complete pairs
#include<bits/stdc++.h>
using namespace std;

int countCompletePairs(string set1[], string set2[], int n, int m) {
    int result = 0;
    int con_s1[n], con_s2[m];
    for (int i=0; i<n; i++) {
        con_s1[i] = 0;
        for (int j=0; j<set1[i].length(); j++)
            con_s1[i] = con_s1[i] | (1<<(set1[i][j]-'a'));
    }
    for (int i=0; i<m; i++) {
        con_s2[i] = 0;
        for (int j=0; j<set2[i].length(); j++)
            con_s2[i] = con_s2[i]|(1<<(set2[i][j]-'a'));
    }
    long long complete = (1<<26) - 1;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if ((con_s1[i] | con_s2[j]) == complete)
                result++;
    return result;
}
 
int main() {
    string set1[] = { "abcdefgh", "geeksforgeeks", "lmnopqrst", "abc" };
    string set2[] = { "ijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz", "defghijklmnopqrstuvwxyz" };
    int n = sizeof(set1)/sizeof(set1[0]);
    int m = sizeof(set2)/sizeof(set2[0]);
    cout<<"Count of complete pairs : "<<countCompletePairs(set1, set2, n, m)<<endl;
    return 0;
}
