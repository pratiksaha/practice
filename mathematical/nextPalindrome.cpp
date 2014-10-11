#include<iostream>
#include<stack>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i=0; i < n; i++)
        cout<<arr[i];
    cout<<endl;
}

bool AreAll9s( int* num, int n )
{
    for(int i = 0; i < n; ++i)
        if( num[i] != 9 )
            return false;
    return true;
}

// Returns next palindrome of a given number num[].
void NP (int num[], int n )
{
    int mid = n/2;
    bool leftsmaller = false;
    int i = mid - 1;
    int j = (n % 2)? mid + 1 : mid;
 
   // Initially, ignore the middle same digits
    while (i >= 0 && num[i] == num[j])
        i--,j++;
 
    // Find if the middle digit(s) need to be incremented or not (or copying left side is not sufficient)
    if ( i < 0 || num[i] < num[j])
        leftsmaller = true;
 
    // Copy the mirror of left to right
    while (i >= 0)
    {
        num[j] = num[i];
        j++;
        i--;
    }
 
    // Handle the case where middle digit(s) must be incremented.
    // This part of code is for CASE 1 and CASE 2.2
    if (leftsmaller == true)
    {
        int carry = 1;
        i = mid - 1;
 
        // If there are odd digits, then increment the middle digit and store the carry
        if (n%2 == 1)
        {
            num[mid] += carry;
            carry = num[mid] / 10;
            num[mid] %= 10;
            j = mid + 1;
        }
        else
            j = mid;
 
        // Add 1 to the rightmost digit of the left side, propagate the carry towards MSB digit and simultaneously copying mirror of the left side to the right side.
        while (i >= 0)
        {
            num[i] += carry;
            carry = num[i] / 10;
            num[i] %= 10;
            num[j++] = num[i--]; // copy mirror to right
        }
    }
}

void generateNextPalindrome(long int no)
{
    int i;
    stack<int> s;
    while(no !=0 ){
        s.push(no%10);
        no = no/10;
    }
    
    int n = s.size();
    int *num = new int[n];
    i = 0;
    while(!s.empty()){
        *(num+i) = s.top();
        s.pop();
        i++;
    }
    // printArray(num, n);
    
    cout<<"Next palindrome is:";
    if( AreAll9s( num, n ) ){//All the digits are 9, simply o/p 1 followed by n-1 0's followed by 1
        cout<<"1";
        for( i=1; i < n; i++ )
            cout<<"0";
        cout<<"1";
    } else {
        NP( num, n );
        printArray (num, n);
    }
}

int main()
{
    long int num = 187978322;
    generateNextPalindrome(num); 
    return 0;
}


