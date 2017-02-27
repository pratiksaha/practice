//to find if there is a pair with given product
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
using namespace std;
 
bool checkProductPair(int arr[], int n, int x) {
    if (n < 2)
        return false;
    unordered_set<int> s;
    for (int i=0; i<n; i++) {
        if (arr[i] == 0) {
           if (x == 0)
               return true;
           else
               continue;
        }
        if (x%arr[i] == 0) {
            if (s.find(x/arr[i]) != s.end())
                return true;
            s.insert(arr[i]);
        }
    }
    return false;
}
 
int main() {
    int arr[] = {10, 20, 9, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 400;
    cout<<"There"<<(checkProductPair(arr, n, x) ? " is " : " is no ")<<"product with value "<<x<<endl;
    x = 190;
    cout<<"There"<<(checkProductPair(arr, n, x) ? " is " : " is no ")<<"product with value "<<x<<endl;
    return 0;
}
