//to get maximum sum of nos such that their LCM is N
#include <bits/stdc++.h>
using namespace std;
 
int getMaximumSumWithLCMn(int N) {
    int sum = 0;
    int LIM = sqrt(N);
    for (int i = 1; i <= LIM; i++) {
        if (N % i == 0) {
            if (i == (N / i))
                sum += i;
            else
                sum += (i + N / i);
        }
    }
    return sum;
}
 
int main() {
    int N = 12;
    cout<<"maximum sum of nos such that their LCM is "<<N<<" = "<<getMaximumSumWithLCMn(N)<<endl;
    return 0;
}
