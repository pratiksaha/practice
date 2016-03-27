//to count perfect squares between a and b
#include<bits/stdc++.h>
using namespace std;

int countPerfectSquares(int a, int b) {
    return (floor(sqrt(b)) - ceil(sqrt(a)) + 1);
}

int main() {
    int a = 9, b = 25;
    cout<<"Count of perfect squares between "<<a<<" & "<<b<<" is "<<countPerfectSquares(a, b)<<endl;
    return 0;
}
