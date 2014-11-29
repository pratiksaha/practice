//find a triplet with 0 sum in a Balanced BST
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

void convertBSTtoDLL(struct node* root, struct node** head, struct node** tail) {
    if (root) {
        if (root->left)
            convertBSTtoDLL(root->left, head, tail);
        root->left = *tail;
        if (*tail)
            (*tail)->right = root;
        else
            *head = root;
        *tail = root;
        if (root->right)
            convertBSTtoDLL(root->right, head, tail);
    }
}

bool isPresentInDLL(struct node* head, struct node* tail, int sum) {
    while (head != tail) {
        int curr = head->data + tail->data;
        if (curr == sum)
            return true;
        else if (curr > sum)
            tail = tail->left;
        else
            head = head->right;
    }
    return false;
}

bool tripletSum0(struct node *node) {
    if (node) {
        struct node* head = NULL;
        struct node* tail = NULL;
        convertBSTtoDLL(node, &head, &tail);
        while ((head->right != tail) && (head->data < 0)) {
            if (isPresentInDLL(head->right, tail, -1*head->data))
                return true;
            else
                head = head->right;
        }
    }
    return false; // there is no 0 sum triplet or tree is empty
}

int main() {
    struct node *root =  getNode(6);
    root->left = getNode(-13);
    root->right = getNode(14);
    root->left->right = getNode(-8);
    root->right->left = getNode(13);
    root->right->right = getNode(15);
    root->right->left->left = getNode(7);
    if(!tripletSum0(root))
        cout<<"No such tripletn";
    else
        cout<<"Triplet exists\n";
    return 0;
}
