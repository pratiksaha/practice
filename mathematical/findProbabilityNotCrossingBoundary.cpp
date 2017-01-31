//to find the probability that we do not cross boundary of a matrix after N moves
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int m, int n) {
    return (x >= 0 && x < m && y >= 0 && y < n);
}

double findProbabilityNotCrossingBoundary(int m, int n, int x, int y, int N) {
    if (!isSafe(x, y, m, n))
        return 0.0;
    if (N == 0)
        return 1.0;
    double prob = 0.0;
    prob += findProbabilityNotCrossingBoundary(m, n, x - 1, y, N - 1) * 0.25;
    prob += findProbabilityNotCrossingBoundary(m, n, x, y + 1, N - 1) * 0.25;
    prob += findProbabilityNotCrossingBoundary(m, n, x + 1, y, N - 1) * 0.25;
    prob += findProbabilityNotCrossingBoundary(m, n, x, y - 1, N - 1) * 0.25;
    return prob;
}

int main() {
    int m = 5, n = 5;
    int i = 1, j = 1;
    int N = 2;
    cout<<"Probability of not crossing the boundary with "<<N<<" moves starting at ("<<i<<","<<j<<") is "<<findProbabilityNotCrossingBoundary(m, n, i, j, N)<<endl;
    return 0;
}
