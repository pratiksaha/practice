//to find nth hexagonal no
#include<bits/stdc++.h>
using namespace std;

int hexagonalNumber(int n) {
    return n*(2*n - 1);
}

int main(){
    cout<<"10th hexagonal no : "<<hexagonalNumber(10)<<endl;
    return 0;
}
