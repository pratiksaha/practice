#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
#define MAX 1000001

//Return all prime numbers smaller than n
vector<int> SieveOfEratosthenes(int n) {
    vector<int> v;
    bool arr[n+1];
    int i;
    
    arr[0] = arr[1] = false; //0 & 1 are not primes
    for(i=2 ; i<=n; i++)//initialize remaining elements as true
        arr[i] = true;
            
    if (n >= 2) {//There are no prime numbers smaller than 2
        int sqr = sqrt(n);
        for (i=2; i<=sqr; i++)//arr[i] == true means i is prime
            if ( arr[i] )            
                for(int j = i*i; j<=n; j += i)//mark its multiples(optimized version)
                    arr[j] = false;   
    }
    
    for(i=0 ; i<=n; i++)
        if(arr[i])
            v.push_back(i);//push all primes to the vector
    return v;
}

vector<long long >isprimeMan(MAX, true);
vector<long long >primeMan;
vector<long long >SPF(MAX);

void manipulated_seive(int N) {
    isprimeMan[0] = isprimeMan[1] = false ;
    for (long long int i=2; i<N ; i++) {
        if (isprimeMan[i]) {
            primeMan.push_back(i);
            SPF[i] = i;
        }
        for (long long int j=0; j<(int)primeMan.size() && i*primeMan[j] < N && primeMan[j] <= SPF[i]; j++) {
            isprimeMan[i*primeMan[j]]=false;
            SPF[i*primeMan[j]] = primeMan[j] ;
        }
    }
}

int main()
{
    int n = 98;
    vector<int> primes;
    vector<int>::iterator it;
    
    primes = SieveOfEratosthenes(n);
    cout<<"Prime numbers upto "<<n<<" are :";
    for(it=primes.begin(); it!=primes.end(); it++)
        cout<<" "<<*it;
    cout<<endl;

    int N = 98;
    manipulated_seive(N);
    cout<<"Prime numbers upto "<<N<<" are :";
    for (int i=0; i<primeMan.size() && primeMan[i] <= N; i++)
        cout<<" "<<primeMan[i];
    cout<<endl;
    return 0;
}
