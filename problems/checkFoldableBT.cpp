//check if a tree is foldable
#include<iostream>
#include<cstdlib>
#include<climits>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node * getNode(int key) { //allocate memory and initialize
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

void deleteTree(struct node **node) { //free all space used by the tree
    if((*node) != NULL) {
        deleteTree(&((*node)->right));
        deleteTree(&((*node)->left));
        struct node *temp = *node;
        *node = NULL;
        free(temp);
    }
}

bool checkMirror(struct node *n1, struct node *n2) {
    if(n1 == NULL && n2 == NULL)
        return true;
    else if(n1 == NULL || n2 == NULL)
        return false;
    else
        return checkMirror(n1->left, n2->right) && checkMirror(n1->right, n2->left);
}

bool checkFoldable(struct node * node) {
    if(node)
        return checkMirror(node->left, node->right);
    else
        return true;
}

int main() {
    struct node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->right->left = getNode(4);
    root->left->right = getNode(5);
    cout<<((checkFoldable(root))?"root is foldable":"root is not foldable")<<endl;
    deleteTree(&root);
    return 0;
}
