//to count number of ways to cover a distance with 1, 2 and 3 steps
#include<iostream>
using namespace std;
 
int countWaysToDistance(int dist) {
    int count[dist+1];
    count[0] = 1, count[1] = 1, count[2] = 2;
    for (int i=3; i<=dist; i++)
        count[i] = count[i-1] + count[i-2] + count[i-3];
    return count[dist];
}

int main() {
    int dist = 4;
    cout<<"No of ways to cover "<<dist<<" distance = "<<countWaysToDistance(dist)<<endl;
    return 0;
}
