//solve Algebraic Transcendental Equations
#include<bits/stdc++.h>
using namespace std;
#define EPSILON 0.01
#define MAX_ITER 1000000

double func(double x) {
    return x*x*x - x*x + 2;
}

double derivFunc(double x) {
    return 3*x*x - 2*x;
}

double solveAlgTransBisection(double a, double b) {
    assert((func(a)*func(b))<0);
    double c = a;
    while ((b-a)>=EPSILON) {
        c = (a+b)/2;
        if (func(c) == 0.0)
            break;
        else if (func(c)*func(a) < 0)
            b = c;
        else
            a = c;
    }
    return c;
}

double solveAlgTransRegulaFalsi(double a, double b) {
    assert((func(a)*func(b))<0);
    double c = a;
    for (int i=0; i<MAX_ITER; i++) {
        c = (a*func(b)-b*func(a))/(func(b)-func(a));
        if (func(c)==0)
            break;
        else if (func(c)*func(a) < 0)
            b = c;
        else
            a = c;
    }
    return c;
}

double solveAlgTransNewtonRaphson(double x) {
    double h = func(x)/derivFunc(x);
    while (abs(h) >= EPSILON) {
        h = func(x)/derivFunc(x);  
        x = x - h;
    }
    return x;
}

int main() {
    double a =-200, b = 300, x0 = -20;
    cout<<"Solving Eqn using Bisection with a = "<<a<<" & b = "<<b<<" Root = "<<solveAlgTransBisection(a, b)<<endl;
    cout<<"Solving Eqn using Regula Falsi with a = "<<a<<" & b = "<<b<<" Root = "<<solveAlgTransRegulaFalsi(a, b)<<endl;
    cout<<"Solving Eqn using Newton Raphson with x0 = "<<x0<<" Root = "<<solveAlgTransNewtonRaphson(x0)<<endl;
    return 0;
}
