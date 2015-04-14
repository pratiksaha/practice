//to find min and max value in an array
#include<iostream>
using namespace std;

struct pairs {
    int min, max;
};  

struct pairs getMinMaxTournament(int arr[], int low, int high) {
    struct pairs minmax;       
    if (low == high) { //if there is only on element
        minmax.max = arr[low];
        minmax.min = arr[low];     
    } else if (high == low + 1) { //if there are two elements 
        if (arr[low] > arr[high]) {
            minmax.max = arr[low];
            minmax.min = arr[high];
        } else {
            minmax.max = arr[high];
            minmax.min = arr[low];
        }  
    } else {
        int mid = (low+high)/2;  
        struct pairs mml = getMinMaxTournament(arr, low, mid);
        struct pairs mmr = getMinMaxTournament(arr, mid+1, high);  
        if (mml.min < mmr.min)
            minmax.min = mml.min;
        else
            minmax.min = mmr.min;
        if (mml.max > mmr.max)
            minmax.max = mml.max;
        else
            minmax.max = mmr.max;     
    }
    return minmax;
}
 
struct pairs getMinMax(int arr[], int n) {
    struct pairs minmax;
    int i; //index of loop
    if (n%2 == 0) { //initialize the first two elements as min and max if array has even no of elems
        if (arr[0] > arr[1]) {
            minmax.max = arr[0];
            minmax.min = arr[1];
        } else {
            minmax.min = arr[0];
            minmax.max = arr[1];
        }
        i = 2;
    } else {
        minmax.min = arr[0];
        minmax.max = arr[0];
        i = 1;
    }
    while (i < n-1) { //pick elements in pair and compare the pair      
        if (arr[i] > arr[i+1]) {
            if(arr[i] > minmax.max)   
                minmax.max = arr[i];
            if(arr[i+1] < minmax.min)          
                minmax.min = arr[i+1];        
        } else {
            if (arr[i+1] > minmax.max)
                minmax.max = arr[i+1];
            if (arr[i] < minmax.min)          
                minmax.min = arr[i];        
        }        
        i += 2;
    }
    return minmax;
}    

int main() {
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int n = 6;
    struct pairs minmaxTournament = getMinMaxTournament(arr, 0, n-1);
    struct pairs minmax = getMinMax(arr, n);
    cout<<"By Tournament method (Min,Max) = "<<minmaxTournament.min<<" "<<minmaxTournament.max<<endl;
    cout<<"By Pairwise method (Min,Max) = "<<minmax.min<<" "<<minmax.max<<endl;
    return 0;
}
