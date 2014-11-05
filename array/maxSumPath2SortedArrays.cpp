//find the sum of the max sum path to reach from beginning of any array to end of any of the two arrays jumping only at common ones
#include<iostream>
#include<algorithm>
using namespace std;

int maxSumPath2SortedArrays(int ar1[], int m, int ar2[], int n) {
    int i=0, j=0, result=0, sum1=0, sum2=0;
    while (i < m && j < n) {
        if (ar1[i] < ar2[j]) {
            sum1 += ar1[i];
            i++;
        } else if (ar1[i] > ar2[j]) {
            sum2 += ar2[j];
            j++;
        } else {
            result += max(sum1, sum2);
            sum1 = 0;
            sum2 = 0;
            while (i<m && j<n && ar1[i]==ar2[j]) {
                result += ar1[i];
                i++;
                j++;
            }
        }
    }
    while (i < m)
        sum1 += ar1[i++];
    while (j < n)
        sum2 += ar2[j++];
    result +=  max(sum1, sum2);
    return result;
}

int main(){
    int ar1[]  = {2, 3, 7, 10, 12, 15, 30, 34};
    int ar2[] =  {1, 5, 7, 8, 10, 15, 16, 19};
    cout<<"Max Sum path from both arrays = "<<maxSumPath2SortedArrays(ar1, sizeof(ar1)/sizeof(ar1[0]), ar2, sizeof(ar2)/sizeof(ar2[0]))<<endl;
    return 0;
}
