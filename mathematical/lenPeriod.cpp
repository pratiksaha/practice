//to find length of period of 1/n without 
#include<iostream>
using namespace std;

int lenPeriod(int n) {
    int rem = 1; // Initialize remainder
    for (int i=1; i<=n+1; i++)
        rem = (10*rem) % n;
   int d = rem;
   int count = 0;
   do {
      rem = (10*rem) % n;
      count++;
   } while(rem != d);
   return count;
}

int main() {
    cout<<"Length of period in 1/3 is "<<lenPeriod(3)<<endl;
    cout<<"Length of period in 1/7 is "<<lenPeriod(7)<<endl;
    return 0;
}
