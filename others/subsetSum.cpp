#include<iostream>
#include<cstdlib>
using namespace std;

//comparator for qsort
int comparator(const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

void subset_sum(int *a, int n, int K, int *s, int sn, int c_pos, int c_sum){
    int i;
    if(c_sum == K){
        for(i=0; i<sn; i++)//We have found a subset, hence print
            cout<<*(s+i)<<" ";
        cout<<endl;
        if( c_pos+1<n && c_sum-a[c_pos]+a[c_pos+1]<=K )//We are finding all possible subsets
            subset_sum(a, n, K, s, sn-1, c_pos+1, c_sum-a[c_pos]); //remove the last element and try to find another combination
    } else {
        if(c_pos<n && c_sum+a[c_pos]<=K){
            for(i=c_pos; i<n; i++){// try all possibilties from the right, since the array is sorted
                s[sn] = a[i];
                if(c_sum+a[i] <=K)//lte since we are yet to print the solution in case of equality
                    subset_sum(a, n, K, s, sn+1, i+1, c_sum+a[i]);             
            }
        }
    }
}

void generateSubsets(int *a, int n, int K){
    int *temp = new int[n];
    int i;
    int total = 0;
    for(i=0; i<n; i++) {
        *(temp+i) = *(a+i);
        total += *(a+i);
    }
    qsort(temp, n, sizeof(int), comparator);
    /*
    for(i=0; i<n; i++)
        cout<<*(temp+i)<<" ";
    cout<<endl;
    */
    int *subset = new int [n];
    int sub_size = 0;
    if(temp[0] <= K && total >= K)
        subset_sum(temp, n, K, subset, sub_size, 0, 0);
    delete[] subset;
    delete[] temp;
}


int main(){
    int arr[] = {15, 22, 14, 26, 32, 9, 16, 8};
    int K = 53;
    generateSubsets(arr, sizeof(arr)/sizeof(arr[0]), K);
    return 0;
}
