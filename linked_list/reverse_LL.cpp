#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    //constructor
    node(int num){
        this->data = num;
        this->next = NULL;
    }

};

node* reverseLinkedList_itrative(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node* prev = NULL;
    node* curr = head;
    node* forward = NULL;

    while( curr != NULL){
        forward = curr ->next ;
        curr ->next = prev ;
        prev = curr;
        curr = forward;
    }
    return prev;
}

node* reverseLinkedList_recursive(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    node* newhead = reverseLinkedList_recursive(head->next);
    head->next ->next = head;
    head ->next = NULL;
    return newhead;
}

int main(){
    //we can call function for any linkedlist.
    return 0;
}