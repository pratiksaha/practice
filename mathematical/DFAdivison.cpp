#include<iostream>
#include<cstdlib>
using namespace std;
 
// Function to build the transition table for the DFA for divisor k
void preprocess(int k, int Table[][2])
{
    int trans0, trans1;
 
    // The following loop calculates the two transitions for each state
    for (int state=0; state<k; ++state)
    {
        //When we were at state p
        // Calculate next state for bit 0
        trans0 = state<<1; //this is 2*p if we read a 0
        Table[state][0] = (trans0 < k)? trans0: trans0-k;
 
        // Calculate next state for bit 1
        trans1 = (state<<1) + 1; //this is 2*p+1 if we read a 1
        Table[state][1] = (trans1 < k)? trans1: trans1-k;
    }
}
 
// A recursive utility function that takes a ‘num’ and DFA (transition table) as input and process ‘num’ bit by bit over DFA
void isDivisibleUtil(int num, int* state, int Table[][2])
{
    // process "num" bit by bit from MSB to LSB
    if (num != 0)
    {
        isDivisibleUtil(num>>1, state, Table);
        *state = Table[*state][num&1];
    }
}
 
// The main function that divides ‘num’ by k and returns the remainder
int isDivisible (int num, int k)
{
    //there will be k states(or remainders in the DFA
    //Transition on each state occurs either for a 0 or 1
    //Hence total of k*2 entries in the transition table 
    int (*Table)[2] = (int (*)[2])malloc(k*sizeof(*Table));
 
    preprocess(k, Table);
 
    // Process ‘num’ over DFA and get the remainder
    int state = 0;//starting state is 0
    isDivisibleUtil(num, &state, Table);
 
    //return the final state as the remainder
    return state;
}
 
int main()
{
    int num = 47;
    int k = 5; 
    int remainder = isDivisible (num, k); 
    if (remainder == 0)
        cout<<"Divisible\n";
    else
        cout<<"Not Divisible: Remainder is "<<remainder<<endl; 
    return 0;
}
