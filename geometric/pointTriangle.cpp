//Check if a point lies in a triangle
#include<iostream>
#include<cmath>
using namespace std;

struct Point{
    int x;
    int y;
};
 
//Function to calculate area of triangle 
float area(struct Point P1, struct Point P2, struct Point P3) {
    return abs( ( P1.x*(P2.y-P3.y) + P2.x*(P3.y-P1.y)+ P3.x*(P1.y-P2.y) )/2.0 );
}
 
//Function to check whether point P lies inside the triangle formed by A, B and C
bool isInside(struct Point P, struct Point A, struct Point B, struct Point C) {      
    float Al = area(A, B, C); //Calculate area of triangle ABC   
    float A1 = area(P, B, C); //Calculate area of triangle PBC 
    float A2 = area(A, P, C); //Calculate area of triangle PAC    
    float A3 = area(A, B, P); //Calculate area of triangle PAB
    
    return (Al == A1 + A2 + A3);
}

int main()
{

    struct Point P, A, B, C;
    P.x = 10;
    P.y = 15;
    A.x = 0;
    A.y = 0;
    B.x = 20;
    B.y = 0;
    C.x = 10;
    C.y = 30;
    
    cout<<(isInside(P,A,B,C)?"Yes":"No")<<endl;

    return 0;
}
