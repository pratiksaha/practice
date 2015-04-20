//to find the point where the function changes sign
#include<iostream>
using namespace std;

int f(int x) { 
    return (x*x - 10*x - 20);
}

int changeFuncSignUtil(int low, int high) {
    if (high >= low) {
        int mid = (low + high)/2;
        if (f(mid) >= 0 && (mid==low || f(mid-1)<0))
            return mid;
        if (f(mid) < 0)
            return changeFuncSignUtil(mid+1, high);
        else
            return changeFuncSignUtil(low, mid-1);
    }
    return -1; //function doesn't have a +ve value in the given range
}

int changeFuncSign() {
    if (f(0) >= 0) //first value itself is positive
        return 0;
    int i = 1;
    while (f(i) < 0)
        i = i*2;
    return changeFuncSignUtil(i/2, i);
}

int main() {
    cout<<"The value n where f() changes from -ve to +ve is "<<changeFuncSign()<<endl;
    return 0;
}
