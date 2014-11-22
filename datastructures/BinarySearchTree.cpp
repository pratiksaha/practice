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

struct node* kSmallest(struct node *node, int k, int* curr) { //find kth smallest node
    if(node) {
        struct node *temp = kSmallest(node->left, k, curr);
        if(temp)
            return temp;
        (*curr)++;
        if(k == *curr)
            return node;
        return kSmallest(node->right, k, curr);
    } else {
        return NULL;
    }
}

struct node* kLargest(struct node *node, int k, int *curr) { //find kth largest node
    if(node) {
        struct node *temp = kLargest(node->right, k, curr);
        if(temp)
            return temp;
        (*curr)++;
        if(k == *curr)
            return node;
        return kLargest(node->left, k, curr);
    } else {
        return NULL;
    }
}

struct node* removeOutsideRange(struct node *node, int minKey, int maxKey) { //remove nodes outside minKey and maxKey
    if(node) {
        node->left = removeOutsideRange(node->left, minKey, maxKey);
        node->right = removeOutsideRange(node->right, minKey, maxKey);
        if (node->data < minKey) {
            struct node *rChild = node->right;
            free(node);
            return rChild;
        } else if (node->data > maxKey) {
            struct node *lChild = node->left;
            free(node);
            return lChild;
        } else {
            return node; //node is in range
        }
    } else {
        return NULL;
    }
}

void inorderPreSuc(struct node *node, struct node *key, struct node **pre, struct node **suc) {//get the inorder predecessor & successor
    if(node) {
        if (node->data < key->data) { //goto right if key is greater than node
            *pre = node; //predecessor = node
            inorderPreSuc(node->right, key, pre, suc);
        } else if(node->data > key->data) { //goto left if key is smaller than node
            *suc = node; //successor = node
            inorderPreSuc(node->left, key, pre, suc);
        } else {
            if(node->left)
                *pre = maxBST(node->left); //max in left subtree is predecessor
            if(node->right)
                *suc = minBST(node->right); //min in right subtree is successor
        }
    }
}

struct node *lowestCommonAncestor(struct node* node, int key1, int key2) { //find the lowest common ancestor node
    while (node != NULL) {
        if (node->data > key1 && node->data > key2) //if both key1 and key2 are smaller than node, then LCA lies in left
            node = node->left;
        else if (node->data < key1 && node->data < key2) //if both key1 and key2 are greater than root, then LCA lies in right
            node = node->right;
        else //current node is the LCA
            break;
    }
    return node;
}

