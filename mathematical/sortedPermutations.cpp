//Print all permutations of a string in sorted order.
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

void swap (char* a, char* b) {
    char t = *a;
    *a = *b;
    *b = t;
}

void reverse(char str[], int l, int h) {
    while(l<h) {
        swap(&str[l], &str[h]);
        l++;
        h--;
    }
}
 
//Finds the index of the smallest character which is greater than the key and is present in str[l..h]
int findInd(char str[], char key, int l, int h) {
    int ind = l;
    for (int i = l+1; i <= h; i++)
        if (str[i] > key && str[i] < str[ind])
            ind = i; 
    return ind;
}
 
void sortedPermutations (char str[])
{
    int n = strlen(str);
 
    sort(str, str+n);
    bool isFinished = false;
    while ( !isFinished ) {
        cout<<str<<endl;
 
        // Find the rightmost character which is smaller than its next character
        int i;
        for ( i = n-2; i>=0; i-- )
            if (str[i] < str[i+1])
                break;
 
        // If there is no such chracter, all are sorted in decreasing order, means we just printed the last permutation and we are done.
        if(i == -1)
            isFinished = true;
        else {
            //find the character which is the smallest character greater than the given character
            int ind = findInd( str, str[i], i+1, n-1 );
            swap( &str[i], &str[ind] );
            reverse( str, i+1, n-1 ); // reverse the string on right
        }
    }
}
 
int main()
{
    char str[] = "CDAB";
    sortedPermutations( str );
    return 0;
}
