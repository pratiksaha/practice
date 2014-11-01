//Find ugly nos
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

unsigned int maxDivide(unsigned int a, unsigned int b) {
    while (a%b == 0)
        a = a/b; 
    return a;
}   

bool isUgly(unsigned int no) {
    no = maxDivide(no, 2);
    no = maxDivide(no, 3);
    no = maxDivide(no, 5);
    return (no == 1)? true : false;
}    

unsigned int getNthUglyNo(int n) {
    unsigned int i = 1; 
    int count = 1;
    while (n>count) {
        i++;      
        if (isUgly(i))
            count++; 
    }
    return i;
}

unsigned int min3(unsigned int a, unsigned int b, unsigned int c) {
    return min(min(a, b), c);
}

unsigned getNthUglyNoDP(int n) {
    unsigned int ugly[n];
    int i=0, i2 = 0, i3 = 0, i5 = 0;
    
    unsigned int next_mul2 = 2;
    unsigned int next_mul3 = 3;
    unsigned int next_mul5 = 5;
    unsigned int next_ugly = 1;
    
    ugly[0] = 1;
 
    for(i=1; i<n; i++) {
        next_ugly = min3(next_mul2, next_mul3, next_mul5);
        ugly[i] = next_ugly;                   
        if(next_ugly == next_mul2) {
           i2++;      
           next_mul2 = ugly[i2]*2;
        }
        if(next_ugly == next_mul3) {
           i3++;
           next_mul3 = ugly[i3]*3;
        }
        if(next_ugly == next_mul5) {
           i5++;
           next_mul5 = ugly[i5]*5;
        }
    }
    return next_ugly;
}

int main() {
    cout<<"150th ugly no is "<<getNthUglyNo(150)<<endl;
    cout<<"150th ugly no is "<<getNthUglyNoDP(150)<<endl;
    return 0;
}
