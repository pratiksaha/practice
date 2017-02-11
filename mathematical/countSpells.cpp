//to count number of ways we can spell a number
#include<bits/stdc++.h>
using namespace std;
 
long long int countSpells(string num) {
    int n = num.length();
    long long int result = 1;
    for (int i=0; i<n; i++) {
       int count = 1;
       while (i < n-1 && num[i+1] == num[i]) {
           count++;
           i++;
       }
       result = result * pow(2, count-1);
    }
    return result;
}

int main() {
    string num = "11112";
    cout<<"No of ways to spell "<<num<<" is "<<countSpells(num)<<endl;
    return 0;
}
