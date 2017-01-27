//to get right angle triangle from given hypotenuse and area of triangle
#include<bits/stdc++.h>
using namespace std;

#define eps 1e-6

double getArea(double base, double hypotenuse) {
    double height = sqrt(hypotenuse*hypotenuse - base*base);
    return 0.5 * base * height;
}

void findRightTriangle(int hypotenuse, int area) {
    int hsquare = hypotenuse * hypotenuse;
    double sideForMaxArea = sqrt(hsquare / 2.0);
    double maxArea = getArea(sideForMaxArea, hypotenuse);
    if (area > maxArea) {
        cout<<"Right Triangle with area : "<<area<<" and hypotenuse : "<<hypotenuse<<" is not possible"<<endl;
    } else {
        double low = 0.0;
        double high = sideForMaxArea;
        double base;
        while (abs(high - low) > eps) {
            base = (low + high) / 2.0;
            if (getArea(base, hypotenuse) >= area)
                high = base;
            else
                low = base;
        }
        double height = sqrt(hsquare - base*base);
        cout<<"Right Triangle with area : "<<area<<" and hypotenuse : "<<hypotenuse<<" has base : "<<base<<" and height : "<<height<<endl;
    }
}

int main() {
    findRightTriangle(5, 6);
    return 0;
}