struct node* searchBST(struct node *node, int key) { //search key in the BST
    if(node && node->data < key)
        return searchBST(node->right, key);
    else if(node && node->data > key)
        return searchBST(node->left, key);
    else //node is NULL or node->data == key
        return node;
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

struct node* deleteNode(struct node* node, int key) {
    if(node) {
        if (node->data < key) {
            node->right = deleteNode(node->right, key);
        } else if (node->data > key) {
            node->left = deleteNode(node->left, key);
        } else {
            if(!node->left && !node->right) {
                free(node);
                return NULL;
            } else if(!(node->left)) {
                struct node *temp = node->right;
                free(node);
                return temp;
            } else if(!(node->right)) {
                struct node *temp = node->left;
                free(node);
                return temp;
            } else {
                struct node* temp = minBST(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }
    }
    return node; //either node is NULL or deleted node had 2 children
}

int main() {
    struct node *t = NULL;
    struct node *temp = NULL;
    struct node *p, *s;
    int tmp = 0;
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
    cout<<"Tree :", printTree(t), cout<<endl;
    cout<<(isBST(t)?"Is a Binary Search Tree":"Is NOT a Binary Search Tree")<<endl;
    cout<<"Min = "<<minBST(t)->data<<endl;
    cout<<"Max = "<<maxBST(t)->data<<endl;
    cout<<"All range = ", printRange(t), cout<<endl;
    cout<<"Within range [10, 75] = ", printRange(t, 10, 75), cout<<endl;
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
    tmp = 0, temp = kSmallest(t, 0, &tmp), cout<<"0th smallest in tree= ", (temp)?cout<<temp->data<<endl:cout<<"Not exist "<<endl;
    tmp = 0, temp = kLargest(t, 0, &tmp), cout<<"0th largest in tree= ", (temp)?cout<<temp->data<<endl:cout<<"Not exist "<<endl;
    tmp = 0, temp = kSmallest(t, 17, &tmp), cout<<"17th smallest in tree= ", (temp)?cout<<temp->data<<endl:cout<<"Not exist "<<endl;
    tmp = 0, temp = kLargest(t, 17, &tmp), cout<<"17th largest in tree= ", (temp)?cout<<temp->data<<endl:cout<<"Not exist "<<endl;
    tmp = 0, temp = kSmallest(t, 1, &tmp), cout<<"1th smallest in tree= ", (temp)?cout<<temp->data<<endl:cout<<"Not exist "<<endl;
    tmp = 0, temp = kLargest(t, 1, &tmp), cout<<"1th largest in tree= ", (temp)?cout<<temp->data<<endl:cout<<"Not exist "<<endl;
    tmp = 0, temp = kSmallest(t, 16, &tmp), cout<<"16th smallest in tree= ", (temp)?cout<<temp->data<<endl:cout<<"Not exist "<<endl;
    tmp = 0, temp = kLargest(t, 16, &tmp), cout<<"16th largest in tree= ", (temp)?cout<<temp->data<<endl:cout<<"Not exist "<<endl;
    tmp = 0, temp = kSmallest(t, 2, &tmp), cout<<"2th smallest in tree= ", (temp)?cout<<temp->data<<endl:cout<<"Not exist "<<endl;
    tmp = 0, temp = kLargest(t, 2, &tmp), cout<<"2th largest in tree= ", (temp)?cout<<temp->data<<endl:cout<<"Not exist "<<endl;
    tmp = 0, temp = kSmallest(t, 8, &tmp), cout<<"8th smallest in tree= ", (temp)?cout<<temp->data<<endl:cout<<"Not exist "<<endl;
    tmp = 0, temp = kLargest(t, 8, &tmp), cout<<"8th largest in tree= ", (temp)?cout<<temp->data<<endl:cout<<"Not exist "<<endl;
    cout<<"Removing nodes outside 2&89", t = removeOutsideRange(t, 2, 89); cout<<" Tree:", printTree(t), cout<<endl;
    inorderPreSuc(t, t, &p, &s), cout<<"For 50", (p)?cout<<" Pre :"<<p->data:cout<<"NA", (s)?cout<<" Suc :"<<s->data:cout<<"NA", cout<<endl;
    inorderPreSuc(t, t->left, &p, &s), cout<<"For 25", (p)?cout<<" Pre :"<<p->data:cout<<"NA", (s)?cout<<" Suc :"<<s->data:cout<<"NA", cout<<endl;
    inorderPreSuc(t, t->right, &p, &s), cout<<"For 75", (p)?cout<<" Pre :"<<p->data:cout<<"NA", (s)?cout<<" Suc :"<<s->data:cout<<"NA", cout<<endl;
    inorderPreSuc(t, t->left->right->right, &p, &s), cout<<"For 45", (p)?cout<<" Pre :"<<p->data:cout<<"NA", (s)?cout<<" Suc :"<<s->data:cout<<"NA", cout<<endl;
    inorderPreSuc(t, t->right->left->left, &p, &s), cout<<"For 55", (p)?cout<<" Pre :"<<p->data:cout<<"NA", (s)?cout<<" Suc :"<<s->data:cout<<"NA", cout<<endl;
    cout<<"Lowest Common Ancestor of 5 & 45 :", temp = lowestCommonAncestor(t, 5, 45), (temp)?cout<<temp->data:"NA", cout<<endl;
    cout<<"Deleting 45", t = deleteNode(t, 45), cout<<" Tree:", printTree(t), cout<<endl;
    cout<<"Deleting 55", t = deleteNode(t, 55), cout<<" Tree:", printTree(t), cout<<endl;
    cout<<"Deleting 5", t = deleteNode(t, 5), cout<<" Tree:", printTree(t), cout<<endl;
    cout<<"Deleting 60", t = deleteNode(t, 60), cout<<" Tree:", printTree(t), cout<<endl;
    cout<<"Deleting 50", t = deleteNode(t, 50), cout<<" Tree:", printTree(t), cout<<endl;
    deleteTree(&t), cout<<"Deleted Tree :", printTree(t),cout<<endl;
    return 0;
}
