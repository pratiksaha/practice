//subset sum problem TODO: print the set
#include<iostream>
using namespace std;

void subsetSum(int set[], int n, int sum) {
    bool subset[sum+1][n+1]; //subset[i][j] = true if there is a subset with sum = i
    for (int i=0; i<=n; i++)
        subset[0][i] = true; //true when sum = 0
    for (int i=1; i<=sum; i++)
        subset[i][0] = false; //false when sum = 1

    for (int i=1; i<=sum; i++) {
        for (int j=1; j<=n; j++) {
            subset[i][j] = subset[i][j-1]; //sum can be generated by a bigger set if it can be generated by a smaller set
            if (i >= set[j-1])
                subset[i][j] = subset[i][j] || subset[i - set[j-1]][j-1]; //either sum is equal to current no or we need to check if differencecan be achieved by first j-1 elements
        }
     }
     cout<<subset[sum][n]<<endl;
}

int main() {
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    subsetSum(set, sizeof(set)/sizeof(set[0]), sum);
    return 0;
}
