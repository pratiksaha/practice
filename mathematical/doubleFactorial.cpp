//double factorial
#include<bits/stdc++.h>
using namespace std;
  
unsigned int doubleFactorial(unsigned int n) {
    int res = 1;
    for (int i=n; i>=0; i=i-2) {
        if (i==0 || i==1)
            return res;
        else
            res *= i;
    }
}
  
int main(){
    int n = 5;
    cout<<"("<<n<<")!! = "<<doubleFactorial(5)<<endl;
    return 0;
}
