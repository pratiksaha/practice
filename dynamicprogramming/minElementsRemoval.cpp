//Find the minimum of elements to be removed from either end in arr[l..h] so that 2*min becomes greater than max.
#include<iostream>
#include<climits>
using namespace std;

void minRemovalDP(int arr[], int n) {
    int i, j;
    int start = -1;
    int end = 0;

    for (i=0; i<n; i++) { //choose starting point     
        int curr_min = INT_MAX;
        int curr_max = INT_MIN;   
        for (j=i; j<n; j++) { //choose ending points
            int val = arr[j];
            if (val < curr_min)
                curr_min = val;
            if (val > curr_max) 
                curr_max = val;
            if (2*curr_min <= curr_max)
                break;
            if ( (j-i>end-start) || (start == -1) ) {
                start = i;
                end = j;
            }
        }
    }

    cout<<"Input Array :";
    for (i=0; i<n; i++)
        cout<<" "<<arr[i];
    cout<<endl;
    if (start == -1) {
        cout<<"No of elements to remove= "<<n<<endl;
        cout<<"After removal array is empty\n";
    } else {
        cout<<"No of elements to remove = "<<n-(end-start+1)<<endl;
        cout<<"After removal array is :";
        for (i=start; i<=end; i++)
            cout<<" "<<arr[i];
        cout<<endl;
    }
}

int main() {
    int a[] = {4, 5, 100, 9, 10, 11, 12, 15, 200};
    int b[] = {20, 4, 1, 3};
    minRemovalDP(a, sizeof(a)/sizeof(a[0]));
    minRemovalDP(b, sizeof(b)/sizeof(b[0]));
    return 0;
}
