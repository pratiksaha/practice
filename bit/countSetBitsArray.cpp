#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
//#define SIZE 5
#define SIZE (1 << 16) //Size of array 64 K
 
// Meta program that generates set bit count array of first 256 integers
#define GROUP_A(x) x, x + 1, x + 1, x + 2 //GROUP_A - When combined with META_LOOK_UP generates count for 4x4 elements
#define GROUP_B(x) GROUP_A(x), GROUP_A(x+1), GROUP_A(x+1), GROUP_A(x+2) // GROUP_B - When combined with META_LOOK_UP generates count for 4x4x4 elements
#define GROUP_C(x) GROUP_B(x), GROUP_B(x+1), GROUP_B(x+1), GROUP_B(x+2) //GROUP_C - When combined with META_LOOK_UP generates count for 4x4x4x4 elements
#define META_LOOK_UP(PARAMETER) GROUP_##PARAMETER(0), GROUP_##PARAMETER(1), GROUP_##PARAMETER(1), GROUP_##PARAMETER(2) // Provide appropriate letter to generate the table
 
int countSetBits(int array[], size_t array_size)
{
    int count = 0;
 
    // META_LOOK_UP(C) - generates a table of 256 integers whose sequence will be number of bits in i-th position where 0 <= i < 256 
    // A static table will be much faster to access
    static unsigned char const look_up[] = { META_LOOK_UP(C) };
 
    unsigned char *pData = NULL;
    
    for(size_t index = 0; index < array_size; index++) {
        pData = (unsigned char *)&array[index];
 
        // Count set bits in individual bytes
        count += look_up[pData[0]];
        count += look_up[pData[1]];
        count += look_up[pData[2]];
        count += look_up[pData[3]];
    }
    return count;
}
 
int main()
{
    int random[SIZE];
    srand((unsigned)time(0)); //Seed to the random-number generator  
    for( int i = 0; i < SIZE; i++ ) { //Generate random numbers
        random[i] = rand();
        //random[i] = i+1;
        //cout<<random[i]<<" ";
    }
    //cout<<endl;
    cout<<"Total number of bits = "<<countSetBits(random, SIZE)<<endl;
    return 0;
}
