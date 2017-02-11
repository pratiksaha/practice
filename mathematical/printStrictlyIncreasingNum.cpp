//to print all n-digit numbers whose digits are strictly increasing from left to right
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
using namespace std;

void printStrictlyIncreasingNum(int start, string out, int n) {
    if (n == 0) {
        cout<<" "<<out;
    } else {
        for (int i = start; i <= 9; i++) {
            string str = out + to_string(i);
            printStrictlyIncreasingNum(i + 1, str, n - 1);
        }
    }
}

void printStrictlyIncreasingNum(int n) {
    cout<<"All "<<n<<" digit nos which are strictly increasing are :";
    printStrictlyIncreasingNum(0, "", n);
    cout<<endl;
}

int main() {
    printStrictlyIncreasingNum(3);
    return 0;
}
