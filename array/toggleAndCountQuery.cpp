//to implement toggle and count queries on a binary array
#include<bits/stdc++.h>
using namespace std;
#define MAX 100000

int tree[MAX] = {0};

bool lazy[MAX] = {false};

void toggle(int node, int st, int en, int us, int ue) {
    if (lazy[node]) {
        lazy[node] = false;
        tree[node] = en - st + 1 - tree[node];
        if (st < en) {
            lazy[node<<1] = !lazy[node<<1];
            lazy[1+(node<<1)] = !lazy[1+(node<<1)];
        }
    }
    if (st>en || us > en || ue < st)
        return ;
    if (us<=st && en<=ue) {
        tree[node] = en-st+1 - tree[node];
        if (st < en) {
            lazy[node<<1] = !lazy[node<<1];
            lazy[1+(node<<1)] = !lazy[1+(node<<1)];
        }
        return;
    }
    int mid = (st+en)/2;
    toggle((node<<1), st, mid, us, ue);
    toggle((node<<1)+1, mid+1,en, us, ue);
    if (st < en)
        tree[node] = tree[node<<1] + tree[(node<<1)+1];
}

int countQuery(int node, int st, int en, int qs, int qe) {
    if (st>en || qs > en || qe < st)
        return 0;
    if (lazy[node]) {
        lazy[node] = false;
        if (st<en) {
            lazy[node<<1] = !lazy[node<<1];
            lazy[(node<<1)+1] = !lazy[(node<<1)+1];
        }
    }
    if (qs<=st && en<=qe)
        return tree[node];
    int mid = (st+en)/2;
    return countQuery((node<<1), st, mid, qs, qe) + countQuery((node<<1)+1, mid+1, en, qs, qe);
}

int main() {
    int n = 5;
    toggle(1, 0, n-1, 1, 2);
    toggle(1, 0, n-1, 2, 4);
    cout<<countQuery(1, 0, n-1, 2, 3)<<endl;
    toggle(1, 0, n-1, 2, 4);
    cout<<countQuery(1, 0, n-1, 1, 4)<<endl;
    return 0;
}
