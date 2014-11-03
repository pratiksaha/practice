//find number of pairs such that x^y > y^x
#include<iostream>
#include<algorithm>
using namespace std;

int countElement(int x, int Y[], int n, int NoOfY[]) {
    if (x == 0)
        return 0; //If x = 0, then the count of pairs for this x is 0

    if (x == 1) 
        return NoOfY[0]; //If x = 1, then the count of pairs for this x is equal to count of 0s in Y[]
 
    int* idx = upper_bound(Y, Y + n, x); //get address of first greater element in Y[0..n-1]
    int ans = (Y + n) - idx; //general rule, x smaller than y means x^y is greater than y^x
    
    ans += (NoOfY[0] + NoOfY[1]); //increase number of pairs for y=0 and y=1
 
    if (x == 2) //decrease number of pairs for x=2 and (y=4 or y=3)
        ans -= (NoOfY[3] + NoOfY[4]);
 
    if (x == 3) //increase number of pairs for x=3 and y=2
        ans += NoOfY[2];

    return ans;
}

int countPairs(int X[], int Y[], int m, int n) {
    int i;   
    int NoOfY[5] = {0}; //store counts of 0, 1, 2, 3 and 4 in array Y
    for (i=0; i<n; i++)
        if (Y[i] < 5)
            NoOfY[Y[i]]++;
 
    int temp[n];
    for(i=0; i<n; i++)
        temp[i] = Y[i];
        
    sort(temp, temp+n);
 
    int count = 0; // Initialize result
 
    for (int i=0; i<m; i++)
        count += countElement(X[i], temp, n, NoOfY);
 
    return count;
}

int main() {
    int X[] = {2, 1, 6};
    int Y[] = {1, 5};
    cout<<"Total pairs = "<<countPairs(X, Y, sizeof(X)/sizeof(X[0]), sizeof(Y)/sizeof(Y[0]))<<endl;
    return 0;
}
