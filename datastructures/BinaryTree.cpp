//Binary Tree
#include<iostream>
#include<cstdlib>
#include<stack>
#include<queue>
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

void createTree(struct node **root) { //create a dummy tree for testing
    *root = getNode(1); 
    (*root)->left = getNode(2);
    (*root)->right = getNode(3);
    (*root)->left->left = getNode(4);
    (*root)->left->right = getNode(5);
    (*root)->right->left = getNode(6);
    (*root)->right->right = getNode(7);
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

void inOrder(struct node* node) { //Inorder traversal
    if(node == NULL)
        return;
    inOrder(node->left);
    cout<<" "<<node->data; 
    inOrder(node->right);
}
 
void preOrder(struct node* node) { //Preorder traversal
    if(node == NULL)
        return;
    cout<<" "<<node->data; 
    preOrder(node->left); 
    preOrder(node->right);
}

void postOrder(struct node* node) { //Postorder traversal
    if(node == NULL)
        return;
    postOrder(node->left);
    postOrder(node->right);
    cout<<" "<<node->data;
}

void levelOrder(struct node* node) { //Levelorder traversal
    cout<<"Level Order Traversal :";
    if(node != NULL) {  
        queue<struct node *> q;
        q.push(node);
        while(!q.empty()) {
            struct node *temp = q.front();
            cout<<" "<<temp->data;
            q.pop();
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
        }
    }
    cout<<endl;
}

void levelOrderReverse(struct node* node) { //Levelorder reverse traversal
    cout<<"Reverse Level Order Traversal :";
    if(node != NULL) {  
        stack<struct node *> s;
        queue<struct node *> q;
        q.push(node);
        while(!q.empty()) {
            struct node *temp = q.front();
            q.pop();
            s.push(temp);
            if(temp->right != NULL)
                q.push(temp->right);
            if(temp->left != NULL)
                q.push(temp->left);
        }
        while(!s.empty()) {
            struct node *temp = s.top();
            cout<<" "<<temp->data;
            s.pop();
        }
    }
    cout<<endl;
}

void levelOrderSpiral(struct node* node) { //Levelorder Spiral traversal
    cout<<"Spiral Level Order Traversal :";
    if(node != NULL) {  
        stack<struct node*> s1;
        stack<struct node*> s2;
        s1.push(node);
        while (!s1.empty() || !s2.empty()) {
            while (!s1.empty()) {
                struct node *temp = s1.top();
                s1.pop();
                cout<<" "<<temp->data;
                if(temp->right != NULL)
                    s2.push(temp->right);
                if(temp->left != NULL)
                    s2.push(temp->left);
            }
            while (!s2.empty()) {
                struct node *temp = s2.top();
                s2.pop();
                cout<<" "<<temp->data;
                if(temp->left != NULL)
                    s1.push(temp->left);
                if(temp->right != NULL)
                    s1.push(temp->right);
       
            }
        }
    }
    cout<<endl;
}

void printLeaves(struct node* node) { //print all leaves of the (sub)tree rooted at node
    if(node) {
        printLeaves(node->left);
        if(!(node->left) && !(node->right))
            cout<<" "<<node->data;
        printLeaves(node->right);
    }
}
 
void printLeftBoundary(struct node* node) { //print left boundary except the leaves in top-down fashion
    if(node) {
        if(node->left) {
            cout<<" "<<node->data;
            printLeftBoundary(node->left);
        } else if(node->right) {
            cout<<" "<<node->data;
            printLeftBoundary(node->right);
        }
    }
}

void printRightBoundary(struct node* node) { //print right boundary except the leaves and root in bottom-up fashion
    if(node) {
        if(node->right) {
            printRightBoundary(node->right);
            cout<<" "<<node->data;
        } else if( node->left ) {
            printRightBoundary(node->left);
            cout<<" "<<node->data;
        }
    }
}

void boundaryTraversal(struct node* node) { //Boundary traversal of tree
    cout<<"Boundary Traversal :";
    if(node) {
        cout<<" "<<node->data;
        printLeftBoundary(node->left);
        printLeaves(node->left);
        printLeaves(node->right);
        printRightBoundary(node->right);
    }
    cout<<endl;
}

int main() {
    struct node *t = NULL;
    createTree(&t);
    cout<<"In Order :", inOrder(t), cout<<endl;
    cout<<"Pre Order :", preOrder(t), cout<<endl;
    cout<<"Post Order :", postOrder(t), cout<<endl;
    levelOrder(t);
    levelOrderReverse(t);
    levelOrderSpiral(t);
    boundaryTraversal(t);
    deleteTree(&t);
    levelOrder(t);
    return 0;   
}
