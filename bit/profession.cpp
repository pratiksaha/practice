//find profession of a person at given level and position
#include<bits/stdc++.h>
using namespace std;

char profession(int level, int pos) {
    if (level == 1)
        return 'e';
    else if (profession(level-1, (pos+1)/2) == 'd')
        return (pos%2)? 'd' : 'e';
    else
        return (pos%2)?  'e' : 'd';
}

int countSetBits(int n) {
    int count = 0;
    while (n) {
        n &= (n-1) ;
        count++;
    }
    return count;
}
 
char professionBit(int level, int pos) {
    int c = countSetBits(pos-1);
    return (c%2)? 'd' : 'e';
}

int main(void) {
    int level = 4, pos = 2;
    cout<<"Profession at level : "<<level<<" & position : "<<pos<<" is "<<((profession(level, pos) == 'e') ? "Engineer" : "Doctor")<<endl;
    cout<<"Profession at level : "<<level<<" & position : "<<pos<<" is "<<((professionBit(level, pos) == 'e') ? "Engineer" : "Doctor")<<endl;
    return 0;
}
