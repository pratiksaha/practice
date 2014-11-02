#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
 
void minJumps(int arr[], int n) {
    int i, j;
    if (n==0 || arr[0]==0) {
        cout<<"Not possible"<<endl;
    } else {
        int jumps[n]; //jumps[i] = min jumps req to reach 0 to i
        jumps[0] = 0;
        for (i=1; i<n; i++) {
            jumps[i] = INT_MAX;
            for (j=0; j<i; j++) {
                if (i<=(j + arr[j]) && jumps[j] != INT_MAX) {
                    jumps[i] = min(jumps[i], jumps[j] + 1);
                    break;
                }
            }
        }
        cout<<"No of jumps = "<<jumps[n-1]<<endl;
    }
}
 
int main() {
  int a[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
  int b[] = {1, 3, 6, 1, 0, 9};
  minJumps(a, sizeof(a)/sizeof(a[0]));
  minJumps(b, sizeof(b)/sizeof(b[0]));
  return 0;
}
