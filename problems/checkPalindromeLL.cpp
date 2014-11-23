//check if a list is palindrome
#include<iostream>
#include<cstdlib>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node* getNode() { //alocate memory
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        cout<<"Memory Full"<<endl;
    }
    return temp;
}

void push_front(struct node **head, int key) { //add node in the front
    struct node* temp = getNode();
    temp->data = key;
    temp->next = (*head);
    (*head) = temp;
}

void deleteList(struct node **head) { //free all space used by the list
    struct node *curr = *head;
    struct node *next;
    while (curr != NULL) {
        next = curr->next;
        free(curr);
        curr = next;
    }
    *head = NULL;
}

void reverse(struct node **head) {
    struct node* prev   = NULL;
    struct node* curr = *head;
    struct node* next;
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

bool checkIdentical(struct node *a, struct node *b) {
    while(true) {
        if(a == NULL && b == NULL)    
            return true;
        else if(a == NULL && b != NULL) 
            return false;
        else if(a != NULL && b == NULL) 
            return false;
        else if(a->data != b->data)
            return false;
        a = a->next; //we reach each here if a and b are not NULL and their data is same
        b = b->next;
    }
}

bool checkPalindrome(struct node *node) {
    struct node *slow, *fast, *mid, *prev_slow, *sec_half;
    mid = NULL;
    slow = node;
    fast = node;
    prev_slow = node;
    bool palindrome = true;
    if(node && node->next) {
        while(fast && fast->next) { //get the middle of the list
            fast = fast->next->next;
            prev_slow = slow;
            slow = slow->next;
        }
        if(fast) { //if there are odd no of nodes
            mid = slow;
            slow = slow->next;
        }
        sec_half = slow;
        prev_slow->next = NULL;
        reverse(&sec_half); //reverse the second half of the list
        palindrome = checkIdentical(node, sec_half);
        reverse(&sec_half); //restore second half
        if(mid) {
            prev_slow->next = mid;
            mid->next = sec_half;
        } else {
            prev_slow->next = sec_half;
        }
    }
    return palindrome;
}       

int main() {
    struct node *a = NULL;
    push_front(&a, 1);
    push_front(&a, 2);
    push_front(&a, 3);   
    push_front(&a, 2);
    push_front(&a, 1);
    cout<<((checkPalindrome(a))?"List is Palindrome":"List is not Palindrome")<<endl;
    push_front(&a, 3);
    cout<<((checkPalindrome(a))?"List is Palindrome":"List is not Palindrome")<<endl;
    deleteList(&a);
    return 0;
}
