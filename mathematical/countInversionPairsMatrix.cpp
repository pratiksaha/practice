// count the number of inversion pairs in a matrix
#include<bits/stdc++.h>
using namespace std;
#define N 4
 
void update(int l, int r, int val, int bit[][N + 1]) {
    for (int i = l; i <= N; i += i & -i)
        for (int j = r; j <= N; j += j & -j)
            bit[i][j] += val;
}
 
long long query(int l, int r, int bit[][N + 1]) {
    long long ret = 0;
    for (int i = l; i > 0; i -= i & -i)
        for (int j = r; j > 0; j -= j & -j)
            ret += bit[i][j];
    return ret;
}

long long int countInversionPairsMatrix(int mat[][N]) {
    int bit[N+1][N+1] = {0};
    vector<pair<int, pair<int, int> > > v;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            v.push_back(make_pair(-mat[i][j], make_pair(i+1, j+1)));
    sort(v.begin(), v.end());
    long long int inv_pair_cnt = 0;
    int i = 0;
    while (i < v.size()) {
        int curr = i;
        vector<pair<int, int> > pairs;
        while (curr < v.size() && (v[curr].first == v[i].first)) {
            pairs.push_back(make_pair(v[curr].second.first, v[curr].second.second));
            inv_pair_cnt += query(v[curr].second.first, v[curr].second.second, bit);
            curr++;
        }
        vector<pair<int, int> >::iterator it;
        for (it = pairs.begin(); it != pairs.end(); it++) {
            int x = it->first;
            int y = it->second;
            update(x, y, 1, bit);
        }
        i = curr;
    } 
    return inv_pair_cnt;
}

int main() {
    int mat[N][N] = { { 4, 7, 2, 9 },
                      { 6, 4, 1, 7 },
                      { 5, 3, 8, 1 },
                      { 3, 2, 5, 6 } };
    cout<<"No of inversion pairs in the matrix is "<<countInversionPairsMatrix(mat)<<endl;
    return 0;
}
