//To count the possible decodings of a number
//For eg
//Input: digits[] = "1234"
//Output: 3
//The possible decodings are "ABCD", "LCD", "AWD"
#include<iostream>
#include<cstring>
using namespace std;

int countDecoding(char *digits)
{
    int n = strlen(digits);
    int count[n+1]; // A table to store results of subproblems
    count[0] = 1;
    count[1] = 1;
    //count[i] stores the no of possibilities with digits upto digits[i-1] (i>0)
    
    for (int i = 2; i <= n; i++) {
        count[i] = 0;        
        if (digits[i-1] > '0') // If the last digit is not 0, then last digit must add to the number of words
            count[i] += count[i-1];
        if (digits[i-2] < '2' || (digits[i-2] == '2' && digits[i-1] < '7') ) // If second last digit is smaller than 2 and last digit is smaller than 7, then last two digits form a valid character
            count[i] += count[i-2];
    }
    return count[n];
}

int main()
{
    char digits[] = "1234";
    cout<<"No of decodings = "<<countDecoding(digits)<<endl;
    return 0;
}
