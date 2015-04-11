//find the min cost path
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<iostream>
#include<stack>
#include<tuple>
using namespace std;


int min(int x, int y, int z) {
   if (x<y)
      return (x<z)?x:z;
   else
      return (y<z)?y:z;
}
 
void minCostPath(int *cost, int m, int n) {
    int i, j, tc[m][n];  
    tc[0][0] = *cost;
    for (i=1; i<m; i++)
        tc[i][0] = tc[i-1][0] + *(cost+i*n);
    for (j=1; j<n; j++)
        tc[0][j] = tc[0][j-1] + *(cost+j);
    for (i=1; i<m; i++)
        for (j=1; j<n; j++)
            tc[i][j] = min(tc[i-1][j-1], tc[i-1][j], tc[i][j-1]) + *((cost+i*n)+j);
    cout<<"Min Cost path = "<<tc[m-1][n-1]<<endl; 
    tuple<int, int> node;
    stack<tuple<int, int>> path;
    i = m-1;
    j = n-1;
    while (i!=0 || j!=0) {
        node = make_tuple(i,j);
        path.push(node);
        if (i==0) {
            j--;
        } else if (j==0) {
            i--;
        } else {
            int curr_min = min(tc[i-1][j-1], tc[i-1][j], tc[i][j-1]);
            if (curr_min == tc[i-1][j] ) {
                i--;
            } else if (curr_min == tc[i][j-1]) {
                j--;
            } else {
                i--;
                j--;
            }
        }
    }
    node = make_tuple(i,j);
    path.push(node);
    cout<<"Path :";
    while(!path.empty()) {
        node = path.top();
        cout<<" ("<<get<0>(node)<<","<<get<1>(node)<<")";
        path.pop();
    }
    cout<<endl;
}

int main() {
   int cost[3][3] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
   minCostPath(*cost, 3, 3);
   return 0;
}
