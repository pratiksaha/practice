//find the max distance covered given n vehicles each with fuel capacity x litres
#include<iostream>
using namespace std;

double maxDistance(int n, int x) {
    double dist = 0.0;
    while (n>0) {
        dist += (double)x/n; //discard one vehicle after every x/k km and fill remaining with x/n litres of fuel
        n--;
    }
    return dist;
}

int main() {
    int n = 3, x = 100;
    cout<<"Maximum distance possible with "<<n<<" vehicles each carrying "<<x<<" litres of fuel is "<<maxDistance(n, x)<<" kms\n";
    return 0;
}
