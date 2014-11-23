//chcek if all internodes have one child from preorder traversal in a BSt
#include<iostream>
using namespace std;
 
bool hasOnlyOneChild(int pre[], int size) {
    int min, max; //initialize min and max
    if (pre[size-1] > pre[size-2]) {
        max = pre[size-1];
        min = pre[size-2];
    } else {
        max = pre[size-2];
        min = pre[size-1];
    }
    for (int i=size-3; i>=0; i--) { //every element must be either smaller than min or greater than max
        if (pre[i] < min)
            min = pre[i];
        else if (pre[i] > max)
            max = pre[i];
        else
            return false;
    }
    return true;
}

int main() {
    int pre[] = {8, 3, 5, 7, 6};
    int size = sizeof(pre)/sizeof(pre[0]);
    cout<<((hasOnlyOneChild(pre,size))?"Yes":"No")<<endl;;
    return 0;
}
