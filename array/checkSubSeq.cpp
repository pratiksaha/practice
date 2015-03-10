//to check if a string is subsequence of another string
#include<iostream>
#include<cstring>
using namespace std;

bool checkSubSeq(char *str1, char *str2) {
    int i, j, m, n;
    m = strlen(str1);
    n = strlen(str2);
    j = 0;
    for (i=0; j<m && i<n; i++)
        if (str1[j] == str2[i])
            j++;
    return (j==m); //if all chars of str1 were found in str2
}

int main() {
    char a[] = "rksh";
    char b[] = "tos";
    char c[] = "pratiksaha";
    cout<<a<<" is"<<(checkSubSeq(a,c)?"":" not")<<" a subsequence of "<<c<<endl;
    cout<<b<<" is"<<(checkSubSeq(b,c)?"":" not")<<" a subsequence of "<<c<<endl;
    return 0;
}
