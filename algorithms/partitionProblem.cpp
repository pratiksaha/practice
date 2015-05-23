//partition problem TODO:print partition
#include<iostream>
using namespace std;

void partitionProblem(int *set, int n) {
    int sum = 0;
    for (int i=0; i<n; i++)
        sum += set[i];
    if (sum%2 == 0) {
        bool part[sum/2+1][n+1]; //similar to subset sum problem
        for (int i=0; i<=n; i++)
            part[0][i] = true;
        for (int i=1; i<=sum/2; i++)
            part[i][0] = false;
        for (int i=1; i<=sum/2; i++) {
            for (int j = 1; j <= n; j++) {
                part[i][j] = part[i][j-1];
                if (i>=set[j-1])
                    part[i][j] = part[i][j] || part[i - set[j-1]][j-1];
            }
        }
        cout<<part[sum/2][n]<<endl;
     } else {
        cout<<false<<endl;
     }
}

int main() {
    int set[] = {3, 1, 1, 2, 2, 1};
    partitionProblem(set, sizeof(set)/sizeof(set[0]));
    return 0;
}
