//Program to find the max area under a histogram
#include<iostream>
#include<stack>
using namespace std;

int getMaxArea(int hist[], int n) {
    stack<int> s;
    int tp;
    int tp_area;
    int max_area = 0;
    int i = 0;
    while(i<n) {
        if ( s.empty()||hist[s.top()]<=hist[i] ){ //If current bar is higher than the bar on top stack, push
            s.push(i);
            i++;
        } else { //calculate area of rectangle with stack top as the smallest bar. i is right index & element before top in stack is 'left index'
            tp = s.top();
            s.pop();
            tp_area = hist[tp]*(s.empty()?i:i-s.top()-1);
            if(max_area < tp_area)
                max_area = tp_area;
        }     
    }
    while(!s.empty()) {//calculate area with every popped bar as the smallest bar
        tp = s.top();
        s.pop();
        tp_area = hist[tp]*(s.empty()?i:i-s.top()-1);
        if(max_area < tp_area)
            max_area = tp_area;
    }
    return max_area;
}

int main() {
    int a[] = {6, 2, 5, 4, 5, 1, 6};
    cout<<"Maximum area in the histogram is "<<getMaxArea(a, sizeof(a)/sizeof(a[0]))<<endl;
    return 0;
}
