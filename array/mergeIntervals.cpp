//merge overlapping intervals
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
 
typedef struct {
    int start, end;
}Interval;
 

bool compareInterval(Interval i1, Interval i2) {
    return (i1.start<i2.start)?true:false;
}

void mergeIntervals(Interval arr[], int n) {
    if (n<=0)
        return;
    int i;  
    Interval temp[n];
    for (i=0; i<n; i++)
        temp[i] = arr[i];
    
    stack<Interval> s;
    sort(temp, temp+n, compareInterval);
    s.push(temp[0]);
    for (i = 1 ; i<n; i++) {
        Interval top = s.top();
        if (top.end < temp[i].start) { //if curr interval is not overlapping with stack top, push it to the stack
            s.push(temp[i]);
        } else if (top.end < temp[i].end) { //else update the ending time of top if ending of curr interval is more
            top.end = temp[i].end;
            s.pop();
            s.push(top);
        }
    }
    
    int m = s.size();
    Interval res[m];
    i = m-1;
    while (!s.empty()) {
        res[i] = s.top();
        s.pop();
        i--;
    }
    
    cout<<"Input Intervals :";
    for(i=0; i<n; i++)
        cout<<" ["<<arr[i].start<<","<<arr[i].end<<"]";
    cout<<endl;
    
    cout<<"Merged Intervals :";
    for(i=0; i<m; i++)
        cout<<" ["<<res[i].start<<","<<res[i].end<<"]";
    cout<<endl;
}

int main() {
    Interval a[] = { {6,8}, {1,9}, {2,4}, {4,7} };
    mergeIntervals(a, sizeof(a)/sizeof(a[0]));
    Interval b[] = { {7,8},{1,3},{2,4},{4,7} };
    mergeIntervals(b, sizeof(b)/sizeof(b[0]));
    Interval c[] = { {1,3},{7,9},{4,6},{10,13} };
    mergeIntervals(c, sizeof(c)/sizeof(c[0]));
    return 0;
}
