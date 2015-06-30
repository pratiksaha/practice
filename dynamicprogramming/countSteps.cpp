//to count number of ways to reach nth stair when a person can climb 1, 2, ..m stairs at a time
#include<iostream>
using namespace std;

int countSteps(int n, int m) {
    int res[n+1];
    res[0] = 1; res[1] = 1;
    for (int i=2; i<=n; i++) {
        res[i] = 0;
        for (int j=1; j<=m && j<=i; j++)
            res[i] += res[i-j];
    }
    return res[n];
}

int main() {
    int n = 4, m = 3;
    cout<<"No off ways to climb "<<n<<" steps taking 1.."<<m<<" steps at a at a time is "<<countSteps(n, m)<<endl;
    return 0;
}
