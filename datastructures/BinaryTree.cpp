//Binary Tree
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<iostream>
#include<cstdlib>
#include<climits>
#include<cstring>
#include<cmath>
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

void printVerticalOrderSum(struct node *node) { //print vertical order sums of a tree
    unordered_map<int, vector<int>> hash;
    int hd = 0;
    cout<<"Vertical Order Sums :\n";
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
        int sum = 0;
        for (vector<int>::iterator it=hash[arr[i]].begin(); it!=hash[arr[i]].end(); it++)
            sum += *it;
        cout<<" "<<sum;
    }
    cout<<endl;
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

bool printAncestors(struct node *node, struct node *key) {
    if(node) {
        if (node == key) {
            return true;
        }else if(printAncestors(node->left, key) || printAncestors(node->right, key)) {
            cout<<" "<<node->data;
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void printAncestorsItr(struct node *node, struct node *key) {
    cout<<"Ancestors of "<<key->data<<" :";
    if(node) {
        stack<struct node *> s;
        while (1) { //traverse the complete tree in postorder way till we find the key
            while(node && node->data != key->data) { //while traversing the left side push into stack to traverse right sub tree later
                s.push(node);
                node = node->left;
            }
            if(node && node->data == key->data) //break if the node whose ancestors are to be printed is found
                break;
            if (s.top()->right == NULL) { //check if right sub-tree exists for the node at top
                node = s.top();
                s.pop();
                while (!s.empty() && s.top()->right == node) { //if the popped node is right child of top, then remove the top
                    node = s.top();
                    s.pop();
                }
            }
            node = s.empty()? NULL: s.top()->right; //start traversing right sub tree if stack is not empty
        }
        while(!s.empty()) { //print the stack which contains the ancestors
            cout<<" "<<s.top()->data;
            s.pop();
        }
    }
    cout<<endl;
}

int getLevel(struct node *node, struct node *key, int lvl=1) { //returns level of key if present else returns 0
    if(node == NULL)
        return 0;
    if(node == key)
        return lvl;
    int level = getLevel(node->left, key, lvl+1);
    if(level != 0) //return level only if key is found
        return level;
    level = getLevel(node->right, key, lvl+1); //return level no matter what
    return level;
}

bool isSibling(struct node *node, struct node *key1, struct node *key2) {//check if key1 and key2 are siblings
    if(node==NULL)
        return false;
    return((node->left == key1 && node->right==key2)||(node->left == key2 && node->right == key1)||isSibling(node->left, key1, key2)||isSibling(node->right, key1, key2));
}

bool isCousin(struct node *node, struct node *key1, struct node *key2) {//check if key1 and key2 are cousins
    if((getLevel(node, key1) == getLevel(node, key2)) && !(isSibling(node, key1, key2)))
        return true;
    else
        return false;
}

bool checkAllLeavesSameLevel(struct node *node, int *leaflvl, int lvl=0) {//check if all leaves are at the same level
    if(node==NULL) {
        return true;
    } else if(node->left == NULL && node->right == NULL) {
        if (*leaflvl == 0) {//set first found leaf's level
            *leaflvl = lvl;
            return true;
        } else {
            return (lvl == *leaflvl);
        }
    } else { //recur
        return (checkAllLeavesSameLevel(node->left, leaflvl, lvl+1)&&checkAllLeavesSameLevel(node->right, leaflvl, lvl+1));
    }
}

int getMaxWidth(struct node *node) { //max width of a tree
    if(node == NULL) {
        return 0;
    } else {
        queue<struct node *> q;
        q.push(node);
        int max_width = 1;
        while(1) { //this loop will run a max time of node count in tree
            int width = q.size();
            if(width == 0)
                return max_width;
            if(width > max_width)
                max_width = width;
            while (width > 0) {
                struct node *node = q.front();
                q.pop();
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
                width--;
            }
        }
    }
}

int getDiameter(struct node *node){ //get diameter of a tree
    if(node) {
        int lheight = getHeight(node->left);
        int rheight = getHeight(node->right);
        int ldiameter = getDiameter(node->left);
        int rdiameter = getDiameter(node->right);
        return max(lheight+rheight+1, max(ldiameter, rdiameter));
    } else {
        return 0;
    }
}

bool checkNode(struct node *node, struct node *key) { //check if key belongs to a tree
    if(node) {
        if(node == key || checkNode(node->left, key) || checkNode(node->right, key))
            return true;
        else
            return false;
    } else {
        return false;
    }
}

struct node *getLCARecr(struct node *node, struct node *key1, struct node *key2, bool *found1, bool *found2) { //recr util to find LCA
    if (node) { //if either key1 or key2 matches with root, report the presence and return root
        if (node == key1) {
            *found1 = true;
            return node;
        }
        else if (node == key2) {
            *found2 = true;
            return node;
        } else { //look for keys in left and right subtrees
            struct node *left_lca = getLCARecr(node->left, key1, key2, found1, found2);
            struct node *right_lca = getLCARecr(node->right, key1, key2, found1, found2);
            if(left_lca&&right_lca) //if both of the above calls return non NULL, this node is the LCA
                return node;
            else
                return (left_lca != NULL)? left_lca: right_lca;
        }
    } else {
        return NULL;
    }
}

struct node *getLCA(struct node *node, struct node *key1, struct node *key2) { //find least common ancestor of key1 and key2
    bool k1 = false;
    bool k2 = false;
    struct node *lca = getLCARecr(node, key1, key2, &k1, &k2);
    if(k1 && k2 || k1 && checkNode(lca, key2) || k2 && checkNode(lca, key1)) //return LCA only if both key1 and key2 are present in tree
        return lca;
    else
        return NULL;
}

struct node *getDistRecr(struct node *node, struct node *key1, struct node *key2, int *d1, int *d2, int *dist, int lvl) { //util to find dist
    if (node) { //if either key1 or key2 matches with root, report the presence and return root
        if (node == key1) {
            *d1 = lvl;
            return node;
        }
        else if (node == key2) {
            *d2 = lvl;
            return node;
        } else { //look for keys in left and right subtrees
            struct node *left_lca = getDistRecr(node->left, key1, key2, d1, d2, dist, lvl+1);
            struct node *right_lca = getDistRecr(node->right, key1, key2, d1, d2, dist, lvl+1);
            if(left_lca&&right_lca) { //if both of the above calls return non NULL, this node is the LCA
                *dist = (*d1) + (*d2) - 2*lvl;
                return node;
            } else {
                return (left_lca != NULL)? left_lca: right_lca;
            }
        }
    } else {
        return NULL;
    }
}

int getDistance(struct node *node, struct node *key1, struct node *key2) { //find distance between key1 and key2
    int d1 = -1;
    int d2 = -1;
    int dist;
    struct node *lca = getDistRecr(node, key1, key2, &d1, &d2, &dist, 1);
    if (d1 != -1 && d2 != -1)  //return dist if both key1 and key2 are present in tree
        return dist;
    else if (d1 != -1) //if key1 is ancestor of key2, consider key1 as root and find level of key2 in subtree rooted with key1
        dist = getLevel(lca, key2, 0);
    else if (d2 != -1) //if key2 is ancestor of key1, consider key2 as root and find level of key1 in subtree rooted with key2
        dist = getLevel(lca, key1, 0);
    else //else return -1
        dist = -1;
    return dist;
}

int depthOfOddLeaf(struct node *node, int level=0) { //get depth of the deepest odd level leaf
    if(node) {
        if(node->left==NULL && node->right==NULL && level&1) //return level if node is leaf with odd level
            return level;
         else //else max from left and right subtree
            return max(depthOfOddLeaf(node->left, level+1),depthOfOddLeaf(node->right, level+1));
    } else {
        return 0;
    }
}

int depthDeepestLeftLeafNode(struct node *node, int level=0, bool left=false){ //get depth of deepest leaf node
    if(node) {
        if(left && node->left==NULL && node->right==NULL)
            return level;
        else
            return max(depthDeepestLeftLeafNode(node->left, level+1, true),depthDeepestLeftLeafNode(node->right, level+1, false));
    } else {
        return 0;
    }
}

struct node* deepestLeftLeaf(struct node *node, int depth, int lvl=0, bool left=false){//get the left leaf node at level depth
    if (node) {
        if(left && lvl==depth && node->left==NULL && node->right==NULL)
            return node;
        struct node * temp;
        temp = deepestLeftLeaf(node->left, depth, lvl+1, true);
        if(temp)
            return temp;
        return deepestLeftLeaf(node->right, depth, lvl+1, false);
    } else {
        return NULL;
    }
}

struct node* getNextRight(struct node *node, struct node *key) { //get the nest right node
    if (node) {
        queue<struct node *> qn; //store nodes
        queue<int> ql; //store node levels
        struct node *temp = node;
        int level = 0;
        qn.push(temp);
        ql.push(level);
        while(!qn.empty()) {//level order traversal
            temp = qn.front();
            level = ql.front();
            qn.pop();
            ql.pop();
            if (temp == key) {
                if (ql.empty()|| ql.front() != level) //return NULL if no more items in queue or this isthe rightmost node of its level
                    return NULL;
                else //else return next node
                    return qn.front();
            }
            if (temp->left) {
                qn.push(temp->left);
                ql.push(level+1);
            }
            if (temp->right != NULL) {
                qn.push(temp->right);
                ql.push(level+1);
            }
        }
        return NULL;
    } else {
        return NULL;
    }
}

bool printPath(struct node *node, struct node *target) { //print path from node to target
    if( node && (node==target||printPath(node->left, target)||printPath(node->right, target)) ) {
        cout<<" "<<node->data;
        return true;
    }
    return false;
}

void maxSumPathRootLeafTarget(struct node *node, int *max_sum, int curr_sum, struct node **target) {
    if (node) {
        curr_sum = curr_sum + node->data;
        if (node->left == NULL && node->right == NULL) { //if this is a leaf node and ,
            if (curr_sum > *max_sum) { //if path to this node has max sum so far
                *max_sum = curr_sum;
                *target = node;
            }
        } else { //recur
            maxSumPathRootLeafTarget(node->left, max_sum, curr_sum, target);
            maxSumPathRootLeafTarget(node->right, max_sum, curr_sum, target);
        }
    }
}

void maxSumPathRootLeaf(struct node *node) {
    cout<<"Max Sum Path :";
    if(node) {
        struct node *target;
        int max_sum = INT_MIN;
        maxSumPathRootLeafTarget(node, &max_sum, 0, &target); //find target
        printPath(node, target); //print path
    }
    cout<<endl;
}

int maxSumPathLeaves(struct node *node, int *res) { //find the max sum between any two leaves
    if(node){
        int lSum = maxSumPathLeaves(node->left, res);
        int rSum = maxSumPathLeaves(node->right, res);
        int curr_sum = max((lSum+rSum+node->data), max(lSum, rSum));
        if(*res < curr_sum)
            *res = curr_sum;
        return max(lSum, rSum)+node->data;
    } else {
        return 0;
    }
}

bool checkPathSum(struct node* node, int sum){ //check if root to leaf path sum exists
    if(node) {
        int subSum = sum - node->data;
        if((subSum == 0 && node->left == NULL && node->right == NULL)||(node->left && checkPathSum(node->left, subSum))||(node->right && checkPathSum(node->right, subSum)))
            return true;
         else
            return false;
    } else {//return true if we run out of tree and sum equals 0
         return (sum == 0);
    }
}

int getTreePathsSum(struct node *node, int val=0) { //get sum of all root to leaf paths
    if(node){
        val = val*10 + node->data;
        if (node->left==NULL && node->right==NULL)
            return val;
        else
            return getTreePathsSum(node->left, val) + getTreePathsSum(node->right, val);
    } else {
        return 0;
    }
}

int getLevelDiff(struct node *node) { //difference between odd and even level nodes
    if(node)
        return node->data - getLevelDiff(node->left) - getLevelDiff(node->right);
    else
        return 0;
}

void printKDistantRoot(struct node *node, int k) { //print all nodes that are k distant from node
    if(node) {
        if(k==0) { //print if required level
            cout<<" "<<node->data;
        } else { //else recur
            printKDistantRoot(node->left, k-1);
            printKDistantRoot(node->right, k-1);
        }
    }
}

void kDistantLeaf(struct node *node, int path[], bool visited[], int pathLen, int k) { //get all nodes that are k distant from a leaf node
    if(node) {
        path[pathLen] = node->data;
        visited[pathLen] = false;
        pathLen++;
        if (node->left == NULL && node->right == NULL && pathLen-k-1 >= 0 && visited[pathLen-k-1] == false) {
            cout<<" "<<path[pathLen-k-1];
            visited[pathLen-k-1] = true;
        }else {
            kDistantLeaf(node->left, path, visited, pathLen, k);
            kDistantLeaf(node->right, path, visited, pathLen, k);
        }
    }
}

void printKDistantLeaf(struct node *node, int k) {//print all nodes that are k distant from a leaf node
    cout<<"All nodes that are "<<k<<" distant from a leaf node :";
    int h = getHeight(node);
    int path[h];
    bool visited[h];
    memset(visited, false, h);
    kDistantLeaf(node, path, visited, 0, k);
    cout<<endl;
}

int printKDistantNode(struct node* node, struct node* target, int k) {//print all nodes that are k distant from target
    if(node){
        if(node == target) {
            printKDistantRoot(node, k);
            return 0;
        }
        int dl = printKDistantNode(node->left, target, k);
        if (dl != -1) {
            if (dl + 1 == k) //if root is at distance k from target, print root
                cout<<" "<<node->data;
            else //else go to right subtree and print all k-dl-2 distant nodes
                printKDistantRoot(node->right, k-dl-2);
            return 1 + dl;
        }
        int dr = printKDistantNode(node->right, target, k);
        if (dr != -1) {
            if (dr + 1 == k) //if root is at distance k from target, print root
                cout<<" "<<node->data;
            else //else go to left subtree and print all k-dr-2 distant nodes
                printKDistantRoot(node->left, k-dr-2);
             return 1 + dr;
        }
        return -1; //target was neither present in left nor in right subtree
    } else {
        return -1;
    }
}

void printBetweenLevels(struct node* node, int low, int high) {
    cout<<"Nodes in levels ["<<low<<","<<high<<"] :";
    queue <struct node *> q;
    struct node *marker = getNode(0);
    int level = 1;
    q.push(node);
    q.push(marker);
    while(!q.empty()) { //level order traversal
        struct node *temp = q.front();
        q.pop();
        if (temp == marker) {
            level++;
            if(q.empty()||level>high)
                break;
            q.push(marker);
            continue;
        }
        if(level>=low)
            cout<<" "<<temp->data;
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    free(marker);
    cout<<endl;
}

void printArray(int path[], int len) { //print path array
    for(int i=0; i<len; i++)
        cout<<" "<<path[i];
    cout<<endl;
}

void printPaths(struct node* node, int path[], int pathLen) {
    if(node) { //add to path
        path[pathLen] = node->data;
        pathLen++;
        if (node->left==NULL && node->right==NULL) { //print if leaf
            printArray(path, pathLen);
        } else { //recur
            printPaths(node->left, path, pathLen);
            printPaths(node->right, path, pathLen);
        }
    }
}

void printAllRootLeafPaths(struct node* node) { //print all root to leaf paths in tree
    int n = getHeight(node);
    int path[n];
    cout<<"All Root to Leaf paths are :\n";
    printPaths(node, path, 0);
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
    printVerticalOrderSum(t);
    cout<<"Print ancestors :", printAncestors(t, t->left->right), cout<<endl;
    printAncestorsItr(t, t->left->right);
    cout<<"Level : "<<getLevel(t, t->left->right)<<endl;
    cout<<"Level : "<<getLevel(t, t->left->right->left)<<endl;
    cout<<"Check Sibling : "<<isSibling(t, t->left, t->right)<<endl;
    cout<<"Check Sibling : "<<isSibling(t, t->left, t->right->right)<<endl;
    cout<<"Check Cousin : "<<isCousin(t, t->left, t->right)<<endl;
    cout<<"Check Cousin : "<<isCousin(t, t->left->right, t->right->right)<<endl;
    int temp = 0;
    cout<<"Check all leaves same level : "<<checkAllLeavesSameLevel(t, &temp)<<endl;
    cout<<"Max Width : "<<getMaxWidth(t)<<endl;
    cout<<"Diameter : "<<getDiameter(t)<<endl;
    cout<<"Checking node : "<<checkNode(t, t->left)<<endl;
    cout<<"Checking node : "<<checkNode(t, t->left->left->left)<<endl;
    struct node *res;
    res = getLCA(t, t->left->left, t->right);
    if(res)
        cout<<"LCA : "<<res->data<<endl;
    else
        cout<<"LCA does not exist"<<endl;
    res = getLCA(t, t->left->left, t->left->right);
    if(res)
        cout<<"LCA : "<<res->data<<endl;
    else
        cout<<"LCA does not exist"<<endl;
    res = getLCA(t, t->left, t->right->left->left);
    if(res)
        cout<<"LCA : "<<res->data<<endl;
    else
        cout<<"LCA does not exist"<<endl;
    cout<<"Distance : "<<getDistance(t, t->left->left, t->right)<<endl;
    cout<<"Distance : "<<getDistance(t, t->left->left, t->left->right)<<endl;
    cout<<"Distance : "<<getDistance(t, t->left, t->right->left->left)<<endl;
    cout<<"Depth of the deepest odd level leaf :"<<depthOfOddLeaf(t)<<endl;
    int d = depthDeepestLeftLeafNode(t);
    cout<<"Depth of deepest leaf node : "<<d<<endl;
    res = deepestLeftLeaf(t, d);
    cout<<"Deepest leaf node : "<<res->data<<endl;
    res = getNextRight(t, t->left->right);
    if(res)
        cout<<"Next Right : "<<res->data<<endl;
    else
        cout<<"Next Right do not exist\n";
    res = getNextRight(t, t->right->right);
    if(res)
        cout<<"Next Right : "<<res->data<<endl;
    else
        cout<<"Next Right do not exist\n";
    res = getNextRight(t, t->right);
    if(res)
        cout<<"Next Right : "<<res->data<<endl;
    else
        cout<<"Next Right do not exist\n";
    maxSumPathRootLeaf(t);
    d = 0;
    maxSumPathLeaves(t, &d);
    cout<<"Max sum between leaves = "<<d<<endl;
    cout<<"Tree "<<((checkPathSum(t,8))?"does":"does not")<<" have root to leaf path of sum 8\n";
    cout<<"Tree "<<((checkPathSum(t,9))?"does":"does not")<<" have root to leaf path of sum 9\n";
    cout<<"Sum of all paths : "<<getTreePathsSum(t)<<endl;
    cout<<"Difference between sums of odd and even levels : "<<getLevelDiff(t)<<endl;
    cout<<"All nodes that are 1 distant from node :",printKDistantRoot(t,1),cout<<endl;
    cout<<"All nodes that are 2 distant from node :",printKDistantRoot(t,2),cout<<endl;
    printKDistantLeaf(t, 1);
    printKDistantLeaf(t, 2);
    cout<<"All nodes that are 1 distant from target",printKDistantNode(t, t->left, 1),cout<<endl;
    cout<<"All nodes that are 2 distant from target",printKDistantNode(t, t->left, 2),cout<<endl;
    cout<<"All nodes that are 3 distant from target",printKDistantNode(t, t->left, 3),cout<<endl;
    printBetweenLevels(t, 2, 2);
    printBetweenLevels(t, 1, 3);
    printAllRootLeafPaths(t);
    deleteTree(&t);
    levelOrder(t);
    return 0;   
}
