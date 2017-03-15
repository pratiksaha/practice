//to count no of palindromic paths
#include<bits/stdc++.h>
using namespace std;
#define R 3
#define C 4

struct cells {
    int rs, cs;
    int re, ce;
    cells(int rs, int cs, int re, int ce) :
        rs(rs), cs(cs), re(re), ce(ce) { }
    bool operator <(const cells& other) const {
        return ((rs != other.rs) || (cs != other.cs) || (re != other.re) || (ce != other.ce));
    }
};

int countPalindromicPaths(char mat[R][C], int rs, int cs, int re, int ce, map<cells, int>& memo) {
    if (rs < 0 || rs >= R || cs < 0 || cs >= C)
        return 0;
    if (re < 0 || re < rs || ce < 0 || ce < cs)
        return 0;
    if (mat[rs][cs] != mat[re][ce])
        return 0;
    if (abs((rs - re) + (cs - ce)) <= 1)
        return 1;
    if (memo.find(cells(rs, cs, re, ce)) != memo.end())
        return memo[cells(rs, cs, re, ce)];
    int ret = 0;
    ret += countPalindromicPaths(mat, rs + 1, cs, re - 1, ce, memo);
    ret += countPalindromicPaths(mat, rs + 1, cs, re, ce - 1, memo);
    ret += countPalindromicPaths(mat, rs, cs + 1, re - 1, ce, memo);
    ret += countPalindromicPaths(mat, rs, cs + 1, re, ce - 1, memo);
    memo[cells(rs, cs, re, ce)] = ret;
    return ret;
}

int countPalindromicPaths(char mat[R][C]) {
    map<cells, int> memo;
    return countPalindromicPaths(mat, 0, 0, R-1, C-1, memo);
}

int main() {
    char mat[R][C] =
    {
        'a', 'a', 'a', 'b',
        'b', 'a', 'a', 'a',
        'a', 'b', 'b', 'a'
    };
    cout<<countPalindromicPaths(mat)<<endl; 
    return 0;
}
