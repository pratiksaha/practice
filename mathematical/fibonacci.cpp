#include<iostream>
#include<cmath>
using namespace std;

//Check if a no is perfect square
bool isPerfectSquare(long int n){
    int s = sqrt(n);
    return (n == s*s);
}

bool isFibonacci(long int n){
    // n is Fibonacci if one of 5*n*n + 4 or 5*n*n - 4 or both is a perferct square
    return isPerfectSquare(5*n*n + 4) || isPerfectSquare(5*n*n - 4);
}

//return the nth Fibonacci no (Space Optimized DP soln in O(n))
long int fib(long int n)
{
    long int a = 0, b = 1, c, i;
    if( n == 0)
        return a;
    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

void multiply(long int F[2][2], long int M[2][2])
{
    long int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
    long int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
    long int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
    long int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];
 
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void power(long int F[2][2], long int n)
{
    if( n == 0 || n == 1)
        return;
    long int M[2][2] = {{1,1},{1,0}};
 
    power(F, n/2);
    multiply(F, F);
 
    if (n%2 != 0)
        multiply(F, M);
}
 
//return the nth Fibonacci no (Matrix method O(Logn))
long int fibo(long int n)
{
    long int F[2][2] = {{1,1},{1,0}};
    if (n == 0)
        return 0;
    power(F, n-1);
    return F[0][0];
}

int countFib(int low, int high) {
    int f1 = 0, f2 = 1, f3 = 1;
    int result = 0;
    while (f1 <= high) {
        if (f1 >= low)
            result++;
        f1 = f2;
        f2 = f3;
        f3 = f1 + f2;
    }
    return result;
}

int main(){
    int x;
    x = 6765;
    cout<<x<<(isFibonacci(x)?" is a fibonacci no":" is not a fibonacci no")<<endl;
    x = 6700;
    cout<<x<<(isFibonacci(x)?" is a fibonacci no":" is not a fibonacci no")<<endl;
    x = 20;
    cout<<x<<"th fibonacci no is "<<fib(x)<<endl;
    x = 21;
    cout<<x<<"th fibonacci no is "<<fibo(x)<<endl;
    int low = 10, high = 100;
    cout<<"No of fibonacci nos between "<<low<<" & "<<high<<" = "<<countFib(low, high)<<endl;
    return 0;
}
