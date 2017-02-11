//to find length of the longest consecutive 1s in binary reprsentation of a number
#include<bits/stdc++.h>
using namespace std;
 
int lengthMaxConsecutiveOnes(int x) {
    int count = 0;
    while (x!=0) {
        x = (x & (x << 1));
        count++;
    }
    return count;
}
 
int main() {
    int n = 14;
    cout<<"length of the longest consecutive 1s in binary reprsentation of "<<n<<" is "<<lengthMaxConsecutiveOnes(n)<<endl;
    n = 222;
    cout<<"length of the longest consecutive 1s in binary reprsentation of "<<n<<" is "<<lengthMaxConsecutiveOnes(n)<<endl;
    return 0;
}
