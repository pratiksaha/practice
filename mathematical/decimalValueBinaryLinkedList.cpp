//to find decimal value of binary linked list
#include<bits/stdc++.h>
using namespace std;

struct node {
    bool data;
    struct node* next;
};

int decimalValueBinaryLinkedList(struct node *head) {
    int  res = 0;
    while (head != NULL) {
        res = (res  << 1) + head->data;
        head = head->next;
    }
    return res;
}
 
struct node * getNode(bool data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
 
int main() {
    struct node* head = getNode(1);
    head->next = getNode(0);
    head->next->next = getNode(1);
    head->next->next->next = getNode(1);
    cout<<"Decimal value is "<<decimalValueBinaryLinkedList(head)<<endl;
    return 0;
}
