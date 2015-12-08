//find area of rectilinear rectangles
//TODO: fill the skeletal solution
#include<bits/stdc++.h>
using namespace std;

typedef struct {
    int x,y;
}Point;

struct rect {
    Point low, high;
};

typedef rect Rectangle;

int rectilinearArea(Rectangle a, Rectangle b) {
    int area;
    if (a.left.x < b.left.x) {
        if (a.left.y < b.left.y ) {
            if (a.right.x < b.right.x) {
                if (a<right.y < b.right.y) {
                
                } else {
                
                }
            } else {
                if (a<right.y < b.right.y) {
                
                } else {
                
                }
            }
        } else {
            if (a.right.x < b.right.x) {
                if (a<right.y < b.right.y) {
                
                } else {
                
                }
            } else {
                if (a<right.y < b.right.y) {
                
                } else {
                
                }
            }
        }
    } else {
        if (a.left.y < b.left.y ) {
            if (a.right.x < b.right.x) {
                if (a<right.y < b.right.y) {
                
                } else {
                
                }
            } else {
                if (a<right.y < b.right.y) {
                
                } else {
                
                }
            }
        } else {
            if (a.right.x < b.right.x) {
                if (a<right.y < b.right.y) {
                
                } else {
                
                }
            } else {
                if (a<right.y < b.right.y) {
                
                } else {
                
                }
            }
        }
    }
    return area;
}

int main () {
    Rectangle a = { {4,4}, {10,10} };
    Rectangle b = { {8,8}, {15, 15} };
    cout<<"Area of given rectangles = "<<rectilinearArea(a,b)<<endl;
    return 0;
}
