//to find  maximum possible determinant of 0/n matrix
#include <bits/stdc++.h>
using namespace std;
 
int maxDeterminant0NMatrix(int n) {
    return (2*n*n*n);
}
 
void resultMatrix(int n) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 0 && j == 2)
                cout<<setw(4)<<"0";
            else if (i == 1 && j == 0)
                cout<<setw(4)<<"0";
            else if (i == 2 && j == 1)
                cout<<setw(4)<<"0";
            else
                cout<<setw(4)<<n;
        }
        cout<<endl;
    }
}

int main() {
    int n = 15;
    cout<<"Maximum Determinant for a 0/n matrix with n = "<<n<<" is "<<maxDeterminant0NMatrix(n)<<" and the matrix is :\n";
    resultMatrix(n);
    return 0;
}
