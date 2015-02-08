//movde nos to second half
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

void reverse(char* str, int low, int high) { //reverse a string b/w low and high indices
    while (low<high) {
        swap(str[low], str[high]);
        low++;
        high--;
    }
}

void moveEvenEnd(char* str, int shift, int len) {//move even indices to end
    for (int i=1; i<len; i *= 3) {
        int j = i;
        char item = str[j+shift];
        do {
            if (j&1) // odd index
                j = len/2 + j/2;
            else // even index
                j /= 2;
            swap(str[j+shift], item);
        }
        while (j!=i);
    }
}

void moveNumbersToSecondHalf (char* str) {
    int remlen = strlen(str);
    int shift = 0; 
    while (remlen) {
        int k = 0;
        while (pow(3,k)+1<=remlen)
            k++;
        int flen = pow(3,k-1)+1;
        remlen = remlen-flen;
        moveEvenEnd(str, shift, flen);
        reverse(str, shift/2, shift-1);
        reverse(str, shift, shift+flen/2-1);
        reverse(str, shift/2, shift+flen/2-1);
        shift += flen;
    }
}

int main() {
    char str[] = "a1b2c3d4e5f6g7";
    cout<<str<<endl;
    moveNumbersToSecondHalf(str);
    cout<<str<<endl;
    return 0;
}
