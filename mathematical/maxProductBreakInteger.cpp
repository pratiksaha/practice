//to find maximum product by breaking an integer
#include<bits/stdc++.h>
using namespace std;

int maxProductBreakInteger(int N) {
    if (N == 2)
        return 1;
    if (N == 3)
        return 2;
    int maxProduct;
    switch (N % 3) {
        case 0:
            maxProduct = pow(3, N/3);
            break;
        case 1:
            maxProduct = 2 * 2 * pow(3, (N/3) - 1);
            break;
        case 2:
            maxProduct = 2 * pow(3, N/3);
            break;
    }
    return maxProduct;
}
 
int main() {
    int n = 10;
    cout<<"maximum product by breaking "<<n<<" is "<<maxProductBreakInteger(n)<<endl;
    return 0;
}
