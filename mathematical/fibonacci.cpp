#include<iostream>
#include<cmath>
using namespace std;
#define MAX 1000
#define PHI 1.6180339887498948

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

long int sumFibonacci(int n) {
    return fib(n+2) - 1;
}

long int evenFibonacci(int n) {
    if (n < 1)
       return n;
    if (n == 1)
       return 2;
    return ((4*evenFibonacci(n-1)) + evenFibonacci(n-2));
}

int findPosFibSeries(int k, int n) {
    unsigned long long int f1 = 0, f2 = 1, f3;
    for (int i = 2; i <= MAX; i++) {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
        if (f2%k==0) //first multiple of k at position i
           return n*i; //n'th multiple would be at position n*i using periodic property of fibonacci numbers under modulo
    }
}

int nonFibonacci(int n) {
    int prevPrev=1, prev=2, curr=3;
    while (n > 0) {
        prevPrev = prev;
        prev = curr;
        curr = prevPrev + prev;
        n = n - (curr - prev - 1);
    }
    n = n + (curr - prev - 1);
    return prev + n;
}

void unitFibonacci(long long int f[], int n) { //finds unit digits of n fibonacci nos and stores in f
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++)
        f[i] = (f[i-1] + f[i-2])%10;
}

int lastDigitOfNFibonacci(int n) {
    long long int f[60] = {0};
    unitFibonacci(f, 60);
    return f[n%60];
}

long long int numberOfDigitsNFibonacci(int n) {
    if (n == 1)
        return 1;
    long double d = (n * log10(PHI)) - ((log10(5)) / 2);
    return ceil(d);
}

long long int evenFibonacciSum(int n) {
    if (n < 2)
        return 0;
    long long int ef1 = 0, ef2 = 2;
    long long int sum = ef1 + ef2;
    while (ef2 <= n) {
        long long int ef3 = 4*ef2 + ef1;
        if (ef3 > n)
            break;
        ef1 = ef2;
        ef2 = ef3;
        sum += ef2;
    }
    return sum;
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
    cout<<"Sum of first 4 fibonacci nos is "<<sumFibonacci(4)<<endl;
    cout<<"7th even fibonacci no is "<<evenFibonacci(7)<<endl;
    cout<<"Position of 5th multiple of 4 in fibonacci series is "<<findPosFibSeries(4, 5)<<endl;
    cout<<"5th non fibonacci no is "<<nonFibonacci(5)<<endl;
    cout<<"Last didgit of 1th fibonacci no is "<<lastDigitOfNFibonacci(1)<<endl;
    cout<<"Last didgit of 61th fibonacci no is "<<lastDigitOfNFibonacci(61)<<endl;
    cout<<"Last didgit of 7th fibonacci no is "<<lastDigitOfNFibonacci(7)<<endl;
    cout<<"Last didgit of 67th fibonacci no is "<<lastDigitOfNFibonacci(67)<<endl;
    for (int i = 1; i <= 10; i++)
        cout<<"No of didgits is Fib("<<i<<") is "<<numberOfDigitsNFibonacci(i)<<endl;
    cout<<"Even Fibonacci Sum till 400 is "<<evenFibonacciSum(400)<<endl;
    return 0;
}
