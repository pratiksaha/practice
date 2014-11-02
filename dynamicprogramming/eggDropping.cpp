//Egg dropping problem
#include<iostream>
#include<cstdlib>
#include<climits>
using namespace std;

int eggDrop(int eggs, int floors) { 
    int EF[eggs+1][floors+1]; //EF[i][j] = min no of trials needed for i eggs and j floors
    int res;
    int i, j, x;
 
    for (i=1; i<=eggs; i++) {
        EF[i][1] = 1; //1 trial for 1 floor
        EF[i][0] = 0; //0 trials for 0 floors
    }

    for (j=1; j<=floors; j++)
        EF[1][j] = j; //j trials for one egg and j floors
 
    for (i=2; i<=eggs; i++) {
        for (j=2; j<=floors; j++) {
            EF[i][j] = INT_MAX;
            for (x=1; x<=j; x++) {
                res = 1 + max(EF[i-1][x-1], EF[i][j-x]);
                if (res < EF[i][j])
                    EF[i][j] = res;
            }
        }
    }
    return EF[eggs][floors];
}

int main() {
    int n = 2, k = 36;
    cout<<"Minimum number of trials in worst case with "<<n<<" eggs and "<<k<<" floors is "<<eggDrop(n, k)<<endl;
    return 0;
}
