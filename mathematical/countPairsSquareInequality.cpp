//to find different (x, y) pairs that satisfy x*x + y*y < n.
#include<iostream>
using namespace std;

int countPairsSquareInequality(int n) {
    int x = 0, yCount, res = 0;
    for (yCount = 0; yCount*yCount < n; yCount++); //count of different y values for x = 0
    while (yCount != 0) {//one by one increase value of x, and find yCount for current x
        res +=  yCount;
        x++;
        while (yCount != 0 && (x*x + (yCount-1)*(yCount-1) >= n))
            yCount--;
    }
    return res;
}

int main() {
    cout<<"Total Number of distinct non-negative pairs (x,y) that satisfy x*x+y*y<n is "<<countPairsSquareInequality(6)<<endl;
    return 0;
}
