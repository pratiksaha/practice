//solve Linear Equations
#include<bits/stdc++.h>
using namespace std;
#define N 3

void displayMatrix(double mat[N][N+1]) {
    for (int i=0; i<N; i++, cout<<endl)
        for (int j=0; j<=N; j++)
            cout<<setw(5)<<mat[i][j];
}

void swap_row(double mat[N][N+1], int i, int j) {
    for (int k=0; k<=N; k++) {
        double temp = mat[i][k];
        mat[i][k] = mat[j][k];
        mat[j][k] = temp;
    }
}

int forwardElimination(double mat[N][N+1]) {
    for (int k=0; k<N; k++) {
        int i_max = k;
        int v_max = mat[i_max][k];
        for (int i=k+1; i<N; i++)
            if (abs(mat[i][k])>v_max)
                v_max = mat[i][k], i_max = i;
        if (!mat[k][i_max])
            return k;
        if (i_max != k)
            swap_row(mat, k, i_max);
        for (int i=k+1; i<N; i++) {
            double f = mat[i][k]/mat[k][k];
            for (int j=k+1; j<=N; j++)
                mat[i][j] -= mat[k][j]*f;
            mat[i][k] = 0;
        }
    }
    return -1;
}

void backSubstitution(double mat[N][N+1]) {
    double x[N];
    for (int i=N-1; i>=0; i--) {
        x[i] = mat[i][N];
        for (int j=i+1; j<N; j++)
            x[i] -= mat[i][j]*x[j];
        x[i] = x[i]/mat[i][i];
    }
    cout<<"Solution for the system :";
    for (int i=0; i<N; i++)
        cout<<" "<<x[i];
    cout<<endl;
}

void solveLinearGaussianElimination(double mat[N][N+1]) {
    cout<<"Solving Given System of Linear Equations by Guassian Elimination:\n";
    displayMatrix(mat);
    int singular_flag = forwardElimination(mat);
    if (singular_flag != -1) {
        cout<<"Singular Matrix\n";
        if (mat[singular_flag][N])
            cout<<"Inconsistent System\n";
        else
            cout<<"Infinitely Many Solutions\n";
    } else {
        backSubstitution(mat);
    }
}

int main() {
    double mat[N][N+1] = {{3.0, 2.0,-4.0, 3.0},
                          {2.0, 3.0, 3.0, 15.0},
                          {5.0, -3, 1.0, 14.0}
                         };
 
    solveLinearGaussianElimination(mat);
    return 0;
}
