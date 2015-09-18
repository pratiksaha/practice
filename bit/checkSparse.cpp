//to check if n is sparse
#include<iostream>
using namespace std;

bool checkSparse(int n) {
    if (n & (n>>1))
        return false;
    else
        return true;
}

int main() {
    int n;
    n = 72;
    cout<<"Checking sparse for "<<n<<" : "<<checkSparse(n)<<endl;
    n = 12;
    cout<<"Checking sparse for "<<n<<" : "<<checkSparse(n)<<endl;
    n = 2;
    cout<<"Checking sparse for "<<n<<" : "<<checkSparse(n)<<endl;
    n = 3;
    cout<<"Checking sparse for "<<n<<" : "<<checkSparse(n)<<endl;
    return 0;
}
