//to find maximum number of X's that can be printed using four keys
//Key 1:        X : Print A on screen 
//Key 2: (Ctrl+A) : Select screen
//Key 3: (Ctrl+C) : Copy selection to buffer
//Key 4: (Ctrl+V) : Print buffer on screen appending it after what has already been printed
//TODO: revisit
#include<iostream>
using namespace std; 

void printMaxX(int N) {
    cout<<"Maximum Number of X's with "<<N<<" keystrokes is : ";
    if (N > 6) {
        int screen[N];
        int i;
        for (i=1; i<=6; i++)
            screen[i-1] = i;
        for (i=7; i<=N; i++) { // for any keystroke i we need to loop from i-3 keystrokes back to 1 keystroke to find a breakpoint b after which we will have Ctrl+A Ctrl+C and then only Ctrl+V all the way
            screen[i-1] = 0;
            for (int b=i-3; b>=1; b--) { // if the breakpoint is at bth keystroke then the optimal string would have length (i-b-1)*screen[b-1]
                int curr = (i-b-1)*screen[b-1];
                if (curr > screen[i-1])
                    screen[i-1] = curr;
            }
        }
        cout<<screen[N-1]<<endl;
    } else {
        cout<<N<<endl;
    }
}

int main() {
    for (int i=1; i<=20; i++)
        printMaxX(i);
    return 0;
}
