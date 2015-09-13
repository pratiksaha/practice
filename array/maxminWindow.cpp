//to find maximum of all minimums of windows of different sizes
#include<iostream>
#include<stack>
using namespace std;
 
void maxminWindow(int arr[], int n) {
    stack<int> s;
    int left[n+1]; //previous smaller
    int right[n+1]; //next smaller
    for (int i=0; i<n; i++) {
        left[i] = -1;
        right[i] = n;
    }
    for (int i=0; i<n; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        if (!s.empty())
            left[i] = s.top();
        s.push(i);
    }
    while (!s.empty()) //empty the stack
        s.pop();
    for (int i = n-1 ; i>=0 ; i-- ) {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        if(!s.empty())
            right[i] = s.top();
        s.push(i);
    }
    int ans[n+1];
    for (int i=0; i<=n; i++) //initialize
        ans[i] = 0;
    for (int i=0; i<n; i++) {
        int len = right[i] - left[i] - 1; //length of the interval
        ans[len] = max(ans[len], arr[i]);
    }
    for (int i=n-1; i>=1; i--) //fill missing entries
        ans[i] = max(ans[i], ans[i+1]);
    for (int i=1; i<=n; i++)
        cout<<"For window of size = "<<i<<" max of min is "<<ans[i]<<endl;
}

int main() {
    int arr[] = {10, 20, 30, 50, 10, 70, 30};
    maxminWindow(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
