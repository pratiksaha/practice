//partitions of an integer
#include<iostream>
using namespace std;

void printArray(int p[], int n) {
    for (int i=0; i<n; i++)
        cout<<" "<<p[i];
    cout<<endl;
}
 
void integerPartition(int n) {
    int p[n]; //partition
    int k = 0;  //index of last element in a partition
    p[k] = n;  //init first partition as number itself
    while (true) {
        printArray(p, k+1); 
        int rem_val = 0; //how much value can be accommodated
        while (k >= 0 && p[k] == 1) { //find the rightmost non-one value in p[]
            rem_val += p[k];
            k--;
        }
        if (k < 0) //all the values are 1
            return;
        p[k]--;
        rem_val++;
        while (rem_val > p[k]) { //divide rem_val in different values of size p[k]
            p[k+1] = p[k];
            rem_val -= p[k];
            k++;
        }
        p[k+1] = rem_val;
        k++;
    }
}

int main() {
    cout<<"All Unique Partitions of 2 :\n";
    integerPartition(2);
    cout<<"All Unique Partitions of 3 :\n";
    integerPartition(3);
    cout<<"All Unique Partitions of 4 :\n";
    integerPartition(4);
    cout<<"All Unique Partitions of 10 :\n";
    integerPartition(10);
    return 0;
}
