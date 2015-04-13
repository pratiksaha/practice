//to minimize the cash flow among a set of persons
#include<iostream>
#include<cstdlib>
using namespace std;
#define N 3

int getMin(int arr[]) {
    int minInd = 0;
    for (int i=1; i<N; i++)
        if (arr[i] < arr[minInd])
            minInd = i;
    return minInd;
}

int getMax(int arr[]) {
    int maxInd = 0;
    for (int i=1; i<N; i++)
        if (arr[i] > arr[maxInd])
            maxInd = i;
    return maxInd;
}

void minCashFlowUtil(int amount[]) {
    int mxCredit = getMax(amount);
    int mxDebit = getMin(amount);
    if (amount[mxCredit] != 0 || amount[mxDebit] != 0)  {//all amounts are settled if both amounts are 0
        int min_val = min(-amount[mxDebit], amount[mxCredit]);
        amount[mxCredit] -= min_val;
        amount[mxDebit] += min_val;
        cout<<"Person "<<mxDebit<<" pays "<<min_val<<" to Person "<<mxCredit<<endl;
        minCashFlowUtil(amount);
    }
}

void minCashFlow(int graph[][N]) {
    int amount[N] = {0}; //amount[p] indicates the net amount to be credited/debited to/from person 'p'
    for (int p=0; p<N; p++)
        for (int i=0; i<N; i++)
            amount[p] += (graph[i][p] -  graph[p][i]);
    minCashFlowUtil(amount);
}

int main() {
    int graph[N][N] = { {0, 1000, 2000},
                        {0, 0, 5000},
                        {0, 0, 0}
                      }; //graph[i][j] indicates the amount that person i needs to pay person j
    minCashFlow(graph);
    return 0;
}
