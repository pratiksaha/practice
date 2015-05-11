//stable marriage problem
#include<iostream>
#include<cstring>
using namespace std;
#define N 4

bool wPreferscurrMOverM(int Girl[N][N], int w, int m, int currm) {
    for (int i=0; i<N; i++) {
        if (Girl[w][i] == currm)
            return true;
        if (Girl[w][i] == m)
           return false;
    }
}

void stableMarriage(int Boy[N][N], int Girl[N][N]) {
    int wPartner[N];
    memset(wPartner, -1, sizeof(wPartner));
    bool mFree[N];
    memset(mFree, false, sizeof(mFree));
    int free = N;
    while (free > 0) { //while there are free men
        int m;
        for (m=0; m < N; m++)
            if (mFree[m] == false) //pick the first free man
                break;
        for (int i = 0; i<N && mFree[m]==false; i++) { //go to all women according to m's preferences
            int w =Boy[m][i];
            if (wPartner[w] == -1) { //w and m become partners if woman of preference is free
                wPartner[w] = m;
                mFree[m] = true;
                free--;
            } else {
                int currm = wPartner[w]; //curr engagement of w
                if (!wPreferscurrMOverM(Girl, w, m, currm)) { //break the engagement if w prefers m over currm
                    wPartner[w] = m;
                    mFree[m] = true;
                    mFree[currm] = false;
                }
            }
        }
    }
    cout<<"Woman  Man"<<endl;
    for (int i=0; i<N; i++)
       cout<<i<<"\t"<<wPartner[i]<<endl;
}

int main() {
    int preferenceBoy[N][N] = { {3, 1, 2, 0},
                                {1, 0, 2, 3},
                                {0, 1, 2, 3},
                                {0, 1, 2, 3},
                              };
    int preferenceGirl[N][N] = {{0, 1, 2, 3},
                                {0, 1, 2, 3},
                                {0, 1, 2, 3},
                                {0, 1, 2, 3},
                               };
    stableMarriage(preferenceBoy, preferenceGirl);
    return 0;
}
