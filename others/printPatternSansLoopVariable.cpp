// to print pattern that first reduces 5 one by one and then adds 5 without any loop an extra variable
#include <iostream>
using namespace std;

void printPatternSansLoopVariable(int n) { 
     if (n ==0 || n<0) {
        cout<<" "<<n;  
     } else {
        cout<<" "<<n;
        printPatternSansLoopVariable(n-5);
        cout<<" "<<n; 
     }  
}

int main() {
    int n = 16;
    printPatternSansLoopVariable(n);
    return 0;
}
