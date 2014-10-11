#include<iostream>
using namespace std;
 
void printArray(int a[], int size)
{
    for(int i = 0; i<size; i++)
        cout<<*(a+i)<<" ";
    cout<<endl;
}

void compositions(int arr[], int size, int M, int K, int i)
{ 
    if (K == 0)
        printArray(arr, i);
    else if(K > 0)
    {
        int k; 
        for (k=1; k<=M; k++)
        {
            arr[i]= k;
            compositions(arr, size, M, K-k, i+1);
         }
    }
}

//prints all combinations to K using nos from 1..M
void printCompositions(int K, int M){
    int size = K;//max no of elems are K when all of them are 1s
    int *arr = new int[size]; 
    compositions(arr, size, M, K, 0);//start from 0
}

int main()
{
    int target = 5;
    int max_no = 3;
    cout<<"Different compositions of "<<target<<" formed by consecutive nos till "<<max_no<<" are\n";
    printCompositions(target, max_no);
    return 0;
}
