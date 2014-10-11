//prints the smallest number whose digits multiply to n
#include<iostream>
#include<stack>
using namespace std;

void findSmallest(int n)
{
    int i, j=0;
    stack<int> res;
    if (n < 10)
    {
        cout<<n+10<<endl;//E.g: for n = 7 output is 17
        return;
    }
    for (i=9; i>1; i--)
    {
        while (n%i == 0)
        {
            n = n/i;
            res.push(i);
        }
    }
    if (n > 10) //prime factors of n are greater than 10
    {
        cout<<"Not possible\n";
        return;
    }
    while(!res.empty()){
        cout<<res.top();
        res.pop();
    }
    cout<<endl;
}
 
int main()
{
    findSmallest(7);
    findSmallest(36);
    findSmallest(13);
    findSmallest(100);
    return 0;
}
