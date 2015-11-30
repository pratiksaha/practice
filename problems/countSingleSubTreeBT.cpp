// C++ program to find count of single valued subtrees
#include<iostream>
#include<cstdlib>
using namespace std;
 
struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node * getNode(int key) {
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    if(temp == NULL) {
        cout<<"Memory full\n";
        exit(1);
    }
    temp->data = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

bool countSingleSubTree(struct node* root, int *count) {
    if (root) {
        bool left = countSingleSubTree(root->left, count);
        bool right = countSingleSubTree(root->right, count);
        if (left == false || right == false)
            return false;
        if (root->left && root->data != root->left->data)
            return false;
        if (root->right && root->data != root->right->data)
            return false;
        (*count)++;
        return true;
    } else {
        return true;
    }
}

int countSingleSubTree(struct node* root) {
    int count = 0;
    countSingleSubTree(root, &count);
    return count;
}

int main() {
    struct node *root = getNode(5);
    root->left = getNode(4);
    root->right = getNode(5);
    root->left->left = getNode(4);
    root->left->right = getNode(4);
    root->right->right = getNode(5);
    cout<<"Count of Single Valued Subtrees is "<<countSingleSubTree(root)<<endl;
    return 0;
}
