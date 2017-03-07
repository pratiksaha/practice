//to find maximum height of arranged coin triangle
#include<bits/stdc++.h>
using namespace std;

float squareRoot(float n) {
    float x = n;
    float y = 1;
    float e = 0.000001;
    while (x - y > e) {
        x = (x + y) / 2;
        y = n/x;
    }
    return x;
}

int maxHeightTriangle(int N) {
    int n = 1 + 8*N;
    int maxH = (-1 + squareRoot(n)) / 2;
    return maxH;
}

int main() {
    int N = 12;
    cout<<"Max height of traingle with "<<N<<" coins is "<<maxHeightTriangle(N)<<endl;
    return 0;
}
