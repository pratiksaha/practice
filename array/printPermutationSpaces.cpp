//to print permutations of a given string with spaces
#include<iostream>
#include<cstring>
using namespace std;

void printPermutationSpacesUtil(char str[], char buff[], int i, int j, int n) {
    if (i==n) {
        buff[j] = '\0';
        cout<<buff<<endl;
    } else {
        buff[j] = str[i]; //put the character
        printPermutationSpacesUtil(str, buff, i+1, j+1, n);
        buff[j] = ' ';//put a space followed by next character
        buff[j+1] = str[i];
        printPermutationSpacesUtil(str, buff, i+1, j+2, n);
    }
}

void printPermutationSpaces(char *str) { //Time: O(n*(2^n)) Space: O(n)
    int n = strlen(str);
    char buf[2*n]; //2n-1 characters and 1 string terminator
    buf[0] = str[0]; //first char will be always at first pos
    printPermutationSpacesUtil(str, buf, 1, 1, n);
}

int main() {
    char *str = "ABCDE";
    printPermutationSpaces(str);
    return 0;
}
