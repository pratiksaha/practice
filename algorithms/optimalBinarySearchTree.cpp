//Optimal Binary Search Tree Problem TODO: reduce to O(n^3) and print tree
#include<iostream>
#include<climits>
using namespace std;

int sum(int *freq, int i, int j) {
    int s = 0;
    for (int k=i; k<=j; k++)
        s += freq[k];
    return s;
}

void optimalBinarySearchTree(int keys[], int freq[], int n) {
    int cost[n][n]; //cost[i][j] = Optimal cost of binary search tree that can be formed from keys[i] to keys[j]
    for (int i=0; i<n; i++) //cost is equal to frequency of the key for a single key
        cost[i][i] = freq[i];
    for (int L=2; L<=n; L++) { //consider chains of length 2, 3 and so on
        for (int i=0; i<=n-L+1; i++) {//i = row index
            int j = i+L-1; //j = col index
            cost[i][j] = INT_MAX;
            for (int r=i; r<=j; r++) { //try making all keys in interval keys[i..j] as root
                int c = ((r>i)?cost[i][r-1]:0) + ((r<j)?cost[r+1][j]:0) + sum(freq, i, j);
                if (c<cost[i][j])
                    cost[i][j] = c;
            }
        }
    }
    cout<<"Cost of optimal binary search tree is "<<cost[0][n-1]<<endl;
}

int main() {
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    optimalBinarySearchTree(keys, freq, sizeof(keys)/sizeof(keys[0]));
    return 0;
}
