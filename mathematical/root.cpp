#include<bits/stdc++.h>
using namespace std;
#define precision 0.0000001

double cubicRoot(double n) {
    double start = 0, end = n;
    double e = 0.0000001;
    while (true) {
        double mid = (start + end)/2;
        double error = abs(n-(mid*mid*mid));
        if (error <= precision)
            return mid;
        if ((mid*mid*mid) > n)
            end = mid;
        else
            start = mid;
    }
}

int floorFifthRoot(int n) {
    if (n == 0 || n == 1)
        return n;
    int low = 1, high = n, ans = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        long int mid5 = mid*mid*mid*mid*mid;
        if (mid5 == n)
            return mid;
        if (mid5 < n) {
            low = mid + 1;
            ans = mid;
        }else {
            high = mid - 1;
        }
    }
    return ans;
}

void quadraticRoots(int a, int b, int c) {
    cout<<"For "<<a<<"x^2 + "<<b<<"x + "<<c<<" : ";
    if (a == 0) {
        cout<<"is not a valid quadratic equation\n";
        return;
    }
    int d  = b*b - 4*a*c;
    double sqrt_val = sqrt(abs(d));
    if (d > 0)
        cout<<"roots are real and different : "<<(double)(-b + sqrt_val)/(2*a)<<" & "<<(double)(-b - sqrt_val)/(2*a)<<endl;
    else if (d == 0)
        cout<<"roots are real and same : "<<-(double)b/(2*a)<<endl;
    else
        cout<<"roots are complex : "<<-(double)b/(2*a)<<" + i "<<sqrt_val<<"  & "<<-(double)b/(2*a)<<" - i "<<sqrt_val<<endl;
}

void unityRoots(int n) {
    double theta = M_PI*2/n;
    cout<<n<<"th roots of unity are :";
    for(int k=0; k<n; k++) {
        double real = cos(k*theta);
        double img = sin(k*theta);
        printf(" ( %.6f", real);
		(img >= 0) ? printf(" + i ") : printf(" - i ");
		printf("%.6f )", abs(img));
    }
    cout<<endl;
}

float sqrootBakhshali(float s) {
    int pSq = 0;
    int N = 0;
    for (int i = static_cast<int>(s); i>0; i--) {
        for (int j = 1; j < i; j++) {
            if (j*j == i) {
                pSq = i;
                N = j;
                break;
            }
        }
        if (pSq > 0)
            break;
    } 
    float d = s - pSq;
    float P = d/(2.0*N);
    float A = N+P;
    float sqrt_of_s = A-((P*P)/(2.0*A));
    return sqrt_of_s;
}

int main(){
    cout<<"Cubic root of 3 is "<<cubicRoot(3)<<endl;
    cout<<"Floor of fifth root of 250 is "<<floorFifthRoot(250)<<endl;
    quadraticRoots(1, 1, 1);
    quadraticRoots(1, -2, 1);
    quadraticRoots(1, -7, -12);
    quadraticRoots(1, -7, 12);
    unityRoots(1);
    unityRoots(2);
    unityRoots(3);
    cout<<"Square Root of 9.2345 is "<<sqrootBakhshali(9.2345)<<endl;
    return 0;
}
