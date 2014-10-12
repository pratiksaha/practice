#include<iostream>
using namespace std;
 
float power(float x, int y) {  
    if( y == 0)
        return 1;
        
    float temp = power(x, y/2);           
    if (y%2 == 0)
        return temp*temp;
    else {
        if(y > 0)
            return x*temp*temp;
        else
            return (temp*temp)/x;
    }
}  

int main() {
    float x = 2;
    int y = -3;
    cout<<power(x, y)<<endl;
    x = 2;
    y = -4;
    cout<<power(x, y)<<endl;
    x = 5;
    y = 3;
    cout<<power(x, y)<<endl;
    return 0;
}
