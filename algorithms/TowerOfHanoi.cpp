#include<iostream>
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

int main() {
    int n = 4;
    towerOfHanoi(n, 'A', 'B', 'C'); //move n disks from A to B using C
    return 0;
}
