//to find largest rectangle with all 1s in a binary matrix
#include<bits/stdc++.h>
using namespace std;
#define R 4
#define C 4

int maxHistogram(int row[]) {
    stack<int> result;
    int top_val;
    int max_area = 0;
    int area = 0;
    int i = 0;
    while (i < C) {
        if (result.empty() || row[result.top()] <= row[i]) {
            result.push(i);
            i++;
        } else {
            top_val = row[result.top()];
            result.pop();
            area = top_val*i;
            if (!result.empty())
                area = top_val*(i-result.top()-1);
            max_area = max(area, max_area);
        }
    }
    while (!result.empty()) {
        top_val = row[result.top()];
        result.pop();
        area = top_val * i;
        if (!result.empty())
            area = top_val*(i-result.top()-1);
        max_area = max(area, max_area);
    }
    return max_area;
}

int maxSizeRectangularMatrix(int A[R][C]) {
    int result = maxHistogram(A[0]);
    for (int i=1; i<R; i++) {
        for (int j=0; j<C; j++)
            if (A[i][j])
                A[i][j] += A[i-1][j];
        result = max(result, maxHistogram(A[i]));
    }
    return result;
}

int main() {
    int A[R][C] = { {0, 1, 1, 0},
                    {1, 1, 1, 1},
                    {1, 1, 1, 1},
                    {1, 1, 0, 0},
                  };
    cout<<"Area of maximum rectangle is "<<maxSizeRectangularMatrix(A)<<endl;
    return 0;
}
