//Print unique rows of a boolean matrix
#include<iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;
#define R 4
#define C 5
#define W 2

void printRow(int M[R][C], int r) {
    for(int j=0; j<C; j++)
        cout<<setw(W)<<M[r][j];
    cout<<endl;
} 

typedef struct Node {
    bool isEndOfCol;
    struct Node *child[2]; //only two children needed for 0 and 1
} Node; // A Trie node

Node* newNode() {
    Node* temp = (Node *)malloc(sizeof(Node));
    temp->isEndOfCol = 0;
    temp->child[0] = NULL;
    temp->child[1] = NULL;
    return temp;
}

bool insert(Node** root, int M[R][C], int r, int c) {
    if ( *root == NULL )
        *root = newNode();
 
    if (c<C) { //recur if there are more entries in this row
        return insert ( &((*root)->child[M[r][c]]), M, r, c+1);
    } else  { //if all entries of this row are processed 
        if ( !( (*root)->isEndOfCol ) )
            return (*root)->isEndOfCol = 1; //unique row
        return 0; //duplicate row
    }
}

void findUniqueRows(int M[R][C]) {
    Node* root = NULL;
    for (int i=0; i<R; i++)
        if (insert(&root, M, i, 0)) //if row inserted to trie, it is unique, print it
            printRow(M, i);
}

int main() {
    int M[R][C] = { {0, 1, 0, 0, 1},
                    {1, 0, 1, 1, 0},
                    {0, 1, 0, 0, 1},
                    {1, 0, 1, 0, 0}
                  };
    cout<<"Input Matrx :\n";
    for(int i=0; i<R; i++)
        printRow(M, i);
    cout<<"Unique Rows :\n";
    findUniqueRows(M);
    return 0;
}
