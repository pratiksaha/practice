//Max Sum Rectangle
#include<iostream>
#include<cstring>
#include<climits>
#include<iomanip>
using namespace std;
#define R 4
#define C 5
#define W 3

int maxSumArray(int* arr, int* beg, int* end, int n) {
    int i;
    int sum = 0;
    int maxSum = INT_MIN;
    *end = -1;
    int cur_beg = 0;
    for (i=0; i<n; i++) {
        sum += arr[i];
        if (sum < 0) {
            sum = 0;
            cur_beg = i+1;
        } else if (sum > maxSum) {
            maxSum = sum;
            *beg = cur_beg;
            *end = i;
        }
    }
    if (*end != -1)
        return maxSum;
    maxSum = arr[0];
    *beg= *end = 0;
    for (i=1; i<n; i++) {
        if (arr[i] > maxSum) {
            maxSum = arr[i];
            *beg = *end = i;
        }
    }
    return maxSum;
}

void maxSumRectangle(int M[R][C]) {
    int maxSum = INT_MIN;
    int fl, fr, ft, fb;
 
    int l, r, i, j;
    int temp[R], sum, beg, end;
    for (l=0; l<C; l++) {
        memset(temp, 0, sizeof(temp));
        for (r=l; r<C; r++) {
            for (i = 0; i < R; ++i)
                temp[i] += M[i][r];
            sum = maxSumArray(temp, &beg, &end, R);
            if (sum > maxSum) {
                maxSum = sum;
                fl = l;
                fr = r;
                ft = beg;
                fb = end;
            }
        }
    }
    cout<<"Input Matrix :\n";
    for (i=0; i<R; i++) {
        for (j=0; j<C; j++) {
            cout<<setw(W)<<M[i][j];
        }
        cout<<endl;
    }
    cout<<"Max Sum Rectangle indices are ("<<ft<<","<<fl<<") & ("<<fb<<","<<fr<<") with sum = "<<maxSum<<endl;
    for (i=fl; i<=fr; i++) {
        for (j=ft; j<=fb; j++) {
            cout<<setw(W)<<M[i][j];
        }
        cout<<endl;
    }
}

int main() {
    int M[R][C] = {{1, 2, -1, -4, -20},
                   {-8, -3, 4, 2, 1},
                   {3, 8, 10, 1, 3},
                   {-4, -1, 1, 7, -6}};
    maxSumRectangle(M);
    return 0;
}
