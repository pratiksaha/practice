//to check if one string is a rotation of another
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

bool checkRotation(char *str1, char *str2) {
    int n1 = strlen(str1);
    int n2 = strlen(str2);
    if (n1 != n2)
        return false;
    char *temp = (char *)malloc(sizeof(char)*(2*n1+1));
    temp[0] = '\0';
    strcat(temp, str1);
    strcat(temp, str1);
    char *ptr = strstr(temp, str2); //http://www.cplusplus.com/reference/cstring/strstr/
    free(temp);
    if (ptr)
        return true;
    else
        return false;
}

int main() {
    char *s1 = "AACD";
    char *s2 = "ACDA";
    char *s3 = "ACDD";
    checkRotation(s1, s2) ? cout<<"Strings are rotations of each other\n" : cout<<"Strings are not rotations of each other\n";
    checkRotation(s1, s3) ? cout<<"Strings are rotations of each other\n" : cout<<"Strings are not rotations of each other\n";
    return 0;
}
