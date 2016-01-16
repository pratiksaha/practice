#include<iostream>
#include<cstring>
using namespace std;
#define INT_BITS 32

//Function to swap n bits at positions p1 and p2 for the no x
int swapBits(unsigned int x, unsigned int p1, unsigned int p2, unsigned int n)
{
    unsigned int set1 =  (x >> p1) & ((1U << n) - 1); // Move all bits of first set to rightmost side 
    unsigned int set2 =  (x >> p2) & ((1U << n) - 1); // Moce all bits of second set to rightmost side
    unsigned int y = (set1 ^ set2);// XOR the two sets
    y = (y << p1) | (y << p2);// Put the xor bits back to their original positions
    unsigned int result = x ^ y; // XOR the 'xor' with the original number so that the two sets are swapped
    return result;
}
 
//Function to left rotate n by d bits
int leftRotate(int n, unsigned int d)
{
   return (n << d)|(n >> (INT_BITS - d));
}
 
//Function to right rotate n by d bits
int rightRotate(int n, unsigned int d)
{
   return (n >> d)|(n << (INT_BITS - d));
}

//Function to reverse the bits of a no assuming 8 bit integers
unsigned int reverseBits(unsigned int num)
{
    unsigned int  NO_OF_BITS = 8;
    unsigned int reverse_num = 0;
    int i;
    //cout<<NO_OF_BITS<<" "<<reverse_num<<" "<<num<<endl;
    for (i = 0; i < NO_OF_BITS; i++)
    {
        if((num & (1 << i)))
           reverse_num |= 1 << ((NO_OF_BITS - 1) - i); 
   }
    return reverse_num;
}

//Function to swap odd and even bits
unsigned int swapEvenOddBits(unsigned int x)
{
    unsigned int even_bits = x & 0xAAAAAAAA; // Get all even bits of x
    unsigned int odd_bits  = x & 0x55555555; // Get all odd bits of x 
    even_bits >>= 1;  // Right shift even bits
    odd_bits <<= 1;   // Left shift odd bits
    return (even_bits | odd_bits); // Combine even and odd bits
}

//Function to swap nibbles in a byte
unsigned char swapNibbles(unsigned char x)
{
    //cout<<sizeof(x);
    return (((x & 0x0F)<<4) | ((x & 0xF0)>>4));
}

//function to add x and y
int add(int x, int y) {
    while (y != 0) { //iterate till there is no carry 
        int carry = x & y; //carry now contains common set bits of x and y
        x = x^y; //sum of bits of x and y where at least one of the bits is not set
        y = carry << 1; //carry is shifted by one so that adding it to x gives the required sum
    }
    return x;
}

//function to subtract y from x
int subtract(int x, int y) {
    while (y != 0) { //iterate till there is no carry
        int borrow = (~x)&y; //borrow contains common set bits of y and unset bits of x
        x = x^y; //subtraction of bits of x and y where at least one of the bits is not set
        y = borrow<<1; //borrow is shifted by one so that subtracting it from x gives the required sum
    }
    return x;
}

int multiplyBySevenByEight(int n) { //calculate 7n/8
    return (n-(n>>3));
}

int turnOffK(int n, int k) { //turn off kth bit in n
    if (k <= 0)
        return n;
    else
        return (n & ~(1 << (k - 1)));
}

void swap(int &x, int &y) {
    (x ^= y), (y ^= x), (x ^= y);
}

void concatenate(int arr1[], int arr2[], int m, int n) {
    memcpy(arr1+m, arr2, sizeof(arr2));
}

int main(){
    cout<<"Swapping bits 0 and 3 in 28 is "<<swapBits(28,0,3,2)<<endl;
    cout<<"Left rotate of 16 by 2 is "<<leftRotate(16,2)<<endl;
    cout<<"Right rotate of 16 by 2 is "<<rightRotate(16,2)<<endl;
    cout<<"Reversing bits of 6 is "<<reverseBits(6)<<endl;
    cout<<"Swapping even and odd bits of 23 is "<<swapEvenOddBits(23)<<endl;
    cout<<"Swapping nibbles of 100 is "<<swapNibbles('d')<<endl;
    cout<<"11+6 = "<<add(11, 6)<<endl;
    cout<<"11-6 = "<<subtract(11, 6)<<endl;
    cout<<"7n/8 when n is 16 = "<<multiplyBySevenByEight(16)<<endl;
    cout<<"Turning off 4th bit in 15 = "<<turnOffK(15, 4)<<endl;
    int a = 10, b = 20;
    cout<<"Before Swapping : "<<a<<","<<b<<endl;
    swap(a, b);
    cout<<"After Swapping : "<<a<<","<<b<<endl;
    int arr1[5] = {1, 2, 3};
    int arr2[]  = {4, 5};
    concatenate(arr1, arr2, 3, 2);
    cout<"Concatenation :";
    for (int i=0; i<5; i++)
        cout<<" "<<*(arr1+i);
    cout<<endl;
    return 0;
}
