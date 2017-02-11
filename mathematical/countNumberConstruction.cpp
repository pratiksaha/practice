//to count all numbers that can be formed using two number numbers x and y
#include<bits/stdc++.h>
using namespace std;
 
int countNumberConstruction(int n, int x, int y) {
    vector<bool> arr(n+1, false);
    if (x <= n)
        arr[x] = true;
    if (y <= n)
        arr[y] = true;
    int result = 0;
    for (int i=min(x, y); i<=n; i++) {
        if (arr[i]) { 
            if (i+x <= n)
                arr[i+x] = true;
            if (i+y <= n)
                arr[i+y] = true;
            result++;
        }
    }
    return result;
}
 
int main() {
    int n = 15, x = 5, y = 7;
    cout<<"Count of all numbers under "<<n<<" that can be formed using "<<x<<" and "<<y<<" is "<<countNumberConstruction(n, x, y)<<endl;
    return 0;
}
