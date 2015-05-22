//assembly line scheduling
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<iostream>
#include<cstdlib>
#include<stack>
#include<string>
using namespace std;
#define LINE 2
#define STATION 4
 
void assemblyLineScheduling(int a[LINE][STATION], int t[LINE][STATION], int *e, int *x) { //CLRS: TODO revisit
    int f[LINE][STATION], l[LINE][STATION], finish, line;
    f[0][0] = e[0] + a[0][0];
    f[1][0] = e[1] + a[1][0];
    l[0][0] = 0;
    l[1][0] = 1;
    for (int i=1; i<STATION; i++) {
        if ((f[0][i-1] + a[0][i]) <= (f[1][i-1] + t[1][i-1] + a[0][i])) {
            f[0][i] = f[0][i-1] + a[0][i];
            l[0][i] = 0;
        } else {
            f[0][i] = f[1][i-1] + t[1][i-1] + a[0][i];
            l[0][i] = 1;
        }
        if ((f[1][i-1] + a[1][i]) <= (f[0][i-1] + t[0][i-1] + a[1][i])) {
            f[1][i] = f[1][i-1] + a[1][i];
            l[1][i] = 1;
        } else {
            f[1][i] = f[0][i-1] + t[0][i-1] + a[1][i];
            l[1][i] = 0;
        }
    }
    if ((f[0][STATION-1] + x[0]) <= (f[1][STATION-1] + x[1])){
        finish = f[0][STATION-1] + x[0];
        line = 0;
    } else {
        finish = f[1][STATION-1] + x[1];
        line = 1;
    }
    cout<<"Min time exit at through line "<<line+1<<" at time "<<finish<<endl;
    int i = line;
    int j = STATION-1;
    stack<string> print;
    print.push("line " + to_string(i+1) + ", station" + to_string(j+1));
    while (j > 0) {
        i = l[i][j];
        print.push("line " + to_string(i+1) + ", station" + to_string(j--));
    }
    while(!print.empty()) {
        cout<<print.top()<<endl;
        print.pop();
    }
}

int main() {
    int a[LINE][STATION] = {{4, 5, 3, 2},
                            {2, 10, 1, 4}};
    int t[LINE][STATION] = {{0, 7, 4, 5},
                            {0, 9, 2, 8}};
    int e[LINE] = {10, 12};
    int x[LINE] = {18, 7};
    assemblyLineScheduling(a, t, e, x);
    return 0;
}
