//to print all prefixes that uniquely represent words
#include<bits/stdc++.h>
using namespace std;
#define ALPHABET 256
#define MAX_WORD_LEN 500

struct TrieNode {
    struct TrieNode *child[ALPHABET];
    int freq;
};

struct TrieNode *getNode(void) {
    struct TrieNode* temp = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    assert(temp);
    temp->freq = 1;
    for (int i = 0; i<ALPHABET; i++)
        temp->child[i] = NULL;
    return temp;
}

void insert(struct TrieNode *root, string str) {
    int len = str.length();
    struct TrieNode *curr = root;
    for (int level = 0; level<len; level++) {
        int index = str[level];
        if (!curr->child[index])
            curr->child[index] = getNode();
        else
           (curr->child[index]->freq)++;
        curr = curr->child[index];
    }
}

void findShortestUniquePrefix(struct TrieNode *root, char prefix[], int ind) {
    if (root) {
        if (root->freq == 1) {
            prefix[ind] = '\0';
            cout<<" "<<prefix;
        } else {
            for (int i=0; i<ALPHABET; i++) {
                if (root->child[i]) {
                    prefix[ind] = i;
                    findShortestUniquePrefix(root->child[i], prefix, ind+1);
                }
            }
        }
    }
}

void findShortestUniquePrefix(string arr[], int n) {
    struct TrieNode *root = getNode();
    root->freq = 0;
    for (int i = 0; i<n; i++)
        insert(root, arr[i]);
    char prefix[MAX_WORD_LEN];
    findShortestUniquePrefix(root, prefix, 0);
}

int main() {
    string arr[] = {"zebra", "dog", "duck", "dove"};
    cout<<"Shortest Unique prefixes are :";
    findShortestUniquePrefix(arr, sizeof(arr)/sizeof(arr[0]));
    cout<<endl;
    return 0;
}
