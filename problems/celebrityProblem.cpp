//celebrity problem
#include<iostream>
#include<list>
using namespace std;

#define N 4

bool MATRIX[N][N] ={{0, 0, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0},
                    {0, 0, 1, 0}};
 
bool haveAcquaintance(int a, int b) { 
    return MATRIX[a][b];
}
 
int celebrityProblem(){
    list<int> stack;
    int i = 0;
    while(i<N) {
        stack.push_back(i);
        i++;
    }
    int A = stack.back();
    stack.pop_back();
    int B = stack.back();
    stack.pop_back();
    while(stack.size()!=1) {
        if(haveAcquaintance(A, B)) {
            A = stack.back();
            stack.pop_back();
        } else {
            B = stack.back();
            stack.pop_back();
        }
    }
    int C = stack.back();
    stack.pop_back();
    if(haveAcquaintance(C, B))
        C = B;
    if(haveAcquaintance(C, A))
        C = A;
    i = 0;
    while(i<N) {
        if(C!=i)
            stack.push_back(i);
        i++;
    }
    while(!stack.empty()) {
        i = stack.back();
        stack.pop_back();
        if(haveAcquaintance(C, i))
            return -1;
        if(!haveAcquaintance(i, C))
            return -1;
    }
    return C;
}
 
int main() {
   int id = celebrityProblem();
   (id==-1)?cout<<"No celebrity\n":cout<<"Celebrity ID "<<id<<endl;
   return 0;
}
