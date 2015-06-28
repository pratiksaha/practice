//to find the amount of water in jth glass of ith row
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cassert>
using namespace std;

float waterGlass(int i, int j, float X) {
    assert(i<=j); //row number i has maximum i columns
    float glass[i*(i+1)/2]; //total i*(i+1)/2 glasses till ith row (including ith row)
    memset(glass, 0, sizeof(glass)); //all glasses as empty
    int idx= 0;
    glass[idx] = X; //put all water in first glass
    for (int row=1; row<=i && X !=0.0; row++) { //let the water flow until we reach required row or water becomes zero
        for (int col = 1; col <= row; ++col, idx++) { //fill glasses
            X = glass[idx]; //get the water from current glass
            glass[idx] = (X >= 1.0f) ? 1.0f : X; //keep the amount less than or equal to capacity in current glass
            X = (X >= 1.0f) ? (X - 1) : 0.0f; //get the remaining amount
            glass[idx+row] += X / 2;
            glass[idx+row+1] += X / 2;
        }
    }
    return glass[i*(i-1)/2 + j - 1];
}

int main() {
    int i = 2, j = 2;
    float X = 2.0;
    cout<<"Amount of water in "<<j<<"th glass of "<<i<<"th row with total water being "<<X<<" is: "<<waterGlass(i, j, X)<<endl;
    return 0;
}
