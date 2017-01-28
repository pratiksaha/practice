//to find n'th smart number
#include<bits/stdc++.h>
using namespace std;
#define MAX 3000

int smartNumber(int n) {
    int primes[MAX] = {0};
    vector<int> result;
    for (int i=2; i<MAX; i++) {
        if (primes[i] == 0) {
            primes[i] = 1;
            for (int j=i*2; j<MAX; j=j+i) {
                primes[j] -= 1;
                if ( (primes[j] + 3) == 0)
                    result.push_back(j);
            }
        }
    }
    sort(result.begin(), result.end());
    return result[n-1];
}

int main(){
    cout<<"50th smart no : "<<smartNumber(50)<<endl;
    return 0;
}
