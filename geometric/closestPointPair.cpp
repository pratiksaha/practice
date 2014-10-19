//to find the smallest distance from a given set of points.
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<climits>
#include<algorithm>
using namespace std;

struct point {
    int x;
    int y;
};

typedef struct point Point; 
  
//compare function used by qsort to sortarray of points according to X coordinate
int compareX(const void* a, const void* b) {
    Point *p1 = (Point *)a,  *p2 = (Point *)b;
    return (p1->x - p2->x);
}

//compare function used by qsort to sortarray of points according to X coordinate
int compareY(const void* a, const void* b) {
    Point *p1 = (Point *)a,   *p2 = (Point *)b;
    return (p1->y - p2->y);
}
 
//returns the square of the distance between two points
int dist(Point p1, Point p2) {
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}
 
//returns the smallest distance between two points in P[] of size n (n is small)
int bruteForce(Point P[], int n) {
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}

 
//returns the dist beween the closest points of strip of given size
//this is O(n)
int stripClosest(Point strip[], int size, int d) {
    int min = d;
    for (int i = 0; i < size; i++)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; j++)//It is a proven fact that this loop runs at most 6 times
            if (dist(strip[i],strip[j]) < min)
                min = dist(strip[i], strip[j]);
    return min;
}
 
//Recursive function to find the smallest distance
int closestPoints(Point Px[], Point Py[], int n) {   
    if (n <= 3)// If there are 2 or 3 points, then use brute force
        return bruteForce(Px, n);
    int i, j;
    int m = n/2;
    Point mP = Px[m];

    Point Pl[m+1]; //left sub array
    Point Pr[n-m-1]; //right sub array
    int li = 0, ri = 0;
    for (i=0; i<n; i++) {
      if (Py[i].x <= mP.x)
         Pl[li++] = Py[i];
      else
         Pr[ri++] = Py[i];
    }

    int dl = closestPoints(Px, Pl, m);
    int dr = closestPoints(Px + m, Pr, n-m);
    int d = min(dl, dr); //find the smallest distances in the left and right subarrays

    Point strip[n]; //build an array strip[] that contains points closer than d to the line passing through the middle point
    j = 0;
    for(i = 0; i < n; i++) {
        if (abs(Py[i].x - mP.x) < d) {
            strip[j] = Py[i];
            j++;
        }
    }
          
    return min(d, stripClosest(strip, j, d) );//return the minimum of d and closest distance in strip[]
}
 
//pre-processing
int closest(Point P[], int n) {
    Point Px[n];
    Point Py[n];
    for (int i = 0; i < n; i++) {
        Px[i] = P[i];
        Py[i] = P[i];
    }
    qsort(Px, n, sizeof(Point), compareX);
    qsort(Py, n, sizeof(Point), compareY);
    return closestPoints(Px, Py, n);
}

int main() {
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    cout<<"The smallest distance is "<<sqrt(closest(P, sizeof(P)/sizeof(P[0])))<<endl;
    return 0;
}
