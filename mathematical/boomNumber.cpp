//to find k-th Boom number
#include<bits/stdc++.h>
using namespace std;

void  boomNumber(long long int k) {
    cout<<k<<"th boom number is ";
    queue<string> q;
    q.push("");
    long long int count = 0;
    while (count <= k) {
        string s1 = q.front();
        q.pop();
        string s2 = s1;
        q.push(s1.append("2"));
        count++;
        if (count==k) {
            cout<<s1;
            break;
        }
        q.push(s2.append("3"));
        count++;
        if (count==k){
            cout<<s2;
            break;
        }
    }
    cout<<endl;
}
 
int main() {
    long long int k = 1000000;
    boomNumber(k);
    return 0;
}   
