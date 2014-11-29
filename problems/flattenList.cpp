//flatten a list
#include<iostream>
#include<cstdlib>
using namespace std;

struct node {
    int data;
    struct node *right;
    struct node *down;
};
 
struct node* newNode(int key) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = key;
    node->right = NULL;
    node->down = NULL;
    return node;
}
 
void deleteList(struct node **head) {
    struct node* curr = *head;
    struct node* next;
    while (curr != NULL) {
        next = curr->down;
        free(curr);
        curr = next;
    }
    *head = NULL;
}

void printList(struct node *head) {
    cout<<"List :";
    while(head != NULL) {
        cout<<" "<<head->data;
        head = head->down;
    }
    cout<<endl;
}

struct node* merge(struct node* a, struct node* b ) {
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    struct node* result;
    if( a->data < b->data ) {
        result = a;
        result->down = merge(a->down, b);
    } else {
        result = b;
        result->down = merge(a, b->down);
    }
    return result;
}

struct node* flatten(struct node* root) {
    if (root == NULL||root->right == NULL)
        return root;
    else
        return merge(root, flatten(root->right));
}

int main() {
    struct node* root = newNode(5);
    root->down = newNode(7);
    root->down->down = newNode(8);
    root->down->down->down = newNode(30);
    root->right = newNode(10);
    root->right->down = newNode(20); 
    root->right->right = newNode(19);
    root->right->right->down = newNode(22);
    root->right->right->down->down = newNode(50);
    root->right->right->right = newNode(28);
    root->right->right->right->down = newNode(25);
    root->right->right->right->down->down = newNode(40);
    root->right->right->right->down->down->down = newNode(45);
    root = flatten(root);
    printList(root);
    deleteList(&root);
    return 0;
}
