//program to print all permutations of a given string
#include<iostream>
using namespace std;

void swap(char *x, char *y){
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *a, int i, int size){
    int j;
    if (i == size -1) {
        cout<<a<<endl;
    } else {
        for(j=i; j<size; j++) {
            swap((a+i), (a+j));
            permute(a, i+1, size);
            swap((a+i), (a+j));
        }
    }
}

int main(){
    char a[] = "ABCD";
    permute(a, 0, 4);
    return 0;
}
