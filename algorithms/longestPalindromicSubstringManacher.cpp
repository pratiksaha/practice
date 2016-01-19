//Manacher’s Algorithm to find longest palindromic substring
#include<bits/stdc++.h>
using namespace std;
 
void longestPalindromicSubstringManacher(char *text) {
    int N = strlen(text);
    if(N == 0)
        return;
    N = 2*N + 1;
    int L[N]; //LPS Length Array
    L[0] = 0;
    L[1] = 1;
    int C = 1; //centerPosition 
    int R = 2; //centerRightPosition
    int i = 0; //currentRightPosition
    int iMirror; //currentLeftPosition
    int maxLPSLength = 0;
    int maxLPSCenterPosition = 0;
    int start = -1;
    int end = -1;
    int diff = -1;
    for (i=2; i<N; i++)  {
        iMirror  = 2*C-i; //get currentLeftPosition iMirror for currentRightPosition i
        L[i] = 0;
        diff = R - i;
        if(diff > 0) //if currentRightPosition i is within centerRightPosition R
            L[i] = min(L[iMirror], diff);
        while ( ( (i+L[i])<N && (i-L[i])>0 ) &&  ( ((i+L[i]+1)%2==0) || (text[(i+L[i]+1)/2]==text[(i-L[i]-1)/2]) ) )
            L[i]++; //attempt to expand palindrome centered at currentRightPosition i
 
        if(L[i] > maxLPSLength) { //track maxLPSLength
            maxLPSLength = L[i];
            maxLPSCenterPosition = i;
        }
        if (i + L[i] > R) { //expand beyond centerRightPosition R & adjust centerPosition C based on expanded palindrome if palindrome centered at currentRightPosition i 
            C = i;
            R = i + L[i];
        }
    }
    start = (maxLPSCenterPosition - maxLPSLength)/2;
    end = start + maxLPSLength - 1;
    cout<<"LPS of string "<<text<<" is ";
    for (i=start; i<=end; i++)
        cout<<text[i];
    cout<<endl;
}
 
int main(int argc, char *argv[]) {
    char text[100];
    strcpy(text, "babcbabcbaccba");
    longestPalindromicSubstringManacher(text);
    strcpy(text, "abaaba");
    longestPalindromicSubstringManacher(text);
    strcpy(text, "abababa");
    longestPalindromicSubstringManacher(text);
    strcpy(text, "abcbabcbabcba");
    longestPalindromicSubstringManacher(text);
    strcpy(text, "caba");
    longestPalindromicSubstringManacher(text);
    strcpy(text, "abacdfgdcaba");
    longestPalindromicSubstringManacher(text);
    strcpy(text, "abacdfgdcabba");
    longestPalindromicSubstringManacher(text);
    strcpy(text, "abacdedcaba");
    longestPalindromicSubstringManacher(text);
    return 0;
}
