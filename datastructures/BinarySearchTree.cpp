//Binary Search Tree
#include<iostream>
#include<cstdlib>
#include<climits>
#include<string>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node * getNode() { //allocate memory
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    if(temp == NULL) {
        cout<<"Memory full\n";
        exit(1);
    }
    return temp;
}

void printTree(struct node *node) { //print the tree inorder
    if(node != NULL) {
        printTree(node->left);
        cout<<" "<<node->data;
        printTree(node->right);
    }
}

void deleteTree(struct node **node) { //free all memory used by the tree
    if((*node) != NULL) {
        deleteTree(&((*node)->right));
        deleteTree(&((*node)->left));
        struct node *temp = *node;
        *node = NULL;
        free(temp);
    }
}

bool isBST(struct node *node, int minKey=INT_MIN, int maxKey=INT_MAX) { //check if given tree is a BST
    if (node==NULL)
        return true;
    if (node->data < minKey || node->data > maxKey)
        return false;
    return isBST(node->left, minKey, node->data-1) && isBST(node->right, node->data+1, maxKey);
}

struct node* minBST(struct node *node) { //find node with minimum key
    while(node->left != NULL)
        node = node->left;
    return node;
}

struct node* maxBST(struct node *node) { //find node with maximum key
    while(node->right != NULL)
        node = node->right;
    return node;
}

void printRange(struct node *node, int minKey=INT_MIN, int maxKey=INT_MAX) { //print values within minKey and maxKey in the BST
    if(node != NULL) {
        if(node->data > minKey)
            printRange(node->left, minKey, maxKey);
        if(node->data >= minKey && node->data <= maxKey )
            cout<<" "<<node->data;
        if(node->data < maxKey)
            printRange(node->right, minKey, maxKey);
    }
}

struct node* ceilBST(struct node *node, int key) { //find ceiling for the key in BST
    if(node == NULL) {
        return NULL;
    } else if(node->data == key) {
        return node;
    } else if(node->data < key) {
        return ceilBST(node->right, key);
    } else {
        struct node *temp = ceilBST(node->left, key);
        if(!temp)
            return node;
        else
            return (temp->data >= key) ? temp : node;
    }
}

struct node* floorBST(struct node *node, int key) { //find floor for the key in BST
    if(node == NULL) {
        return NULL;
    } else if(node->data == key) {
        return node;
    } else if(node->data > key) {
        return floorBST(node->left, key);
    } else {
        struct node *temp = floorBST(node->right, key);
        if(!temp)
            return node;
        else
            return (temp->data <= key) ? temp : node;
    }
}

struct node* inorderPredecessor(struct node *node, struct node *key_node) { //find inorder predecessor node
    if(node == NULL)
        return NULL;       
    if(key_node->left != NULL) {
        return maxBST(key_node->left);
    } else {
        struct node *temp = NULL;
        while (node != NULL) {
            if (key_node->data < node->data) {
                temp = node;
                node = node->left;
            } else if (key_node->data > node->data) {
                node = node->right;
            } else {
                break;
            }
        }
        return temp;
    }
}

struct node* inorderSuccessor(struct node *node, struct node *key_node) { //find inorder successor node
    if(node == NULL)
        return NULL;
        
    if(key_node->right != NULL) {
        return minBST(key_node->right);
    } else {
        struct node *temp = NULL;
        while (node != NULL) {
            if (key_node->data > node->data) {
                temp = node;
                node = node->right;
            } else if (key_node->data < node->data) {
                node = node->left;
            } else {
                break;
            }
        }
        return temp;
    }
}

struct node* searchBST(struct node *node, int key) { //search key in the BST
    if(node == NULL || node->data == key)
        return node;
    else if(node->data < key)
        return searchBST(node->right, key);
    else
        return searchBST(node->left, key);
}

void insertNode(struct node **node, int key) { //BST insert
    if(*node == NULL) {
        *node = getNode();
        (*node)->data = key;
        (*node)->left = NULL;
        (*node)->right = NULL;
    } else {
        if((*node)->data < key)
            insertNode(&((*node)->right), key);
        else if ((*node)->data > key)
            insertNode(&((*node)->left), key);
    }
}


int main() {
    struct node *t = NULL;
    struct node *temp = NULL;
    insertNode(&t, 50);
    insertNode(&t, 25);
    insertNode(&t, 75);
    insertNode(&t, 10);
    insertNode(&t, 40);
    insertNode(&t, 60);
    insertNode(&t, 90);
    insertNode(&t, 5);
    insertNode(&t, 15);
    insertNode(&t, 55);
    insertNode(&t, 70);
    insertNode(&t, 80);
    insertNode(&t, 4);
    insertNode(&t, 1);
    insertNode(&t, 45);
    insertNode(&t, 13);
    cout<<"Tree :";
    printTree(t);
    cout<<endl;
    cout<<(isBST(t)?"Is a Binary Search Tree":"Is NOT a Binary Search Tree")<<endl;
    cout<<"Min = "<<minBST(t)->data<<endl;
    cout<<"Max = "<<maxBST(t)->data<<endl;
    cout<<"All range = ";
    printRange(t);
    cout<<endl;
    cout<<"Within range [10, 75] = ";
    printRange(t, 10, 75);
    cout<<endl;
    cout<<"10"<<((searchBST(t, 10) != NULL)?" Found":" Not Found")<<endl;
    cout<<"70"<<((searchBST(t, 70) != NULL)?" Found":" Not Found")<<endl;
    cout<<"49"<<((searchBST(t, 49) != NULL)?" Found":" Not Found")<<endl;
    cout<<"51"<<((searchBST(t, 51) != NULL)?" Found":" Not Found")<<endl;
    cout<<"Ceil of 50 = "<<ceilBST(t, 50)->data<<endl;
    cout<<"Floor of 50 = "<<floorBST(t, 50)->data<<endl;
    cout<<"Ceil of 49 = "<<ceilBST(t, 49)->data<<endl;
    cout<<"Floor of 49 = "<<floorBST(t, 49)->data<<endl; 
    cout<<"Ceil of 51 = "<<ceilBST(t, 51)->data<<endl;
    cout<<"Floor of 51 = "<<floorBST(t, 51)->data<<endl;
    temp = inorderSuccessor(t, t); 
    cout<<"Inorder Successor of 50 = ";
    if(temp)
        cout<<temp->data<<endl;
    else
        cout<<"Not exist"<<endl;
    temp = inorderPredecessor(t, t);
    cout<<"Inorder Predecessor of 50 = ";
    if(temp)
        cout<<temp->data<<endl;
    else
        cout<<"Not exist"<<endl;         
    deleteTree(&t);
    cout<<"Tree :";
    printTree(t);
    cout<<endl;
    return 0;
}
