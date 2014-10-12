#include <iostream>
using namespace std;
 
// returns value of poly[0]*x^(n-1) + poly[1]*x^(n-2) + .. + poly[n-1]
int horner(int poly[], int n, int x)
{
    int result = poly[0];    
    for (int i=1; i<n; i++)//Horner's method
        result = result*x + poly[i]; 
    return result;
}
 
int main() {
    // Let us evaluate value of 2x3 - 6x2 + 2x - 1 for x = 3
    int poly[] = {2, -6, 2, -1};
    int x = 3;
    cout<<"Value of polynomial is " <<horner(poly, sizeof(poly)/sizeof(poly[0]), x)<<endl;
    return 0;
}
