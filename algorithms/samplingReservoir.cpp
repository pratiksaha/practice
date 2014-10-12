//Reservoir sampling algorithm
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

void printArray(int arr[], int size) {
    for (int i=0; i < size; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

int* Reservoir(int stream[], int n, int k){
    int *reservoir, i;
    reservoir = (int *)malloc(k*sizeof(int));
    for (i = 0; i < k; i++)//copy first k items to sample
        reservoir[i] = stream[i]; 
        
    srand(time(0));
    for (i=k; i < n; i++) {
        int j = rand() % (i+1);// Pick a random index from 0 to i.
        if (j < k)//replace if the randomly  picked index is smaller than k
            reservoir[j] = stream[i];
    }
    return reservoir;
}

int main()
{
    int population[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int n = sizeof(population)/sizeof(population[0]);
    int k = 5;
    int *sample;
    
    cout<<"Population is:";
    printArray(population, n);
    sample = Reservoir(population, n, k);
    cout<<"Sample is:";
    printArray(sample, k);
    free(sample);
    return 0;
}
