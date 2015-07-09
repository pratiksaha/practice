//segregate alphabets and digits
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

void cycleLeader( char* str, int shift, int len) {
    for (int i=1; i<len; i *= 3 ) {
        int j = i;
        char item = str[j+shift];
        do {
            if (j&1)
                j = len/2 + j/2;
            else
                j /= 2;
            swap(str[j+shift], item);
        } while (j!=i);
    }
}

void segregateAlphaDig(char* str) {
    int lenRemaining = strlen(str);
    int shift = 0;
    while (lenRemaining) {
        int k = 0;
        while (pow(3, k)+1 <= lenRemaining)
            k++;
        int lenFirst = pow(3, k-1)+1;
        lenRemaining -= lenFirst;
        cycleLeader(str, shift, lenFirst);
        reverse(str+shift/2, str+shift);
        reverse(str+shift, str+shift+lenFirst/2);
        reverse(str+shift/2, str+shift+lenFirst/2);
        shift += lenFirst;
    }
}

int main() {
    char str[] = "a1b2c3d4e5f6g7";
    cout<<str<<endl;
    segregateAlphaDig( str);
    cout<<str<<endl;
    return 0;
}
