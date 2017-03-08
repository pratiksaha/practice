//generate all binary strings of size k without consecutive 1's 
#include<bits/stdc++.h>
using namespace std ;

void generateBinaryStringsKWithoutConsecutive1(int K, char str[], int n) {
    if (n == K) {
        str[n] = '\0';
        cout<<str<<endl;
        return ;
    }
    if (str[n-1] == '1') {
        str[n] = '0';
        generateBinaryStringsKWithoutConsecutive1 (K , str , n+1);
    }
    if (str[n-1] == '0') {
        str[n] = '0';
        generateBinaryStringsKWithoutConsecutive1(K, str, n+1);
        str[n] = '1';
        generateBinaryStringsKWithoutConsecutive1(K, str, n+1);
    }
}

void generateBinaryStringsKWithoutConsecutive1(int K) {
    if (K > 0) {
        char str[K];
        str[0] = '0';
        generateBinaryStringsKWithoutConsecutive1(K, str, 1);
        str[0] = '1';
        generateBinaryStringsKWithoutConsecutive1(K, str, 1);
    }
}

int main() {
    int K = 3;
    generateBinaryStringsKWithoutConsecutive1(K);
    return 0;
}
