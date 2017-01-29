//to find minimum XOR pair value in an array
#include<bits/stdc++.h>
using namespace std;
#define INT_SIZE 32

struct node {
    int value;
    struct node * children[2];
};

struct node * getNode() {
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = 0;
    newNode->children[0] = newNode->children[1] = NULL;
    return newNode;
}

void insert(struct node *root, int key) {
    struct node *temp = root;
    for (int i=INT_SIZE-1; i>=0; i--) {
        bool current_bit = (key & (1<<i));
        if (temp->children[current_bit] == NULL)
            temp->children[current_bit] = getNode();
        temp = temp->children[current_bit];
    }
    temp->value = key ;
}

int minXORPairValue(struct node * root, int key) {
    struct node * temp = root;
    for (int i=INT_SIZE-1; i>=0; i--) {
        bool current_bit = ( key & ( 1<<i) );
        if (temp->children[current_bit] != NULL)
            temp = temp->children[current_bit];
        else if(temp->children[1-current_bit] !=NULL)
            temp = temp->children[1-current_bit];
    }
    return key ^ temp->value;
}

int minXORPairValue(int arr[], int n) {
    int min_xor = INT_MAX;
    struct node *root = getNode();
    insert(root, arr[0]);
    for (int i=1; i<n; i++) {
        min_xor = min(min_xor, minXORPairValue(root, arr[i]));
        insert(root, arr[i]);
    }
    return min_xor;
}

int main() {
    int arr[] = {9, 5, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Minimum XOR value of pairs in the array is "<<minXORPairValue(arr, n)<<endl;
    return 0;
}
