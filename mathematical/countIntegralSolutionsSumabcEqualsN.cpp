//to count solutions of a + b + c = n
#include<bits/stdc++.h>
using namespace std;
 
int countIntegralSolutionsSumabcEqualsN(int n) {
    return ((n+1)*(n+2))/2;
}

int main(){
    int n = 3;
    cout<<"No of integral sols of a+b+c = "<<n<<" is "<<countIntegralSolutionsSumabcEqualsN(n)<<endl;
    return 0;
}
