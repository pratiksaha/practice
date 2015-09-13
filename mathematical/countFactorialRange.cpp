//to count factorial numbers in given range
#include <iostream>
using namespace std;
 
int countFactorialRange(int low, int high) {
    int fact = 1, x = 1; 
    while (fact < low) { //find the first factorial number >= low
        fact = fact*x;
        x++;
    }
    int res = 0;
    while (fact <= high) { //count factorial numbers in range [low, high]
        res++;
        fact = fact*x;
        x++;
    }
    return res;
}

int main() {
    int l = 2;
    int r = 720;
    cout<<"Count of factorial nos between "<<l<<" & "<<r<<" is "<<countFactorialRange(2, 720)<<endl;
    return 0;
}
