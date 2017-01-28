//to find nth s-gonal no
#include<bits/stdc++.h>
using namespace std;

int polygonalNumber(int s, int n) {
    return (s - 2)*n*(n-1)/2 + n;
}

int main(){
    cout<<"For s = 6 & n = 10 : "<<polygonalNumber(6, 10)<<endl;
    cout<<"For s = 7 & n = 8 : "<<polygonalNumber(7, 8)<<endl;
    cout<<"For s = 12 & n = 5 : "<<polygonalNumber(12, 5)<<endl;
    return 0;
}
