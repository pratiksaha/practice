//check if two trees are isomorphic
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

bool checkIsomorphic(struct node* n1, struct node *n2) {
    if(n1 == NULL && n2 == NULL)
        return true;
    else if(n1 == NULL || n2 == NULL)
        return false;
    else if(n1->data != n2->data)
        return false;
    else 
        return ( ( checkIsomorphic(n1->left,n2->left) && checkIsomorphic(n1->right,n2->right) ) || ( checkIsomorphic(n1->left,n2->right) && checkIsomorphic(n1->right,n2->left) ) );
}

int main() {
    struct node *n1 = getNode(1);
    n1->left = getNode(2);
    n1->right = getNode(3);
    n1->left->left = getNode(4);
    n1->left->right = getNode(5);
    n1->right->left = getNode(6);
    n1->left->right->left = getNode(7);
    n1->left->right->right = getNode(8);
    struct node *n2 = getNode(1);
    n2->left = getNode(3);
    n2->right = getNode(2);
    n2->right->left = getNode(4);
    n2->right->right = getNode(5);
    n2->left->right = getNode(6);
    n2->right->right->left = getNode(8);
    n2->right->right->right = getNode(7);
    cout<<((checkIsomorphic(n1, n2))?"n1 and n2 are isomorphic":"n1 and n2 are not isomorphic")<<endl;
    deleteTree(&n1);
    deleteTree(&n2);
    return 0;
}
