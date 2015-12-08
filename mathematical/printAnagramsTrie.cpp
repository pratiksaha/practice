// An efficient program to print all anagrams together
#include<bits/stdc++.h>
using namespace std;
#define ALPHABET 26

struct IndexNode {
    int index;
    struct IndexNode* next;
};

struct IndexNode* getIndexNode(int index) {
    struct IndexNode* temp = (struct IndexNode *)malloc(sizeof(struct IndexNode));
    assert(temp);
    temp->index = index;
    temp->next = NULL;
    return temp;
}

struct TrieNode {
    bool isEnd;
    struct TrieNode* child[ALPHABET];
    struct IndexNode* head;
};

struct TrieNode* getTrieNode() {
    struct TrieNode* temp = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    assert(temp);
    temp->isEnd = 0;
    temp->head = NULL;
    for (int i=0; i<ALPHABET; i++)
        temp->child[i] = NULL;
    return temp;
}

int compare(const void* a, const void* b) {
    return *(char*)a - *(char*)b;
}

void insert(struct TrieNode** root, char* word, int index) {
    if (*root == NULL)
        *root = getTrieNode();
 
    if (*word != '\0') {
        insert( &((*root)->child[tolower(*word)-'a'] ), word+1, index );
    } else {
        if ((*root)->isEnd) {
            IndexNode* curr = (*root)->head;
            while( curr->next )
                curr = curr->next;
            curr->next = getIndexNode(index);
        } else {
            (*root)->isEnd = 1;
            (*root)->head = getIndexNode(index);
        }
    }
}

void printAnagrams(struct TrieNode* root, char *wordArr[]) {
    if (root) {
        if (root->isEnd) {
            IndexNode* curr = root->head;
            while (curr) {
                cout<<" "<<wordArr[curr->index];
                curr = curr->next;
            }
        }
        for (int i=0; i<ALPHABET; i++)
            printAnagrams(root->child[i], wordArr);
    }
}

void printAnagrams(char* wordArr[], int size) {
    struct TrieNode* root = NULL;
    for (int i=0; i<size; i++) {
        int len = strlen(wordArr[i]);
        char *buffer = new char[len+1];
        strcpy(buffer, wordArr[i]);
        qsort( (void*)buffer, strlen(buffer), sizeof(char), compare );
        insert(&root,  buffer, i);
    }
    printAnagrams(root, wordArr);
}

int main() {
    char* wordArr[] = {"cat", "dog", "tac", "god", "act", "gdo"};
    cout<<"Printing Anagrams together :";
    printAnagrams(wordArr, sizeof(wordArr)/sizeof(wordArr[0]));
    cout<<endl;
    return 0;
}
