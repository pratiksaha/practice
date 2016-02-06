//to print Farey Sequence of order n
#include <bits/stdc++.h>
using namespace std;

void fareySequence(int n) {
    cout<<"Farey Sequence of order "<<n<<" is :";
    double x1 = 0, y1 = 1, x2 = 1, y2 = n;
    cout<<" "<<x1<<"/"<<y1<<" "<<x2<<"/"<<y2;
    double x, y = 0;
    while (y != 1.0) {
        x = floor((y1+n)/y2)*x2-x1;
        y = floor((y1+n)/y2)*y2-y1;
        cout<<" "<<x<<"/"<<y;
        x1 = x2, x2 = x, y1 = y2, y2 = y;
    }
    cout<<endl;
}

int main() {
    int n = 7;
    fareySequence(n);
    return 0;
}
