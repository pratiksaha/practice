//to print nth carol no
#include<bits/stdc++.h>
using namespace std;

int carolNumber(int n) {
    int result = pow(2, n) - 1;
    return result*result - 2;
}

int main(){
    int n =4;
    cout<<n<<"th Carol No is "<<carolNumber(n)<<endl;
    return 0;
}
