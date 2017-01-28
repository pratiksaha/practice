//to find nth pentagonal no
#include<bits/stdc++.h>
using namespace std;

int pentagonalNumber(int n) {
    return (3*n*n - n)/2;
}

int main(){
    cout<<"10th pentagonal no : "<<pentagonalNumber(10)<<endl;
    return 0;
}

