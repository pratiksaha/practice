//to count all possible way to construct buildings
#include<iostream>
using namespace std;

int countBuildingsON(int N) {
    if (N == 1)
        return 4; //2 for one side and 4 for two sides
    int countB=1; //count of ways with a building at the end
    int countS=1; //count of ways with a space at the end
    int prev_countB, prev_countS;
    for (int i=2; i<=N; i++) {
        prev_countB = countB;
        prev_countS = countS;
        countS = prev_countB + prev_countS;
        countB = prev_countS;
    }
    int result = countS + countB; //result for one side is sum of ways ending with building and ending with space
    return (result*result); //result for 2 sides is square of result for one side
}

void multiply(long int F[2][2], long int M[2][2]) {
    long int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
    long int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
    long int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
    long int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void power(long int F[2][2], long int n) {
    if( n == 0 || n == 1)
        return;
    long int M[2][2] = {{1,1},{1,0}};
    power(F, n/2);
    multiply(F, F);
    if (n%2 != 0)
        multiply(F, M);
}

long int fibo(long int n) {
    long int F[2][2] = {{1,1},{1,0}};
    if (n == 0)
        return 0;
    power(F, n-1);
    return F[0][0];
}

long int countBuildingsOLogN(int N) {
    int result = fibo(N+2);
    return (result*result);
}

int main() {
    int N = 3;
    cout<<"Count of ways for "<<N<<" sections is "<<countBuildingsON(N)<<endl;
    cout<<"Count of ways for "<<N<<" sections is "<<countBuildingsOLogN(N)<<endl;
    return 0;
}
