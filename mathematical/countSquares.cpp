//to count squares in a rectangle of size m x n
#include<bits/stdc++.h>
using namespace std;

int countSquares(int m, int n) {
   if (n < m)
      swap(m, n);
   return  m*(m+1)*(2*m+1)/6 + (n-m)*m*(m+1)/2;
}

int main() {
   int m = 4, n = 3;
   cout<<"No of squares in a "<<m<<"x"<<n<<" rectangle is "<<countSquares(m, n)<<endl;
}
