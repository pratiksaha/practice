//to find Pythagorean Triplets in an array
#include<iostream>
#include<algorithm>
using namespace std;

void pythagoreanTriplet(int arr[], int n) {
    int squares[n], temp[n];
    cout<<"Input Array :";
    for (int i=0; i<n; i++) {
        cout<<" "<<arr[i];
        temp[i] = arr[i];
        squares[i] = arr[i]*arr[i];
    }
    cout<<"\nPythagorean Triplets :";
    sort(temp, temp+n);
    sort(squares, squares+n);
    for (int i=n-1; i>=2; i--) {
        int l=0, r=i-1;
        while (l<r) {
            if (squares[l]+squares[r] == squares[i]) //triplet found
                cout<<" ("<<temp[l]<<","<<temp[r]<<","<<temp[i]<<")";
            (squares[l]+squares[r] < squares[i])? l++: r--;
        }
    }
    cout<<endl;
}

int main() {
    int arr[] = {3, 1, 10, 4, 6, 5, 8};
    pythagoreanTriplet(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
