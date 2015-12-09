//to print all decodings
#include<bits/stdc++.h>
using namespace std;

char alphabet[] = {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

struct node {
    char *data;
    struct node *left;
    struct node *right;
};

struct node * getNode(char *key) { //allocate memory and initialize
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    if(temp == NULL) {
        cout<<"Memory full\n";
        exit(1);
    }
    temp->data = strdup(key);
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

struct node* createTree(int data, string temp, int a[], int i, int n) {
    //cout<<data<<endl;
    if (data >=0 && data<=26) {
        string curr = temp;
        char c = alphabet[data];
        if (c!=' ')
            curr.push_back(c);
        //cout<<curr<<" "<<i<<" "<<data<<endl;
        struct node *root = getNode((char *)(curr.c_str()));
        //cout<<"here\n";
        if (i+1<n) {
            root->left = createTree(a[i+1], curr, a, i+1, n);
            if (i+2<n) {
                root->right = createTree(a[i+1]*10 + a[i+2], curr, a, i+2, n);
            }
        }
        return root;
    } else {
        return NULL;
    }
}

void printLeaves(struct node* node) {
    if (node) {
        if (!node->left && !node->right)
            cout<<" "<<node->data;
        printLeaves(node->left);
        printLeaves(node->right);
    }
}

void printDecoding(int a[], int n) {
    struct node *root = createTree(0, "", a, -1, n);
    cout<<"All decodings for ";
    for (int i=0; i<n; i++)
        cout<<a[i];
    cout<<" are :";
    printLeaves(root);
    cout<<endl;
    deleteTree(&root);
}

int main() {
    int arr1[] = {1, 1, 3, 4};
    printDecoding(arr1, sizeof(arr1)/sizeof(arr1[0]));
    int arr2[] = {1, 1, 1};
    printDecoding(arr2, sizeof(arr2)/sizeof(arr2[0]));
    int arr3[] = {2, 6};
    printDecoding(arr3, sizeof(arr3)/sizeof(arr3[0])); 
    int arr4[] = {1, 2};
    printDecoding(arr4, sizeof(arr4)/sizeof(arr4[0]));
    int arr5[] = {1, 0};
    printDecoding(arr5, sizeof(arr5)/sizeof(arr5[0]));
    int arr6[] = {};
    printDecoding(arr6, sizeof(arr6)/sizeof(arr6[0]));
    int arr7[] = {1, 2, 2, 1};
    printDecoding(arr7, sizeof(arr7)/sizeof(arr7[0]));
    return 0;
}
