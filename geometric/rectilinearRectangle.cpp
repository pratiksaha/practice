//rectilinear rectangle
#include<iostream>
using namespace std;
 
struct point {
    int x, y;
};

typedef struct point Point;

bool checkOverlap(Point l1, Point r1, Point l2, Point r2) {
    if (l1.x > r2.x || l2.x > r1.x)
        return false; //one rectangle is left of other
    if (l1.y < r2.y || l2.y < r1.y)
        return false; //one rectangle is above other
    return true;
}

int main() {
    Point l1 = {0, 10}, r1 = {10, 0};
    Point l2 = {5, 5}, r2 = {15, 0};
    Point l3 = {20, 25}, r3 = {20, 25};
    checkOverlap(l1, r1, l2, r2) ? cout<<"Rectangles Overlap\n" : cout<<"Rectangles Do not Overlap\n";
    checkOverlap(l1, r1, l3, r3) ? cout<<"Rectangles Overlap\n" : cout<<"Rectangles Do not Overlap\n";
    return 0;
}
