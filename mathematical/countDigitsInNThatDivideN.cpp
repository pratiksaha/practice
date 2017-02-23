//to find number of digits in N that divide N
#include<bits/stdc++.h>
using namespace std;
 
bool divisible(string N, int digit) {
    int ans = 0;
    for (int i = 0; i < N.length(); i++) {
        ans = (ans*10 + (N[i]-'0'));
        ans %= digit;
    }
    return (ans == 0);
}

int countDigitsInNThatDivideN(string N) {
    bool divide[10] = {false};
    divide[1] = true;
    for (int digit=2; digit<=9; digit++)
        if (divisible(N, digit))
            divide[digit] = true;
    int result = 0;
    for (int i=0; i<N.length(); i++)
        if (divide[N[i]-'0'])
            result++;
    return result;
}

int main() {
    string N = "122324";
    cout<<countDigitsInNThatDivideN(N)<<endl;
    return 0;
}
