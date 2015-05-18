//longest prefix match
#include<iostream>
#include<cstdlib>
#include<string>
#include<cassert>
using namespace std;

#define ALPHABET_SIZE 26
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

struct node {
    struct node* children[ALPHABET_SIZE];
    int value; //non-zero for leaf node
};

struct node* getNode() {
    struct node* temp = (struct node *)malloc(sizeof(struct node));
    assert(temp); //just in case malloc fails
    temp->value = 0;
    for (int i=0; i<ALPHABET_SIZE; i++)
        temp->children[i] = NULL;
    return temp;
}

bool checkLeaf(struct node* node) { //check if node is a leaf node
    return (node->value != 0); //node is leaf if value is non zero
}

bool checkDelete(struct node* node) { //check if node can be deleted
    for (int i=0; i<ALPHABET_SIZE; i++)
        if (node->children[i])
            return false;
    return true; //node can be deleted if all its children are NULL
}

void insertTrie(struct node* node, string key) {
    int len = key.size();
    for (int level=0; level<len; level++) {
        int idx = CHAR_TO_INDEX(key[level]);
        if (!node->children[idx]) //add a new child only if it is not yet seen
            node->children[idx] = getNode();
        node = node->children[idx]; //move to the child for next iteration
    }
    node->value = 1; //can be any non-zero value to indicate leaf node
}

string longestPrefixMatch(struct node* node, string key) {
    int len = key.size();
    string result = "";
    for (int level=0; level<len; level++) {
        int idx = CHAR_TO_INDEX(key[level]);
        if (!node->children[idx]) //child for the alphabet is NULL means key is not present
            return result;
        result.push_back(key[level]);
        node = node->children[idx]; //move to the child for next iteration
    }
    return result;
}

int main() {
    string keys[] = {"are", "area", "base", "cat", "cater", "basement"};
    struct node* root = getNode(); //dummy root node of trie
    for (int i=0; i<sizeof(keys)/sizeof(keys[0]); i++)
        insertTrie(root, keys[i]);
    string input[] = {"caterer", "basement", "are", "arex", "basemexz", "xyz"};
    int n = sizeof(input)/sizeof(input[0]);
    string output[n];
    for (int i=0; i<n; i++)
        output[i] = longestPrefixMatch(root, input[i]);
    for (int i=0; i<n; i++)
        cout<<input[i]<<"----------"<<output[i]<<endl;
    return 0;       
}
