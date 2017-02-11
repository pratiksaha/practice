//to find out all combinations of positive numbers that add upto given number
#include<bits/stdc++.h>
using namespace std;

void findCombinationsThatAddToN(int arr[], int index, int num, int reducedNum) {
    if (reducedNum < 0)
        return;
    if (reducedNum == 0) {
        for (int i = 0; i < index; i++)
            cout<<" "<<arr[i];
        cout<<endl;
        return;
    }
    int prev = (index == 0)? 1 : arr[index-1];
    for (int k = prev; k <= num ; k++) {
        arr[index] = k;
        findCombinationsThatAddToN(arr, index + 1, num, reducedNum - k);
    }
}

void findCombinationsThatAddToN(int n) {
    int arr[n];
    cout<<"All combinations that add to "<<n<<" are :\n";
    findCombinationsThatAddToN(arr, 0, n, n);
}

int main() {
    int n = 5;
    findCombinationsThatAddToN(n);
    return 0;
}
