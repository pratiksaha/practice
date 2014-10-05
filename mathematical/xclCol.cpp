//To print Excel column name for a given column number
#include<iostream>
#include<stack>
using namespace std;
 

void printColName(int n)
{
    stack<char> res;
    while(n>0)
    {
        int rem = n%26;       
        if (rem==0)// If remainder is 0, then a 'Z' must be there in output
        {
            res.push('Z');
            n = (n/26)-1;
        }
        else // If remainder is non-zero
        {
            res.push((rem-1)+'A');
            n = n/26;
        }
    }
    while(!res.empty()){
        cout<<res.top();
        res.pop();
    }
    cout<<endl;
}

int main()
{
    printColName(26);
    printColName(51);
    printColName(52);
    printColName(80);
    printColName(676);
    printColName(702);
    printColName(705);
    return 0;
}
