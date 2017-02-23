//to check if a string can be partitioned into two divisible strings
#include<bits/stdc++.h>
using namespace std;
 
void partitionIntoDivisibleParts(string &str, int a, int b) {
    int len = str.length();
    vector<int> lr(len+1, 0);
    lr[0] = (str[0] - '0')%a;
    for (int i=1; i<len; i++)
        lr[i] = ((lr[i-1]*10)%a + (str[i]-'0'))%a;
    vector<int> rl(len+1, 0);
    rl[len-1] = (str[len-1] - '0')%b;
    int power10 = 10;
    for (int i= len-2; i>=0; i--) {
        rl[i] = (rl[i+1] + (str[i]-'0')*power10)%b;
        power10 = (power10 * 10) % b;
    }
    for (int i=0; i<len-1; i++) {
        if (lr[i] != 0)
            continue;
        if (rl[i+1] == 0) {
            cout<<"YES : ";
            for (int k=0; k<=i; k++)
                cout<<str[k];
            cout<<" , ";
            for (int k=i+1; k<len; k++)
                cout<<str[k];
            cout<<endl;
            return;
        }
    }
    cout<<"NO\n";
}

int main() {
    string str = "123";
    int a = 12, b = 3;
    partitionIntoDivisibleParts(str, a, b);
    return 0;
}
