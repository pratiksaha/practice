//to print prime factors and their powers
#include<bits/stdc++.h>
using namespace std;

void sieveOfEratosthenes(int N, int s[]) {
    vector <bool> prime(N+1, false);
    for (int i=2; i<=N; i+=2)
        s[i] = 2;
    for (int i=3; i<=N; i+=2) {
        if (prime[i] == false) {
            s[i] = i;
            for (int j=i; j*i<=N; j+=2) {
                if (prime[i*j] == false) {
                    prime[i*j] = true;
                    s[i*j] = i;
                }
            }
        }
    }
}
 
void factorPowers(int N) {
    int s[N+1];
    sieveOfEratosthenes(N, s);
    cout<<"Factor Powers of "<<N<<" :\n";
    int curr = s[N];
    int cnt = 1;
    while (N > 1) {
        N /= s[N];
        if (curr == s[N]) {
            cnt++;
            continue;
        }
        cout<<curr<<"\t"<<cnt<<endl;
        curr = s[N];
        cnt = 1;
    }
}
 
int main() {
    int N = 360;
    factorPowers(N);
    return 0;
}
