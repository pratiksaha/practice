//AVL Tree
#include<iostream>
#include<cstdlib>
#include<cassert>
using namespace std;

struct node {
    int data, height;
    struct node* left;
    struct node* right;
};

struct node* getNode(int key) {
    struct node* temp = (struct node *)malloc(sizeof(struct node));
    assert(temp); //just in case malloc fails
    temp->data = key;
    temp->height = 1; //assume it is leaf
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int height(struct node* node) { //return height of a node
    if (node)
        return node->height;
    else
        return 0;
}

int getBalance(struct node* node) {//return balance
    if (node)
        return height(node->left) - height(node->right);
    else
        return 0;
}

struct node* leftRotate(struct node* node){ //left rotate about node
    struct node* rNode = node->right;
    struct node* lrNode = rNode->left;
    rNode->left = node;
    node->right = lrNode;
    node->height = max(height(node->left), height(node->right)) + 1;
    rNode->height = max(height(rNode->left), height(rNode->right)) + 1;
    return rNode;
}

struct node* rightRotate(struct node* node){ //right rotate about node
    struct node* lNode = node->left;
    struct node* rlNode = lNode->right;
    lNode->right = node;
    node->left = rlNode;
    node->height = max(height(node->left), height(node->right)) + 1;
    lNode->height = max(height(lNode->left), height(lNode->right)) + 1;
    return lNode;
}

struct node* balanceAVL(struct node* node, int key) { //balance the AVL sub tree rooted at node
    node->height = max(height(node->left), height(node->right)) + 1;
    int balance = getBalance(node);
    if (balance > 1 && key < node->left->data) { //left left
        return rightRotate(node);
    } else if (balance < -1 && key > node->right->data) { //right right
        return leftRotate(node);
    } else if (balance > 1 && key > node->left->data) { //left right
        node->left = leftRotate(node->left);
        return rightRotate(node);
    } else if (balance < -1 && key < node->right->data) { //right left
        node->right = rightRotate(node->right);
        return leftRotate(node);
    } else { //balanced
        return node;
    }
}

struct node* getMinValueNode(struct node* node) { //return the min value node in the subtree rooted at node
    struct node* curr = node;
    while (curr->left != NULL)
        curr = curr->left;
    return curr;
}

struct node* searchAVL(struct node *node, int key) { //search key in the AVL Tree
    if(node && node->data < key)
        return searchAVL(node->right, key);
    else if(node && node->data > key)
        return searchAVL(node->left, key);
    else //node is NULL or node->data == key
        return node;
}

struct node* insertAVL(struct node* node, int key) { //insert key in AVL Tree
    if (node==NULL)
        return getNode(key);
    else if (node->data > key)
        node->left = insertAVL(node->left, key);
    else
        node->right = insertAVL(node->right, key);
    return balanceAVL(node, key);
}

struct node* deleteAVL(struct node* node, int key) { //delete key from AVL Tree
    if (node==NULL) {
        return node;
    } else if (node->data > key) {
        node->left = deleteAVL(node->left, key);
    } else if (node->data < key) {
        node->right = deleteAVL(node->right, key);
    } else {
        if (node->left && node->right) { //node to be deleted has 2 children
            struct node* temp = getMinValueNode(node->right);
            node->data = temp->data;
            node->right = deleteAVL(node->right, temp->data);
        } else {
            struct node* temp = node->left ? node->left : node->right;
            if (temp) { //1 child
                *node = *temp;
            } else { //0 child
                temp = node;
                node = NULL;
            }
            free(temp);
        }
    }
    if (node) //tree is not empty after deleting one key
        return balanceAVL(node, key);
    else //tree is empty after deleting one key
        return node;
}

void printTree(struct node *node) { //print the tree inorder
    if(node != NULL) {
        printTree(node->left);
        cout<<" "<<node->data;
        printTree(node->right);
    }
}

int main() {
    struct node *root = NULL;
    struct node* temp;
    root = insertAVL(root, 9);
    root = insertAVL(root, 5);
    root = insertAVL(root, 10);
    root = insertAVL(root, 0);
    root = insertAVL(root, 6);
    root = insertAVL(root, 11);
    root = insertAVL(root, -1);
    root = insertAVL(root, 1);
    root = insertAVL(root, 2);
    temp = searchAVL(root, 10);
    temp ? cout<<"10 found in AVL tree\n" : cout<<"10 not found in AVL tree\n";
    cout<<"Tree :"; printTree(root); cout<<endl;
    root = deleteAVL(root, 10);
    temp = searchAVL(root, 10);
    temp ? cout<<"10 found in AVL tree\n" : cout<<"10 not found in AVL tree\n";
    cout<<"Tree :"; printTree(root); cout<<endl;
    return 0;
}
