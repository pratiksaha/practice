//to count triplets with sum smaller than a given value
#include<iostream>
using namespace std;
 
int countTripletsSumSmaller(int arr[], int n, int sum) {
    int ans = 0;
    for (int i = 0; i < n-2; i++)
        for (int j = i+1; j < n-1; j++)
            for (int k = j+1; k < n; k++)
                if (arr[i] + arr[j] + arr[k] < sum)
                    ans++;
    return ans;
}

int main() {
    int arr[] = {5, 1, 3, 4, 7};
    int sum = 12;
    cout<<countTripletsSumSmaller(arr, sizeof(arr)/sizeof(arr[0]), sum) << endl;
    return 0;
}
