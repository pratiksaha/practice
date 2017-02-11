//to find all the Stepping Number in [n, m]
#include<bits/stdc++.h>
using namespace std;
 
bool isSteppingNumber(int n) {
    int prevDigit = -1;
    while (n) {
        int curDigit = n % 10;
        if (prevDigit == -1) {
            prevDigit = curDigit;
        } else {
            if (abs(prevDigit - curDigit) != 1)
                return false;
        }
        prevDigit = curDigit;
        n /= 10;
    }
    return true;
}

void steppingNumbersBFS(int n, int m, int num) {
    queue<int> q;
    q.push(num);
    while (!q.empty()) {
        int stepNum = q.front();
        q.pop();
        if (stepNum <= m && stepNum >= n)
            cout<<" "<<stepNum;
        if (num == 0 || stepNum > m)
            continue;
        int lastDigit = stepNum % 10;
        int stepNumA = stepNum * 10 + (lastDigit- 1);
        int stepNumB = stepNum * 10 + (lastDigit + 1);
        if (lastDigit == 0) {
            q.push(stepNumB);
        } else if (lastDigit == 9) {
            q.push(stepNumA);
        } else {
            q.push(stepNumA);
            q.push(stepNumB);
        }
    }
}

void steppingNumbersDFS(int n, int m, int stepNum) {
    if (stepNum <= m && stepNum >= n)
        cout<<" "<<stepNum;
    if (stepNum == 0 || stepNum > m)
        return ;
    int lastDigit = stepNum % 10;
    int stepNumA = stepNum*10 + (lastDigit-1);
    int stepNumB = stepNum*10 + (lastDigit+1);
    if (lastDigit == 0) {
        steppingNumbersDFS(n, m, stepNumB);
    } else if(lastDigit == 9) {
        steppingNumbersDFS(n, m, stepNumA);
    } else {
        steppingNumbersDFS(n, m, stepNumA);
        steppingNumbersDFS(n, m, stepNumB);
    }
}
 
void steppingNumbers(int n, int m) {
    cout<<"Stepping Nos between "<<n<<" and "<<m<<"are:\nUsing brute force:";    
    for (int i=n; i<=m; i++)
        if (isSteppingNumber(i))
            cout<<" "<<i;
    cout<<endl;
    cout<<"Using BFS :";
    for (int i = 0 ; i <= 9 ; i++)
        steppingNumbersBFS(n, m, i);
    cout<<endl;
    cout<<"Using DFS :";
    for (int i = 0 ; i <= 9 ; i++)
        steppingNumbersDFS(n, m, i);
    cout<<endl;
}

int main() {
    steppingNumbers(0, 21);
    return 0;
}
