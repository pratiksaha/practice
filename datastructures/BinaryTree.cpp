//Binary Tree
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<iostream>
#include<cstdlib>
#include<stack>
#include<queue>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
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

bool isComplete(struct node* node) { //check if a tree is complete
    if(node == NULL) {
        return true;
    } else {
        queue<struct node *> q;
        bool nonFull = false; //marker to be set true when a non full node is seen
        q.push(node);
        while(!q.empty()) {
            struct node *temp = q.front();
            q.pop();
            if(temp->left) {
                if(nonFull) //if we have seen a non full node and we see a node with non-empty left child
                    return false;
                q.push(temp->left);
            } else { //this is a non full node if left child is empty
                nonFull = true;
            }
            if(temp->right) {
                if(nonFull) //if we have seen a non full node and we see a node with non-empty right child
                    return false;
                q.push(temp->right);
            } else { //this is a non full node if right child is empty
                nonFull = true;
            }
        }
        return true;
    }
}

int getSize(struct node* node) { //get size of a tree
    if(node == NULL)
        return 0;
    else
        return 1 + getSize(node->left) + getSize(node->right); //Size of a tree = 1 + Size of left subtree + Size of right subtree
}

int getLeafCount(struct node* node) { //get no of leaves
    if(node == NULL)
        return 0;
    else if(node->left == NULL && node->right==NULL) //this is a leaf
        return 1;
    else
        return getLeafCount(node->left) + getLeafCount(node->right); //leaf count of left subtree + leaf count of right subtree
}

int getHeight(struct node *node) { //get height of tree
    if(node == NULL)
       return 0;
    else
       return 1 + max(getHeight(node->left), getHeight(node->right)); //height = 1 + max(left subtree height,right subtree height)
}

int treeHeight(struct node *node) { //get height of tree iteratively
    if(node == NULL) {
        return 0;
    } else {
        queue<struct node *> q;
        q.push(node);
        int height = 0;
        while(1) { //this loop will run a max time of node count in tree
            int nodeCount = q.size();
            if (nodeCount == 0)
                return height;
            height++;
            while (nodeCount > 0) {
                struct node *node = q.front();
                q.pop();
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
                nodeCount--;
            }
        }
    }
}

bool isBalanced(struct node *node, int* height) { //check if tree is balanced
    if(node == NULL) {
        *height = 0;
        return true;
    } else {
        int lheight = 0, rheight = 0;
        bool lbal = isBalanced(node->left, &lheight);
        bool rbal = isBalanced(node->right, &rheight);
        *height = max(lheight, rheight) + 1;
        if(abs(lheight - rheight) >= 2)
            return false;
        else
            return lbal && rbal;
    }
}

bool isBalancedRBT(struct node *node, int *maxh, int *minh) { //chcek if tree is balanced as a red black tree
    if (node == NULL) {
        *maxh = *minh = 0;
        return true;
    } else {
        int lmxh, lmnh, rmxh, rmnh;
        if(isBalancedRBT(node->left, &lmxh, &lmnh) == false)
            return false;
        if(isBalancedRBT(node->right, &rmxh, &rmnh) == false)
            return false;
        *maxh = max(lmxh, rmxh) + 1;
        *minh = min(lmnh, rmnh) + 1;
        if(*maxh<=2*(*minh))
            return true;
        else
            return false;
    }
}

void findMinMaxHD(struct node *node, int *min, int *max, int hd) { //find min and max horizontal distance wrt root
    if (node != NULL) {
        if(hd < *min)
            *min = hd;
        else if(hd > *max)
            *max = hd;
        findMinMaxHD(node->left, min, max, hd-1);
        findMinMaxHD(node->right, min, max, hd+1);
    }
}

void printVerticalLine(struct node *node, int curr, int hd) { //print nodes in curr vertical line
    if (node != NULL){
        if (hd == curr)
            cout<<" "<<node->data;
        printVerticalLine(node->left, curr, hd-1);
        printVerticalLine(node->right, curr, hd+1);
    }
}

