//to print coils of a matrix
#include<bits/stdc++.h>
using namespace std;

void matrixCoil(int n) {
    int m = 8*n*n;
    int coil1[m];
    coil1[0] = 8*n*n + 2*n;
    int curr = coil1[0];
    int nflg = 1, step = 2;
    int index = 1;
    while (index < m) {
        for (int i=0; i<step; i++) {
            curr = coil1[index++] = (curr - 4*n*nflg);
            if (index >= m)
                break;
        }
        if (index >= m)
            break;
        for (int i=0; i<step; i++) {
            curr = coil1[index++] = curr + nflg;
            if (index >= m)
                break;
        }
        nflg = nflg*(-1);
        step += 2;
    }
    int coil2[m];
    for (int i=0; i<8*n*n; i++)
        coil2[i] = 16*n*n + 1 -coil1[i];
    cout<<"Coil 1 : ";
    for(int i=0; i<8*n*n; i++)
        cout<<" "<<coil1[i];
    cout<<endl;
    cout<<"Coil 2 : ";
    for(int i=0; i<8*n*n; i++)
        cout<<" "<<coil2[i];
    cout<<endl;
}
 
int main() {
    int n = 1;
    matrixCoil(n);
    return 0;
}
