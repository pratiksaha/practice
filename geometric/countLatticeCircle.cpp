//to count lattice points on a circle
#include<bits/stdc++.h>
using namespace std;

int countLatticeCircle(int r) {
    if (r <= 0)
        return 0;
    int result = 4; //for (r, 0), (-r, 0), (0, r) & (0, -r)
    for (int x=1; x<r; x++) {
        int ySquare = r*r - x*x;
        int y = sqrt(ySquare);
        if (y*y == ySquare)
            result += 4;
    }
    return result;
}

int main() {
    int r = 5;
    cout<<"For circle with center at (0,0) and radius "<<r<<" no of lattice points is "<<countLatticeCircle(r)<<endl;
    return 0;
}
