//to count number of ways to connect n points on a circle such that no two connecting lines cross each other and every point is connected with one other point
#include<bits/stdc++.h>
using namespace std;

unsigned long int catalanDP(unsigned int n) {
    unsigned long int catalan[n+1];
    catalan[0] = catalan[1] = 1;
    for (int i=2; i<=n; i++) {
        catalan[i] = 0;
        for (int j=0; j<i; j++)
            catalan[i] += catalan[j] * catalan[i-j-1];
    }
    return catalan[n];
}

unsigned long int nonCrossingLinesConnectingPointsOnCircle(unsigned long int n) {
   if (n & 1) // no way odd no of points can be connected by lines
      return 0;
   return catalanDP(n/2);
}

int main() {
    int n = 6;
    cout<<"no of ways "<<n<<" points on a circle can be joined is "<<nonCrossingLinesConnectingPointsOnCircle(n)<<endl;
    return 0;
}
