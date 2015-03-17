//to simulate a cyber cafe and find no of unserved customers
#include<iostream>
#include<cstring>
using namespace std;

int simulateCyberCafe(int computers, char *sequence) { //input: no of computers and sequnce of arrivals
    char seen[26] = {0}; //O means not seen, 1 means seen, 2 means occupying a computer
    int unserved = 0;
    int occupied = 0;
    for (int i=0; sequence[i]; i++) {
        int index = sequence[i] - 'A';
        if (seen[index] == 0) { //arrival
            seen[index] = 1;
            if (occupied < computers) {
                occupied++;
                seen[index] = 2;
            } else {
                unserved++;
            }
        } else { //departure
           if (seen[index] == 2)
               occupied--;
           seen[index] = 0;
        }
    }
    return unserved;
}

int main() {
    cout<<"No of unserved customers for 2 computers and sequence ABBAJJKZKZ is "<<simulateCyberCafe(2, "ABBAJJKZKZ")<<endl;
    cout<<"No of unserved customers for 3 computers and sequence GACCBDDBAGEE is "<<simulateCyberCafe(3, "GACCBDDBAGEE")<<endl;
    cout<<"No of unserved customers for 3 computers and sequence GACCBGDDBAEE is "<<simulateCyberCafe(3, "GACCBGDDBAEE")<<endl;
    cout<<"No of unserved customers for 1 computers and sequence ABCBCA is "<<simulateCyberCafe(1, "ABCBCA")<<endl;
    cout<<"No of unserved customers for 1 computers and sequence ABCBCADEED is "<<simulateCyberCafe(1, "ABCBCADEED")<<endl;
    return 0;
}
