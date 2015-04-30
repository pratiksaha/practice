#include<iostream>
#include<stack>
#include<cstdlib>
#include<cmath>
using namespace std;

void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        cout<<"Move disk 1 from "<<from<<" to "<<to<<endl;
        return;
    }
    towerOfHanoi(n-1, from, aux, to);
    cout<<"Move disk "<<n<<" from "<<from<<" to "<<to<<endl;
    towerOfHanoi(n-1, aux, to, from);
}

void printMove(char from, char to, int disk) {
    cout<<"Move disk "<<disk<<" from "<<from<<" to "<<to<<endl;
}

void moveDisk(char src, char dest, stack<int> *srcS, stack<int> *destS) {
    if (srcS->empty() && !destS->empty()) {
        int curr = destS->top();
        destS->pop();
        srcS->push(curr);
        printMove(dest, src, curr);
    } else if (!srcS->empty() && destS->empty()) {
        int curr = srcS->top();
        srcS->pop();
        destS->push(curr);
        printMove(src, dest, curr);
    } else if (!srcS->empty() && !destS->empty()) {
        if (srcS->top() > destS->top()) {
            int curr = destS->top();
            destS->pop();
            srcS->push(curr);
            printMove(dest, src, curr);
        } else {
            int curr = srcS->top();
            srcS->pop();
            destS->push(curr);
            printMove(src, dest, curr);
        }
    }
}

void towerOfHanoiItr(int n, char from, char to, char aux) {
    cout<<"Iterative solution begins>>>\n";
    stack<int> fromS, toS, auxS;
    if (n%2==0)
        swap(aux, to);
    int moves = pow(2,n)-1;
    for (int i=n; i>=1; i--)
        fromS.push(i);
    for (int i=1; i<=moves; i++) {
        if (i%3 == 1)
            moveDisk(from, to, &fromS, &toS);
        else if (i%3 == 2)
            moveDisk(from, aux, &fromS, &auxS);
        else
            moveDisk(aux, to, &auxS, &toS);
    }
    cout<<"<<<Iterative solution ends\n";
}

int main() {
    int n = 4;
    cout<<"Recursive solution begins>>>\n";
    towerOfHanoi(n, 'A', 'B', 'C'); //move n disks from A to B using C
    cout<<"<<<Recursive solution ends\n";
    towerOfHanoiItr(n, 'A', 'B', 'C'); //move n disks from A to B using C
    return 0;
}
