#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int isPowerOf4(int n)
{
    int count = 0;
    if ( n && !(n&(n-1)) )//Check if there is only one bit set in n
    {
        while(n > 1)// count 0 bits before set bit
        {
            n  >>= 1;
            count += 1;
        }     
        return (count%2 == 0)? 1 :0; //If count is even then return true else false
    }
    return 0; // If there are more than 1 bit set then n is not a power of 4
}

int isPowerOf2(int x)
{
    return x && (!(x&(x-1)));
}

int isMultipleOf9(int n)
{
    if (n == 0 || n == 9)
        return 1;
    if (n < 9)
        return 0;
    return isMultipleOf9((int)(n>>3) - (int)(n&7));
}

int isMultipleOf3(int n)
{
    int odd_count = 0;
    int even_count = 0;
    if(n < 0)
        n = -n;
    if(n == 0)
        return 1;
    if(n == 1)
        return 0; 
    while(n)
    {
        if(n & 1)
           odd_count++;
        n = n>>1;
        if(n & 1)
            even_count++;
        n = n>>1;
    } 
    return isMultipleOf3(abs(odd_count - even_count));
}

int getParity(int n)
{
    int parity = 0;
    while (n)
    {
        parity = !parity;
        n = n & (n - 1);
    }       
    return parity;
}

bool isMultipleof5(int n) {
    if ( (n&1) == 1 )
        n<<= 1; 
    float x = n;
    x = ((int)(x*0.1))*10;
    if ( (int)x == n )
        return true;
 
    return false;
}

int main(){
    int no;
    no = 64;
    cout<<no<<(isPowerOf4(no)?" is power of 4":" is not a power of 4")<<endl;
    no = 63;
    cout<<no<<(isPowerOf4(no)?" is power of 4":" is not a power of 4")<<endl;
    no = 32;
    cout<<no<<(isPowerOf2(no)?" is power of 2":" is not a power of 2")<<endl;
    no = 31;
    cout<<no<<(isPowerOf2(no)?" is power of 2":" is not a power of 2")<<endl;
    no = 81;
    cout<<no<<(isMultipleOf9(no)?" is multiple of 9":" is not a multiple of 9")<<endl;
    no = 60;
    cout<<no<<(isMultipleOf9(no)?" is multiple of 9":" is not a multiple of 9")<<endl;
    no = 27;
    cout<<no<<(isMultipleOf3(no)?" is multiple of 3":" is not a multiple of 3")<<endl;
    no = 28;
    cout<<no<<(isMultipleOf3(no)?" is multiple of 3":" is not a multiple of 3")<<endl;
    no = 13;
    cout<<no<<(getParity(no)?" is odd parity":" is even parity")<<endl;
    no = 6;
    cout<<no<<(getParity(no)?" is odd parity":" is even parity")<<endl;
    no = 28;
    cout<<no<<(isMultipleof5(no)?" is multiple of 5":" is not a multiple of 5")<<endl;
    no = 15;
    cout<<no<<(isMultipleof5(no)?" is multiple of 5":" is not a multiple of 5")<<endl;
    no = 20;
    cout<<no<<(isMultipleof5(no)?" is multiple of 5":" is not a multiple of 5")<<endl;
    return 0;
}
