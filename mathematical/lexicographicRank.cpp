//Finding lexicographic rank of string in linear time
#include<iostream>
#include<cstring>
using namespace std;
#define MAX_CHAR 256
 
long int fact(int n) {
    return (n <= 1)? 1 :n * fact(n-1);
}
 
// Construct a count array where value at every index contains count of smaller characters in whole string This is O(1)
void populateAndIncreaseCount(int* count, char* str) {
    int i; 
    int n =strlen(str);
    for( i = 0; i<n; i++ )
        count[str[i]]++; //Count no of each character in the string 
 
    for( i = 1; i<MAX_CHAR ; i++ )//Count no of smaller characters than each character
        count[i] += count[i-1];
}
 
// Removes a character ch from count[] array constructed by populateAndIncreaseCount() This is O(1)
void updatecount(int* count, char ch) {
    int i;
    for( i=ch; i<MAX_CHAR; i++ )
        count[i]--;
}

int findRank(char* str)
{
    int len = strlen(str);
    long int mul = fact(len);
    int rank = 1, i;
    int count[MAX_CHAR] = {0};  // all elements of count[] are initialized with 0
 
    // Populate the count array such that count[i] contains count of characters which are present in str and are smaller than i
    populateAndIncreaseCount( count, str );
 
    for (i = 0; i < len; ++i) {
        mul /= len - i;
 
        // count number of chars smaller than str[i] fron str[i+1] to str[len-1]
        rank += count[ str[i] - 1] * mul;
 
        // Reduce count of characters greater than str[i]
        updatecount(count, str[i]);
    }
 
    return rank;
}

int main()
{
    char str[] = "abedc";
    cout<<"Lexicographic Rank of "<<str<<" is "<<findRank(str)<<endl;
    return 0;
}
