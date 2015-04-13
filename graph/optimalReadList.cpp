//to schedule chapters for reading in given days
#include<iostream>
#include<cstdlib>
#include<climits>
#include<cmath>
using namespace std;
#define CHAPTERS 4
#define DAYS 3
#define NOLINK -1
int optimal_path[DAYS+1]; //final balanced schedule
int DAG[CHAPTERS+1][CHAPTERS+1]; //graph

void updateAssignment(int* path, int path_len) {
    for (int i=0; i<path_len; i++)
        optimal_path[i] = path[i] + 1;
}

void assignChapters(int u, int* path, int path_len, int sum, int k) { //DFS based recursive function to store the optimal path in path[] of size path_len
    static int min = INT_MAX;
    if (k >= 0) {
        path[path_len] = u;
        path_len++;
        if (k==0 && u==CHAPTERS) { //update
            if (sum < min) {
                updateAssignment(path, path_len);
                min = sum;
            }
        }
        for (int v=u+1; v<=CHAPTERS; v++) { //DFS
            sum += DAG[u][v];
            assignChapters(v, path, path_len, sum, k-1);
            sum -= DAG[u][v];
        }
    }
}

void optimalReadList(int pages[]) {
    int avg_pages=0, sum=0, S[CHAPTERS+1], path[DAYS+1];
    S[0] = 0; 
    for (int i=0; i<CHAPTERS; i++) { //S[i] = total pages till ith chapter
        sum += pages[i];
        S[i+1] = sum;
    }
    avg_pages = round(sum/DAYS);
    for (int i=0; i<=CHAPTERS; i++) { //DAG with vertices = chapter name & Edge weight = |avg_pages - pages in a chapter|
        for (int j = 0; j <= CHAPTERS; j++) {
            if (j <= i) {
                DAG[i][j] = NOLINK;
            } else {
                sum = abs(avg_pages - (S[j] - S[i]));
                DAG[i][j] = sum;
            }
        }
    }
    assignChapters(0, path, 0, 0, DAYS);
    cout<<"Optimal Chapter Assignment :"<<endl;
    for (int i=0; i<DAYS; i++) {
        int ch = optimal_path[i];
        cout<<"Day "<<i+1<<": "<<ch;
        ch++;
        while ( (i<DAYS-1 && ch<optimal_path[i+1]) || (i == DAYS-1 && ch <= CHAPTERS)) {
           cout<<" "<<ch;
           ch++;
        }
        cout<<endl;
    }
}

int main(void) {
    int pages[CHAPTERS] = {7, 5, 6, 12};
    optimalReadList(pages);
    return 0;
}
