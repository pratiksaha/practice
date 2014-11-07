//find the max for all subarrays of size k
#include<iostream>
#include<deque> 
using namespace std;
 
void maxK(int arr[], int n, int k) {
    deque<int>  window(k); //Double Ended Queue that will store indexes of useful elems in every window maintained in decreasing order

    int i=0;
    while(i<k) { //first k elems
        while ( (!window.empty()) && arr[i] >= arr[window.back()]) //previous smaller elements are useless
            window.pop_back(); //remove from rear
        window.push_back(i);
        i++;
    }
 
    while(i<n) { //remaining elems
        cout<<arr[window.front()]<<endl; //elem at the front of the queue is the largest elem of previous window
        while ( (!window.empty()) && window.front() <= i-k) //remove elems which are out of curr window
            window.pop_front();
        while ( (!window.empty()) && arr[i] >= arr[window.back()]) //remove all elements smaller than the curr elem
            window.pop_back(); 
        window.push_back(i);
        i++;
    }
    cout<<arr[window.front()]<<endl;
}

int main() {
    int arr[] = {12, 1, 78, 90, 57, 89, 56};
    maxK(arr, sizeof(arr)/sizeof(arr[0]), 3);
    return 0;
}
