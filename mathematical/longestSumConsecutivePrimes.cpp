//to find longest sum of consecutive primes
#include<bits/stdc++.h>
using namespace std;
#define MAX 10000

void sieveSundaram(vector <int> &primes) {
    bool marked[MAX/2 + 1] = {0};
    for (int i=1; i<=(sqrt(MAX)-1)/2; i++)
        for (int j=(i*(i+1))<<1; j<=MAX/2; j=j+2*i+1)
            marked[j] = true;
    primes.push_back(2);
    for (int i=1; i<=MAX/2; i++)
        if (marked[i] == false)
            primes.push_back(2*i + 1);
}

int longestSumConsecutivePrimes(int limit, vector<int> &prime, long long int sum_prime[]) {
    int max_length = -1;
    int prime_number = -1;
    for (int i=0; prime[i]<=limit; i++) {
        for (int j=0; j<i; j++) {
            if (sum_prime[i] - sum_prime[j] > limit)
                break;
            long long int consSum  = sum_prime[i] - sum_prime[j];
            if (binary_search(prime.begin(), prime.end(), consSum)) {
                if (max_length < i-j+1) {
                    max_length = i-j+1;
                    prime_number = consSum;
                }
            }
        }
    }
    return prime_number;
}
 
void longestSumConsecutivePrimes(int arr[], int n) {
    vector<int> primes;
    sieveSundaram(primes);
    long long int sum_prime[primes.size() + 1];
    sum_prime[0] = 0;
    for (int i = 1 ; i <= primes.size(); i++)
        sum_prime[i] = primes[i-1] + sum_prime[i-1];
    for (int i=0; i<n; i++)
      cout<<"prime number which can be written as the sum of the most consecutive primes <= "<<arr[i]<<" is "<<longestSumConsecutivePrimes(arr[i], primes, sum_prime)<<endl;
}

int main() {
    int arr[] = {10, 30, 40, 50, 1000};
    int n = sizeof(arr)/sizeof(arr[0]);
    longestSumConsecutivePrimes(arr, n);
    return 0;
}
