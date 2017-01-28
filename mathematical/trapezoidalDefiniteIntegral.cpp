//to implement Trapezoidal rule
#include<bits/stdc++.h>
using namespace std;

float func(float x) {
    return 1/(1+x*x);
}
 
float trapezoidalDefiniteIntegral(float a, float b, float n) {
    float h = (b-a)/n;
    float s = func(a)+func(b);
    for (int i = 1; i < n; i++)
        s += 2*func(a+i*h);
    return (h/2)*s;
}

int main() {
    float x0 = 0;
    float xn = 1;
    int n = 6;
    cout<<"Value of integral b/w "<<x0<<" & "<<xn<<" with "<<n<<" intervals is "<<trapezoidalDefiniteIntegral(x0, xn, n)<<endl;
    return 0;
}
