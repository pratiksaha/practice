//interleaving
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

void printInterleaves(char *str1, char *str2, char *str, int m, int n, int i) {
    if (m==0 && n ==0) {
        cout<<" "<<str;
    }
    if (m != 0) {
        str[i] = str1[0];
        printInterleaves(str1 + 1, str2, str, m-1, n, i+1);
    }
    if (n != 0) {
        str[i] = str2[0];
        printInterleaves(str1, str2+1, str, m, n-1, i+1);
    }
}

void printInterleaves(char *str1, char *str2) { //print interleavings of str1 and str2
    int m = strlen(str1);
    int n = strlen(str2);
    char *str= (char*)malloc((m+n+1)*sizeof(char));
    str[m+n] = '\0';
    cout<<"All strings formed by interleaving "<<str1<<" & "<<str2<<" :";
    printInterleaves(str1, str2, str, m, n, 0);
    cout<<endl;
    free(str); 
}

bool checkInterleaved (char *str1, char *str2, char *str) { //check if str is an interleaving of str1 & str2 (only for distinct)
    while (*str != 0) {
        if (*str1 == *str)
            str1++;
        else if (*str2 == *str)
            str2++;
        else
            return false;
        str++;
    }
    if (*str1 || *str2)
        return false;
    else
        return true;
}

int main() {
    char *str1 = "AB";
    char *str2 = "CD";
    char *str3 = "CADB";
    char *str4 = "DBAC";
    printInterleaves(str1, str2);
    cout<<str3<<(checkInterleaved(str1, str2, str3) ? " is " : " is not ")<<"interleaved of "<<str1<<" & "<<str2<<endl;
    cout<<str4<<(checkInterleaved(str1, str2, str4) ? " is " : " is not ")<<"interleaved of "<<str1<<" & "<<str2<<endl;
    return 0;
}
