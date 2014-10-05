//Program to find angle between hour and minute hands
#include<iostream>
#include<cmath>
using namespace std;
 
int min(int x, int y) 
{ 
    return (x < y)? x: y; 
}
 
int calcAngle(int h, int m)
{
    if (h <0 || m < 0 || h >12 || m > 60){   
        cout<<"wrong input"<<endl;
        return -1;
    }    
    h %= 12;
    m %= 60;
    int hour_angle = 0.5 * (h*60 + m);
    int minute_angle = 6*m;
    int angle = abs(hour_angle - minute_angle);
    angle = min(360-angle, angle); 
    return angle;
}

int main()
{
    cout<<calcAngle(9, 60)<<endl;
    cout<<calcAngle(3, 30)<<endl;
    return 0;
}
