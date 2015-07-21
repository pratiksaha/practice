//to find maximum product pair in an array
#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

void maxProductPair(int arr[], int n) {
    cout<<"For Input Array :";
    for (int i=0; i<n; i++)
        cout<<" "<<arr[i];
    if (n<2) {
        cout<<" No pairs exists\n";
    } else if (n == 2) {
        cout<<" Max product pair is {"<<arr[0]<<","<<arr[1]<<"}\n";
    } else {
        int posa = 0;
        int posb = 0;
        int nega = 0;
        int negb = 0;
        for (int i=0; i<n; i++) {
            if (arr[i] > 0 && arr[i] > posa) {
                posb = posa;
                posa = arr[i];
            } else if (arr[i] > 0 && arr[i] > posb) {
                posb = arr[i];
            }
            if (arr[i] < 0 && abs(arr[i]) > abs(nega)) {
                negb = nega;
                nega = arr[i];
            } else if(arr[i] < 0 && abs(arr[i]) > abs(negb)) {
                negb = arr[i];
            }
        }
        cout<<" Max product pair is {";
        if (nega*negb > posa*posb)
            cout<<nega<<","<<negb;
        else
            cout<<posa<<","<<posb;
        cout<<"}\n";
    }
}

int main() {
    int arr[] = {1, 4, 3, 6, 7, 0};
    maxProductPair(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
