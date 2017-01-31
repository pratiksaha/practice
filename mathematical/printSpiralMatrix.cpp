//to print a n x n spiral matrix
#include<bits/stdc++.h>
using namespace std;

void printSpiralMatrix(int n) {
    cout<<"Spiral clockwise matrix of size "<<n<<" :\n";
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int x;
            x = min(min(i, j), min(n-1-i, n-1-j));
            if (i <= j)
                cout<<setw(4)<<(n-2*x)*(n-2*x) - (i-x) - (j-x);

            else
                cout<<setw(4)<<(n-2*x-2)*(n-2*x-2) + (i-x) + (j-x);
        }
        cout<<endl;
    }
}

int main() {
    int n = 5;
    printSpiralMatrix(n);
    return 0;
}
