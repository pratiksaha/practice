//to find the floor and ceiling of a number in a sorted array
#include<iostream>
using namespace std;

int ceilSearch(int arr[], int low, int high, int x) {
    if(x<=arr[low]) //return first elem if x <= first elem
        return low;
    if(x>arr[high]) //return -1 if x > last elem 
        return -1;  
    int mid = (low+high)/2;
    if(arr[mid]==x) { //return mid if x == mid elem
        return mid;
    } else if(arr[mid]<x) { //either arr[mid+1] is ceil(x) or ceil lies in arr[mid+1...high] if x > arr[mid] 
        if(mid+1<=high && x<=arr[mid+1])
            return mid+1;
        else
            return ceilSearch(arr, mid+1, high, x);
    } else { //either arr[mid] is ceil(x) or ceil lies in arr[low...mid-1] if x < arr[mid]
        if(mid-1>=low && x>arr[mid-1])
            return mid;
        else    
            return ceilSearch(arr, low, mid-1, x);
    }
}

int floorSearch(int arr[], int low, int high, int x) {
    if(x<arr[low]) //return -1 if x < first elem
        return -1;
    if(x>=arr[high]) //return last elem if x >= last elem
        return high;  
    int mid = (low+high)/2;
    if(arr[mid]==x) { //return mid if x == mid elem
        return mid;
    } else if(arr[mid]>x) {//either arr[mid-1] is floor(x) or floor lies in arr[low..mid-1] if x < arr[mid]
        if(mid-1>=low && x>=arr[mid-1])
            return mid-1;
        else    
            return floorSearch(arr, low, mid-1, x);
    } else { //either arr[mid] is floor(x) or floor lies in arr[mid+1...high] if x > arr[mid]
        if(mid+1<=high && x<arr[mid+1])
            return mid;
        else
            return floorSearch(arr, mid+1, high, x);  
    }
}

int main() {
    int arr[] = {4, 6, 8, 10, 12, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    int n1=2, n2=20, n3=10, n4=7, n5=17;
    cout<<"Input Array :";
    for (int i=0; i<n; i++)
        cout<<" "<<arr[i];
    cout<<endl;
    cout<<"For "<<n1<<" Ceiling Index = "<<ceilSearch(arr, 0, n-1, n1)<<" Floor Index = "<<floorSearch(arr, 0, n-1, n1)<<endl;
    cout<<"For "<<n2<<" Ceiling Index = "<<ceilSearch(arr, 0, n-1, n2)<<" Floor Index = "<<floorSearch(arr, 0, n-1, n2)<<endl;
    cout<<"For "<<n3<<" Ceiling Index = "<<ceilSearch(arr, 0, n-1, n3)<<" Floor Index = "<<floorSearch(arr, 0, n-1, n3)<<endl;
    cout<<"For "<<n4<<" Ceiling Index = "<<ceilSearch(arr, 0, n-1, n4)<<" Floor Index = "<<floorSearch(arr, 0, n-1, n4)<<endl;
    cout<<"For "<<n5<<" Ceiling Index = "<<ceilSearch(arr, 0, n-1, n5)<<" Floor Index = "<<floorSearch(arr, 0, n-1, n5)<<endl;
    return 0;
}
