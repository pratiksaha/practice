//weighted job scheduling using DP to maximize profit
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
 
typedef struct {
    int start, finish, profit;
}Job;

bool myComp(Job s1, Job s2) { //used by sort()
    return (s1.finish < s2.finish);
}

int latestNonConflictJob(Job arr[], int i) { //find the latest job that doesn't conflict with the job[i]
    for (int j=i-1; j>=0; j--) //todo: use binary search
        if (arr[j].finish <= arr[i].start)
            return j;
    return -1;
}

void weightedJobScheduling(Job *jobs, int n) {
    sort(jobs, jobs+n, myComp); 
    int *table = new int[n]; //table[i] stores the profit for jobs till arr[i]
    table[0] = jobs[0].profit;
    for (int i=1; i<n; i++) {
        int inclProf = jobs[i].profit; //profit including curr job
        int l = latestNonConflictJob(jobs, i);
        if (l != -1)
            inclProf += table[l];
        table[i] = max(inclProf, table[i-1]); //store max of including and excluding
    }
    int result = table[n-1];
    stack<int> res;
    int curr = result;
    for (int j = n-1; j>0; j--) {
        if (table[j-1] != curr)
            res.push(j);
    }
    cout<<"Max profit is "<<result<<" with jobs :";
    while (!res.empty()) {
        cout<<" "<<res.top();
        res.pop();
    }
    cout<<endl;
    delete[] table;
}

int main() {
    Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    weightedJobScheduling(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
