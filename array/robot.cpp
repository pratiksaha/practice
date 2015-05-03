//to check if the given path for a robot is circular or not
#include<iostream>
using namespace std;

#define N 0
#define E 1
#define S 2
#define W 3
 
bool checkCircular(char path[]) {
    int x = 0, y = 0; //initial position
    int dir = N; //initial direction
    for (int i=0; path[i]; i++) {
        char move = path[i];
        if (move == 'R') {
            dir = (dir+1)%4;
        } else if (move == 'L') {
            dir = (4+dir-1)%4;
        } else { //move == G
            if (dir == N)
                y++;
            else if (dir == E)
                x++;
            else if (dir == S)
                y--;
            else
                x--;
        }
    }
    return (x==0 && y==0); //path is cyclic if robot comes back to (0, 0)
}

int main() {
    char path1[] = "GLGLGLG";
    checkCircular(path1) ? cout<<"Given sequence of moves is circular\n" : cout<<"Given sequence of moves is NOT circular\n";
    char path2[] = "GLGRGLG";
    checkCircular(path2) ? cout<<"Given sequence of moves is circular\n" : cout<<"Given sequence of moves is NOT circular\n";
    return 0;
}
