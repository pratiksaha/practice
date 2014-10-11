#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

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

int main()
{
    int n = 98;
    vector<int> primes;
    vector<int>::iterator it;
    
    primes = SieveOfEratosthenes(n);
    cout<<"Prime numbers upto "<<n<<" are :";
    for(it=primes.begin(); it!=primes.end(); it++)
        cout<<*it<<" ";
    cout<<endl;
    return 0;
}
