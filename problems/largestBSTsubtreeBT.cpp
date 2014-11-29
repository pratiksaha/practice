//find the largest BST subtree in a BT
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

int largestBSTUtil(struct node* node, int *min, int *max, int *max_size, bool *is_bst) {
    if (node) {
        bool left_flag = false;
        bool right_flag = false;
        int ls, rs;
        
        *max = INT_MIN;
        ls = largestBSTUtil(node->left, min, max, max_size, is_bst);
        if (*is_bst && node->data > *max)
            left_flag = true;
        int temp = *min;
        *min =  INT_MAX;
        rs = largestBSTUtil(node->right, min, max, max_size, is_bst);
        if (*is_bst && node->data < *min)
            right_flag = true;
 
        if (temp < *min)
            *min = temp;
        if (node->data < *min)
            *min = node->data;
        if (node->data > *max)
            *max = node->data;
        if(left_flag && right_flag) { //both left and right subtrees are BST
            if (ls + rs + 1 > *max_size)
                *max_size = ls + rs + 1;
            return ls + rs + 1; //return the size of this tree
        } else {
            *is_bst = false;
            return 0;
        }
    } else {
        *is_bst = true;
        return 0;
    }
}

int largestBST(struct node* node) {
    int min = INT_MAX;
    int max = INT_MIN;
    int max_size = 0;
    bool is_bst = false;
    largestBSTUtil(node, &min, &max, &max_size, &is_bst);
    return max_size;
}

int main() {
    struct node *root = getNode(50);
    root->left = getNode(10);
    root->right = getNode(60);
    root->left->left = getNode(5);
    root->left->right = getNode(20);
    root->right->left = getNode(55);
    root->right->left->left = getNode(45);
    root->right->right = getNode(70);
    root->right->right->left = getNode(65);
    root->right->right->right = getNode(80);
    cout<<"Size of larget BST subtree = "<<largestBST(root)<<endl;
    deleteTree(&root);
    return 0;
}
