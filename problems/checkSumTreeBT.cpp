//check if a tree is a sum tree
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

bool checkSumTree(struct node* node) {
    if(node == NULL || (node->left == NULL && node->right == NULL)) {
        return true;
    }else if(checkSumTree(node->left) && checkSumTree(node->right)){
        int left_data, right_data;
        if(node->left == NULL)
            left_data = 0;
        else if (node->left->left == NULL && node->left->right == NULL)
            left_data = node->left->data;
        else
            left_data = 2*(node->left->data);
        if(node->right == NULL)
            right_data = 0;
        else if (node->right->left == NULL && node->right->right == NULL)
            right_data = node->right->data;
        else
            right_data = 2*(node->right->data);
        return (node->data == (left_data + right_data));
    } else {
        return false;
    }
}

int main() {
    struct node *root = getNode(26);
    root->left = getNode(10);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(6);
    root->right->right = getNode(3);
    cout<<((checkSumTree(root))?"root is a sum tree":"root is not a sum tree")<<endl;
    deleteTree(&root);
    return 0;
}
