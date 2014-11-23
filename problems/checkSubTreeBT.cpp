//check if a BT is subtree of another BT
#include<iostream>
#include<cstdlib>
#include<climits>
#include<cstring>
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

bool checkIdentical(struct node* a, struct node* b) {
    if(a==NULL && b==NULL) {
        return true;
    } else if (a!=NULL && b!=NULL) {
        return (a->data == b->data && checkIdentical(a->left, b->left) && checkIdentical(a->right, b->right));
    } else {
        return false;
    }
}

bool checkSubTree(struct node *T, struct node *S) {
    if (S == NULL)
        return true;
    if (T == NULL)
        return false;
    if (checkIdentical(T, S))
        return true;
    return checkSubTree(T->left, S) || checkSubTree(T->right, S);
}

void storeInorder(struct node *root, char arr[], int &i) {
    if (root == NULL) {
        arr[i++] = '$';
        return;
    }
    storeInorder(root->left, arr, i);
    arr[i++] = root->data;
    storeInorder(root->right, arr, i);
}

void storePreOrder(struct node *root, char arr[], int &i) {
    if (root == NULL) {
        arr[i++] = '$';
        return;
    }
    arr[i++] = root->data;
    storePreOrder(root->left, arr, i);
    storePreOrder(root->right, arr, i);
}
 
bool checkSubtree(struct node *T, struct node *S) {
    if(S == NULL)
        return true;
    if(T == NULL)
        return false;
    int m = 0, n = 0;
    char inT[100], inS[100];
    storeInorder(T, inT, m);
    storeInorder(S, inS, n);
    inT[m] = '\0', inS[n] = '\0';
    m = 0, n = 0;
    char preT[100], preS[100];
    storePreOrder(T, preT, m);
    storePreOrder(S, preS, n);
    preT[m] = '\0', preS[n] = '\0';
    if(strstr(inT, inS) && strstr(preT, preS))
        return true;
    else
        return false;
}

int main() {
    struct node *T = getNode(26);
    T->right = getNode(3);
    T->right->right = getNode(3);
    T->left = getNode(10);
    T->left->left = getNode(4);
    T->left->left->right = getNode(30);
    T->left->right = getNode(6);
    struct node *S = getNode(10);
    S->right = getNode(6);
    S->left = getNode(4);
    S->left->right = getNode(30);
    cout<<((checkSubtree(T, S))?"Tree S is subtree of tree T":"Tree S is not a subtree of tree T")<<endl;
    cout<<((checkSubTree(T, S))?"Tree S is subtree of tree T":"Tree S is not a subtree of tree T")<<endl;
    S->left->right->left = getNode(100);
    cout<<((checkSubtree(T, S))?"Tree S is subtree of tree T":"Tree S is not a subtree of tree T")<<endl;
    cout<<((checkSubTree(T, S))?"Tree S is subtree of tree T":"Tree S is not a subtree of tree T")<<endl;
    deleteTree(&S);
    deleteTree(&T);
    return 0;
}
