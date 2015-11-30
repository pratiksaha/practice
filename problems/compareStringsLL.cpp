//to compare two strings represented as linked lists
#include<iostream>
#include<cstdlib>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node* getNode(char c) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        cout<<"Memory Full"<<endl;
    }
    temp->data = c;
    temp->next = NULL;
    return temp;
}

int compareStrings(struct node *list1, struct node *list2)  {
    while (list1 && list2 && list1->data == list2->data)  {         
        list1 = list1->next;
        list2 = list2->next;
    }
    if (list1 && list2) 
        return (list1->data > list2->data)? 1: -1;
    else if (list1 && !list2)
        return 1;
    else if (list2 && !list1)
        return -1;
    else
        return 0;
}

int main() {
    struct node *list1 = getNode('s');
    list1->next = getNode('a');
    list1->next->next = getNode('h');
    list1->next->next->next = getNode('a');
    list1->next->next->next->next = getNode('p');
    list1->next->next->next->next->next = getNode('a');
    struct node *list2 = getNode('s');
    list2->next = getNode('a');
    list2->next->next = getNode('h');
    list2->next->next->next = getNode('a');
    list2->next->next->next->next = getNode('p');
    list2->next->next->next->next->next = getNode('a');
    cout<<compareStrings(list1, list2)<<endl;
    return 0;
}
