//Check if B is a subset of A
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

bool checkSubsetHash(int A[], int M, int B[], int N) {
    unordered_map<int, int> hash;
    int i;
    for(i=0; i<M; i++)
        hash.insert(make_pair(A[i], 1));
    for(i=0; i<N; i++)
        if (hash.find(B[i]) == hash.end())
            return false;
    return true;
}

bool checkSubset(int A[], int M, int B[], int N) {
    int i, j;
    if(M<N)
        return false;
 
    int t1[M];
    for(i=0; i<M; i++)
        t1[i] = A[i];
    int t2[N];
    for(i=0; i<N; i++)
        t2[i] = B[i];
        
    sort(t1, t1+M);
    sort(t2, t2+N);
    
    i = 0;
    j = 0;
    while(i<M && j<N) {
        if( t1[i]<t2[j] ) {
            i++;
        } else if( t1[i]>t2[j] ) {
            return false;
        } else {
            i++;
            j++;
        }
    }
  
    if(j<N)
        return false;
    else
        return true;
}

int main() {
    int arr1[] = {11, 1, 13, 21, 3, 7};
    int arr2[] = {11, 3, 7, 1};
    int arr3[] = {11, 1, 13, 21, 3, 7, 9};
    int arr4[] = {11, 3, 7, 1, 15};
    
    if( checkSubset(arr1, sizeof(arr1)/sizeof(arr1[0]), arr2, sizeof(arr2)/sizeof(arr2[0])) )
        cout<<"Subset\n";
    else
        cout<<"Not Subset\n";
        
    if(checkSubsetHash(arr1, sizeof(arr1)/sizeof(arr1[0]), arr2, sizeof(arr2)/sizeof(arr2[0])))
        cout<<"Subset\n";
    else
        cout<<"Not Subset\n";
    
    if( checkSubset(arr3, sizeof(arr3)/sizeof(arr3[0]), arr4, sizeof(arr4)/sizeof(arr4[0])) )
        cout<<"Subset\n";
    else
        cout<<"Not Subset\n";
        
    if(checkSubsetHash(arr3, sizeof(arr3)/sizeof(arr3[0]), arr4, sizeof(arr4)/sizeof(arr4[0])))
        cout<<"Subset\n";
    else
        cout<<"Not Subset\n";
    
    return 0;
}
