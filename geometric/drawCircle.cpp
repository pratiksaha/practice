//Draw a circle without floating point arithmetic
#include<iostream>
using namespace std;

//Draw circle with radius r 
void drawCircle(int r)
{
    int N = 2*r+1; // Consider a rectangle of size N*N
    int x, y;  // Coordinates inside the rectangle
 
    for (int i = 0; i < N; i++) { // Draw a square of size N*N.
        for (int j = 0; j < N; j++)
        {
            // Start from the left most corner point
            x = i-r;
            y = j-r;
            if (x*x + y*y <= r*r+1 ) // If this point is inside the circle, print it
                cout<<".";
            else // If outside the circle, print space
                cout<<" ";
            cout<<" ";
        }
        cout<<endl;;
    }
}

int  main()
{
    drawCircle(19);
    return 0;
}
