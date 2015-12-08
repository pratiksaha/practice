//to find max subarray XOR
#include<bits/stdc++.h>
using namespace std;

#define INT_SIZE sizeof(int)*8

struct TrieNode {
    int value;
    TrieNode *arr[2];
};

struct TrieNode* getNode() {
    struct TrieNode* temp = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    assert(temp);
    temp->value = 0;
    temp->arr[0] = temp->arr[1] = NULL;
    return temp;
}

void insert(TrieNode *root, int pre_xor) {
    TrieNode *temp = root;
    for (int i=INT_SIZE-1; i>=0; i--) {
        bool val = pre_xor & (1<<i);
        if (!temp->arr[val])
            temp->arr[val] = getNode();
        temp = temp->arr[val];
    }
    temp->value = pre_xor;
}

int query(TrieNode *root, int pre_xor) {
    TrieNode *temp = root;
    for (int i=INT_SIZE-1; i>=0; i--) {
        bool val = pre_xor & (1<<i); 
        if (temp->arr[1-val]) //first look for a prefix that has opposite bit
            temp = temp->arr[1-val];
        else if (temp->arr[val]) //else look for same bit
            temp = temp->arr[val];
    }
    return pre_xor^(temp->value);
}

int maxSubarrayXOR(int arr[], int n) {
    TrieNode *root = getNode();
    insert(root, 0);
    int result = INT_MIN, pre_xor =0;
    for (int i=0; i<n; i++) {
        pre_xor = pre_xor^arr[i];
        insert(root, pre_xor);
        result = max(result, query(root, pre_xor));
    }
    return result;
}

int main() {
    int arr[] = {8, 1, 2, 12};
    cout<<"Max Subarray XOR is " << maxSubarrayXOR(arr, sizeof(arr)/sizeof(arr[0]))<<endl;
    return 0;
}
