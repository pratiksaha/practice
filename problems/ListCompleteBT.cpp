//convert list to complete BT
#include<iostream>
#include<cstdlib>
#include<queue>
using namespace std;

struct listNode {
    int data;
    struct listNode* next;
};

struct treeNode {
    int data;
    struct treeNode *left, *right;
};

struct listNode* getListNode() { //alocate memory
    struct listNode *temp = (struct listNode *)malloc(sizeof(struct listNode));
    if (temp == NULL) {
        cout<<"Memory Full"<<endl;
    }
    return temp;
}

struct treeNode* getTreeNode(int data) { //allocate memory
    struct treeNode *temp = (struct treeNode *)malloc(sizeof(struct treeNode));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
void push_front(struct listNode **head, int key) { //add node in the front
    struct listNode* temp = getListNode();
    temp->data = key;
    temp->next = *head;
    *head = temp;
}

void printTree(struct treeNode *node) { //print the tree inorder
    if (node) {
        printTree(node->left);
        cout<<" "<<node->data;
        printTree(node->right);
    }
}

void printList(struct listNode *head) { //print the list
    cout<<"Linked List :";
    while(head != NULL) {
        cout<<" "<<head->data;
        head = head->next;
    }
    cout<<endl;
}

void convertListTree(struct listNode *head, struct treeNode **root) {
    if (head) {
        queue<struct treeNode *> q;
        *root = getTreeNode(head->data);
        q.push(*root);
        head = head->next;
        while (head) {
            struct treeNode *parent = q.front();
            q.pop();
            struct treeNode *leftChild = NULL, *rightChild = NULL;
            leftChild = getTreeNode(head->data);
            q.push(leftChild);
            head = head->next;
            if (head) {
                rightChild = getTreeNode(head->data);
                q.push(rightChild);
                head = head->next;
            }
            parent->left = leftChild;
            parent->right = rightChild;
        }
    } else {
        *root = NULL;
    }
}

int main() {
    struct listNode* head = NULL;
    push_front(&head, 36);
    push_front(&head, 30);
    push_front(&head, 25);
    push_front(&head, 15);
    push_front(&head, 12);
    push_front(&head, 10);
    printList(head);
    struct treeNode *root;
    convertListTree(head, &root);
    cout<<"Tree :", printTree(root), cout<<endl;
    return 0;
}
