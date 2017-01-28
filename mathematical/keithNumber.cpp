//check if a no is keith's no
#include<bits/stdc++.h>
using namespace std;

bool keithNumber(int x) {
    vector <int> terms;
    int temp = x, n = 0;
    while (temp > 0) {
        terms.push_back(temp%10);
        temp = temp/10;
        n++;
    }
    reverse(terms.begin(), terms.end());
    int next_term = 0, i = n;
    while (next_term < x) {
        next_term = 0;
        for (int j=1; j<=n; j++)
            next_term += terms[i-j];
        terms.push_back(next_term);
        i++;
    }
    return (next_term == x);
}

int main(){
    int n;
    n = 14;
    cout<<n<<" is"<<(keithNumber(n)? " " : " not ")<<"a keith no\n";
    n = 12;
    cout<<n<<" is"<<(keithNumber(n)? " " : " not ")<<"a keith no\n";
    n = 197;
    cout<<n<<" is"<<(keithNumber(n)? " " : " not ")<<"a keith no\n";
    return 0;
}
