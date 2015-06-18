//to generate n-bit Gray codes
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void grayCode(int n) {
    cout<<n<<"-bit Gray Codes :\n";
    if (n <= 0)
        return;
    vector<string> arr;
    arr.push_back("0");
    arr.push_back("1");
    int i, j;
    for (int i=2; i<(1<<n); i=i<<1) {
        for (int j=i-1; j>=0; j--)
            arr.push_back(arr[j]); //add prev in reverse order
        for (int j=0; j<i; j++)
            arr[j] = "0" + arr[j]; //append 0 to first half
        for (int j=i; j<2*i; j++)
            arr[j] = "1" + arr[j]; //append 1 to second half
    }
    for (i=0; i<arr.size(); i++ )
        cout<<arr[i]<<endl;
}

int main() {
    grayCode(4);
    return 0;
}
