//no of groups in an array which are divisible by 3
#include<iostream>
using namespace std;
 
int findgroups(int arr[], int n)
{
    int c[3] = {0};
    int i;
    int res = 0;
    for (i=0; i<n; i++)
        c[arr[i]%3]++;//Count elements with remainder 0, 1 and 2

    res += ((c[0]*(c[0]-1))>>1);//Count groups of size 2 from 0 remainder elements  
    res += c[1] * c[2];//Count groups of size 2 with one element with 1 remainder and other with 2 remainder   
    res += (c[0] * (c[0]-1) * (c[0]-2))/6;//Count groups of size 3 with all 0 remainder elements   
    res += (c[1] * (c[1]-1) * (c[1]-2))/6;//Count groups of size 3 with all 1 remainder elements    
    res += ((c[2]*(c[2]-1)*(c[2]-2))/6);//Count groups of size 3 with all 2 remainder elements
    res += c[0]*c[1]*c[2];//Count groups of size 3 with different remainders

    return res;
}

int main()
{
    int arr[] = {3, 6, 7, 2, 9};
    cout<<"Required number of groups are "<<findgroups(arr, sizeof(arr)/sizeof(arr[0])<<endl;
    return 0;
}
