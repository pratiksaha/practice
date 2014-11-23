//check if each node of a tree holds the child sum property
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

bool checkChildSum(struct node* node) {
    if(node == NULL || (node->left == NULL && node->right == NULL)) {
        return true;
    }else {
        int left_data = 0;
        if(node->left)
            left_data = node->left->data;
        int right_data = 0;
        if(node->right != NULL)
            right_data = node->right->data;
        if((node->data == left_data + right_data) && checkChildSum(node->left) && checkChildSum(node->right))
            return true;
        else
            return false;
    }
}

int main() {
    struct node *root  = getNode(10);
    root->left = getNode(8);
    root->right = getNode(2);
    root->left->left = getNode(3);
    root->left->right = getNode(5);
    root->right->right = getNode(2);
    cout<<((checkChildSum(root))?"root holds child sum property":"root does not hold child sum property")<<endl;
    deleteTree(&root);
    return 0;
}
