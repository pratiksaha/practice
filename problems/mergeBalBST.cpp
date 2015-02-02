//merge two balanced BSTs
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
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

void printTree(struct node *node) { //print the tree inorder
    if (node) {
        printTree(node->left);
        cout<<" "<<node->data;
        printTree(node->right);
    }
}

int countNodes(struct node *node) {
    int count = 0;
    while (node) {
        node = node->right;
        count++;
    }
    return count;
}

void TreeToListUtil(struct node *node, struct node **prev, struct node **head) {
    if (node) {
        TreeToListUtil(node->left, prev, head);
        if (*prev) {
            (*prev)->right = node;
        } else {
            *head = node;
        }
        node->left = *prev;
        *prev = node;
        TreeToListUtil(node->right, prev, head);
    }
}

struct node* TreeToList(struct node *node) {
    struct node *res = NULL;
    if (node) {
        struct node *prev = NULL;
        TreeToListUtil(node, &prev, &res);
    }
    return res;
}

struct node* mergeList(struct node* a, struct node* b) {
    if (a == NULL) {
        return b;
    } else if (b == NULL) {
        return a;
    } else {
        struct node* result = getNode(0);
        if (a->data <= b->data) {
            result->data = a->data;
            result->right = mergeList(a->right, b);
        } else {
            result->data = b->data;
            result->right = mergeList(a, b->right);
        }
        return result;
    }
}

struct node* ListToTreeUtil(struct node **node_ref, int n) {
    if (n <= 0) {
        return NULL;
    } else {
        struct node *left = ListToTreeUtil(node_ref, n/2);
        struct node *root = *node_ref;
        root->left = left;
        *node_ref = (*node_ref)->right;
        root->right = ListToTreeUtil(node_ref, n-n/2-1);
        return root;
    }
}

struct node* ListToTree(struct node *node) {
    int n = countNodes(node);
    return ListToTreeUtil(&node, n);
}

struct node * mergeTrees(struct node *a, struct node *b) {
    struct node *al = TreeToList(a);
    struct node *bl = TreeToList(b);
    struct node *reslist = mergeList(al, bl);
    return ListToTree(reslist); 
}

int main() {
    struct node *root1 = getNode(100);
    root1->left = getNode(50);
    root1->right = getNode(300);
    root1->left->left = getNode(20);
    root1->left->right = getNode(70);
    struct node *root2 = getNode(80);
    root2->left = getNode(40);
    root2->right = getNode(120);
    cout<<"Tree :"; printTree(root1); cout<<endl;
    cout<<"Tree :"; printTree(root2); cout<<endl;
    struct node *res = mergeTrees(root1, root2);
    cout<<"Merged Tree :"; printTree(res); cout<<endl;
    return 0;
}
