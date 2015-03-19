//to find the square of a no
#include<iostream>
using namespace std;
 
int square(int n) {//Time: O(logn)
    if (n==0) //base case
        return 0;
    if (n<0) //square of n is same is square of -n
        n = -n;
    int x = n>>1; //x=floor(n/2)
    if (n&1) //n is odd
        return ((square(x)<<2) + (x<<2) + 1);
    else //n is even
        return (square(x)<<2);
}

int main() {
    for (int i=-5; i<=20; i++)
        cout<<"Square of "<<i<<" is "<<square(i)<<endl;
    return 0;
}
