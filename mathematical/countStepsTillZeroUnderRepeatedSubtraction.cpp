//to count of steps until one of the two numbers become 0
#include<bits/stdc++.h>
using namespace std;

int countStepsTillZeroUnderRepeatedSubtraction(int x, int y) {
    if (x%y == 0)
        return x/y;
    else
        return x/y + countStepsTillZeroUnderRepeatedSubtraction(y, x%y);
}

int main() {
   int x = 100, y = 19;
   cout<<"No of steps until one of the two numbers become 0 for "<<x<<" & "<<y<<" is "<<countStepsTillZeroUnderRepeatedSubtraction(x, y)<<endl;
   return 0;
}
