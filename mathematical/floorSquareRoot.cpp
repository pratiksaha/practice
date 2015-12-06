//to find floor(sqrt(x))
#include<bits/stdc++.h>
using namespace std;
        
int floorSquareRoot(int x)  {
    if (x==0 || x==1) 
       return x;
    int start = 1, end = x, ans;   
    while (start <= end) {        
        int mid = (start+end)/2;
        if (mid*mid == x)
            return mid;
        if (mid*mid < x) {
            start = mid + 1;
            ans = mid;
        } else {
            end = mid - 1;
        }       
    }
    return ans;
}

int main() {     
    int x = 16;
    cout<<"floor(sqrt("<<x<<")) = "<<floorSquareRoot(x)<<endl;
    return 0;   
}
