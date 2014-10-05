// Program to print pascals triangle
#include<iostream>
#include<iomanip>
using namespace std;
#define width 4
 
void printPascal(int n)
{
    for (int line = 1; line <= n; line++)
    {
        int C = 1;  // used to represent C(line, i)
        int i;
        for(i=n-line; i>0; i--)
            cout<<setw(width)<<" ";
        for (i = 1; i <= line; i++) 
        {
            cout<<setw(width)<<" "<<setw(width)<<C;  // The first value in a line is always 1
            C = C * (line - i) / i; 
        }
        cout<<endl;
    }
    
}

int main()
{
    int n = 8;
    printPascal(n);
    printPascal(10);
    return 0;
}