void printVerticalOrder(struct node *node) { //print vertical order of a tree
    int min = 0, max = 0;
    findMinMaxHD(node, &min, &max, 0);
    cout<<"Vertical Order :\n";
    for (int i=min; i<=max; i++)
        printVerticalLine(node, i, 0), cout<<endl;
}

void getVerticalOrderHash(struct node* node, int hd, unordered_map<int, vector<int>> *hash) { //create the vertical order hash
    if (node != NULL) {
        (*hash)[hd].push_back(node->data);
        getVerticalOrderHash(node->left, hd-1, hash);
        getVerticalOrderHash(node->right, hd+1, hash);
    }
}

void printVerticalOrderHash(struct node *node) { //print vertical order of a tree (hash based soln)
    unordered_map<int, vector<int>> hash;
    int hd = 0;
    cout<<"Vertical Order (hash) :\n";
    getVerticalOrderHash(node, hd, &hash);
    int i, n;
    n = hash.size();
    int arr[n];
    i = 0;
    for(unordered_map<int,vector<int>>:: iterator it=hash.begin(); it!=hash.end(); it++) {
        arr[i] = it->first;
        i++;
    }
    sort(arr, arr+n);
    for(i=0; i<n; i++) {
        for (vector<int>::iterator it=hash[arr[i]].begin(); it!=hash[arr[i]].end(); it++)
            cout<<" "<<*it;
        cout<<endl;
    }
}

void printLeftView(struct node *node, int lvl, int *max_so_far) {
    if(node) {
        if (*max_so_far<lvl) {
            cout<<" "<<node->data;
            *max_so_far = lvl;
        }
        printLeftView(node->left, lvl+1, max_so_far);
        printLeftView(node->right, lvl+1, max_so_far);
    }
}

void printRightView(struct node *node, int lvl, int *max_so_far) {
    if(node) {
        if (*max_so_far<lvl) {
            cout<<" "<<node->data;
            *max_so_far = lvl;
        }
        printRightView(node->right, lvl+1, max_so_far);
        printRightView(node->left, lvl+1, max_so_far);
    }
}

void printTopView(struct node *node) {
    cout<<"Top View : ";
    if(node) {
        struct nodeItem{
            struct node* key;
            int hd;
        };
        queue<struct nodeItem> q;
        unordered_set<int> s;
        struct nodeItem curr;
        curr.key = node;
        curr.hd = 0;
        q.push(curr);
        while(!q.empty()) {
            struct nodeItem temp = q.front();
            q.pop();
            if(s.find(temp.hd) == s.end()) {
                s.insert(temp.hd);
                cout<<" "<<temp.key->data;
            }
            if(temp.key->left) {
                curr.key = temp.key->left;
                curr.hd = temp.hd - 1;
                q.push(curr);
            }
            if(temp.key->right) {
                curr.key = temp.key->right;
                curr.hd = temp.hd + 1;
                q.push(curr);
            }
        }
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
    cout<<"Checking if tree is complete : "<<isComplete(t)<<endl;
    cout<<"Size of tree = "<<getSize(t)<<endl;
    cout<<"No of leaves = "<<getLeafCount(t)<<endl;
    cout<<"Height of tree = "<<getHeight(t)<<endl;
    cout<<"Height of tree (itr) = "<<treeHeight(t)<<endl;
    int h = 0;
    cout<<"Checking balance of the tree : "<<isBalanced(t, &h)<<endl;
    int m = 0, n = 0;
    cout<<"Checking balance of the tree as per RBT : "<<isBalancedRBT(t, &m, &n)<<endl;
    printVerticalOrder(t);
    printVerticalOrderHash(t);
    int tmp = 0;
    cout<<"Left View :", printLeftView(t, 0, &tmp), cout<<endl;
    tmp = 0;
    cout<<"Right View :", printRightView(t, 0, &tmp), cout<<endl;
    printTopView(t);
    deleteTree(&t);
    levelOrder(t);
    return 0;   
}
