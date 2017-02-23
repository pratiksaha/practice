//to find max & min possible sums of two numbers that we can get if replacing digit from 5 to 6 and viceversa
#include<bits/stdc++.h>
using namespace std;

int replaceDigit(int x, int from, int to) {
    int result = 0;
    int multiply = 1;
    while (x % 10 > 0) {
        int reminder = x % 10;
        if (reminder == from)
            result += to * multiply;
        else
            result += reminder * multiply;
        multiply *= 10;
        x /= 10;
    }
    return result;
}
 
void calcMinMaxSumReplace56(int x1, int x2) {
    int minSum = replaceDigit(x1, 6, 5) + replaceDigit(x2, 6, 5);
    int maxSum = replaceDigit(x1, 5, 6) + replaceDigit(x2, 5, 6);
    cout<<"Min sum : "<<minSum<<" Max sum : "<<maxSum<<endl;
}

int main() {
    int x1 = 5466, x2 = 4555;
    calcMinMaxSumReplace56(x1, x2);
    return 0;
} 
