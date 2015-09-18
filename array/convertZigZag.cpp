//to sort an array in ZigZag form
#include <iostream>
using namespace std;

void convertZigZag(int arr[], int n) {
    bool flag = true; //true means < and flase means >
    for (int i=0; i<=n-2; i++) {
        if (flag) {
            if (arr[i] > arr[i+1])
                swap(arr[i], arr[i+1]);
        } else {
            if (arr[i] < arr[i+1])
                swap(arr[i], arr[i+1]);
        }
        flag = !flag;
    }
}

int main() {
    int  arr[] = {4, 3, 7, 8, 6, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Input Array :";
    for (int i=0; i<n; i++)
        cout<<" "<<arr[i];
    cout<<endl;
    convertZigZag(arr, n);
    cout<<"Output Array :";
    for (int i=0; i<n; i++)
        cout<<" "<<arr[i];
    cout<<endl;
    return 0;
}
