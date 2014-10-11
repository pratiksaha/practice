//Prime factorization
#include<iostream>
#include<cmath>
#include<vector>
#include<map>
using namespace std;

vector<int> primeFactors(int n) {
    vector<int> pfs;
    //Print the number of 2s that divide n
    while (n%2 == 0) {
        pfs.push_back(2);   
        n = n/2;
    }
 
    int root = sqrt(n);
    for (int i = 3; i<=root; i = i+2) { //n must be odd at this point So we can skip one element
        // While i divides n, print i and divide n
        while (n%i == 0) {
            pfs.push_back(i);
            n = n/i;
        }
    }
     
    if (n > 2) // This condition is to handle the case whien n is a prime number greater than 2
        pfs.push_back(n);
    return  pfs;
}

map<int, int> primeFactorization(int n) {
    vector<int> pfs;
    vector<int>::iterator it;
    map<int, int> pfz;
    
    pfs = primeFactors(n);
    for(it = pfs.begin(); it != pfs.end(); it++) {
        if(pfz.count(*it))
            pfz[*it] += 1;
        else
            pfz.insert(pair<int, int>(*it, 1)); 
    }
    
    return pfz;
}

void printPrimeFactors(int n) {
    vector<int> pf;
    vector<int>::iterator ipf;
    pf = primeFactors(n);
    cout<<"Prime factors of "<<n<<" are"; 
    for(ipf = pf.begin(); ipf != pf.end(); ipf++)
        cout<<" "<<*ipf;
    cout<<endl;
}

void printPrimeFactorization(int n) {
    map<int, int> pfz;
    map<int, int>::iterator ipfz;
    pfz = primeFactorization(n);
    cout<<"Prime factorization of "<<n<<" is "; 
    for(ipfz = pfz.begin(); ipfz != pfz.end(); ipfz++) {
        if (ipfz != pfz.begin())
            cout<<"*";
        cout<<ipfz->first<<"^"<<ipfz->second;
    }
    cout<<endl;
}

int main()
{
    int n = 315;
    printPrimeFactors(n);
    printPrimeFactorization(n);          
    return 0;
}
