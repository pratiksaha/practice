//greedy algorithm for activity selection problem
//assumes activities are already sorted by finish times
#include<iostream>
using namespace std;

void activitySelection(int *start, int *finish, int size) {
    cout<<"Selected Activities :";
    int i = 0; //first activity always gets selected
    cout<<" "<<i<<":("<<start[i]<<","<<finish[i]<<")";
    for (int j=1; j<size; j++) {
        if (start[j] >= finish[i]) { //select activity if's start time is >= to finish time of previously selected activity
          cout<<" "<<j<<":("<<start[j]<<","<<finish[j]<<")";
          i = j;
        }
    }
    cout<<endl;
}

int main() {
    int s[] =  {1, 3, 0, 5, 8, 5};
    int f[] =  {2, 4, 6, 7, 9, 9};
    int n = sizeof(s)/sizeof(s[0]);
    activitySelection(s, f, n);
    return 0;
}
