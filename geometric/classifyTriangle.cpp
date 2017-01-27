//to classify a given triangle
#include<bits/stdc++.h>
using namespace std;
 
class Point {
public:
    int x, y;
    Point()    {}
    Point(int x, int y) : x(x), y(y)    {}
};

inline int square(int x) {
    return x * x;
}

inline int euclidDistSquare(Point p1, Point p2) {
    return square(p1.x - p2.x) + square(p1.y - p2.y);
}

void order(int &a, int &b, int &c) {
    int copy[3];
    copy[0] = a;
    copy[1] = b;
    copy[2] = c;
    sort(copy, copy + 3);
    a = copy[0];
    b = copy[1];
    c = copy[2];
}

string getSideClassification(int a, int b, int c) {
    if (a == b && b == c)
        return "Equilateral";
    else if (a == b || b == c)
        return "Isosceles";
    else
        return "Scalene";
}

string getAngleClassification(int a, int b, int c) {
    if (a + b > c)
        return "Acute";
    else if (a + b == c)
        return "Right";
    else
        return "Obtuse";
}

void classifyTriangle(Point p1, Point p2, Point p3) {  
    int a = euclidDistSquare(p1, p2);
    int b = euclidDistSquare(p1, p3);
    int c = euclidDistSquare(p2, p3);
    order(a, b, c);
    cout<<"Triangle is "<<getAngleClassification(a, b, c)<<" and "<<getSideClassification(a, b, c)<<endl;
}

int main() {
    Point p1, p2, p3;
    p1 = Point(3, 0);
    p2 = Point(0, 4);
    p3 = Point(4, 7);
    classifyTriangle(p1, p2, p3);
    p1 = Point(0, 0);
    p2 = Point(1, 1);
    p3 = Point(1, 2);
    classifyTriangle(p1, p2, p3);
    return 0;
}
