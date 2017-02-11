//to tell the current direction in a grid
#include<bits/stdc++.h>
using namespace std;

void directionLastSquareBlock(long long int R, long long int C) {
    if (R!=C && R%2==0 && C%2!=0 && R<C)
    {
        cout << "Left" << endl;
        return;
    }
    if (R!=C && R%2!=0 && C%2==0 && R>C)
    {
        cout << "Up" << endl;
        return;
    }
    if (R==C && R%2!=0 && C%2!=0)
    {
        cout << "Right" << endl;
        return;
    }
    if (R==C && R%2==0 && C%2==0)
    {
        cout << "Left" << endl;
        return;
    }
    if (R!=C && R%2!=0 && C%2!=0 && R<C)
    {
        cout << "Right" << endl;
        return;
    }
    if (R!=C && R%2!=0 && C%2!=0 && R>C)
    {
        cout << "Down" << endl;
        return;
    }
    if (R!=C && R%2==0 && C%2==0 && R<C)
    {
        cout << "Left" << endl;
        return;
    }
    if (R!=C && R%2==0 && C%2==0 && R>C)
    {
        cout << "Up" << endl;
        return;
    }
    if (R!=C && R%2==0 && C%2!=0 && R>C)
    {
        cout << "Down" << endl;
        return;
    }
    if (R!=C && R%2!=0 && C%2==0 && R<C)
    {
        cout << "Right" << endl;
        return;
    }
}

int main() {
    long long int R=3, C=1;
    directionLastSquareBlock(R, C);
    return 0;
}
