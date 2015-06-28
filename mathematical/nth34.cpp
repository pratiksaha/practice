//to find n'th number in a number system with only 3 and 4
#include<iostream>
#include<string>
using namespace std;

string nth34(int n) {
    string arr[n+1];
    arr[0] = "";
    int size = 1, m = 1;
    while (size<=n) {
        for (int i=0; i<m && (size+i)<=n; i++)
            arr[size+i] = "3" + arr[size-m+i];
        for (int i=0; i<m && (size + m + i)<=n; i++)
            arr[size+m+i] = "4" + arr[size-m+i];
        m = m*2;
        size = size + m;
    }
    return arr[n];
}

int main() {
    for (int i=1; i<16; i++)
        cout<<i<<"th no is "<<nth34(i)<<endl;
    return 0;
}
