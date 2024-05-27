#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* random;

    node(int num){
        this->data = num;
        this->next = NULL;
    }
};
void insertAtTail(node* head , node* tail , int val){
    node* temp = new node(val);
    if( head == NULL){
        head = temp;
        tail = temp;
        return;
    }

    tail ->next = new node(val);
    tail = tail ->next;
}


//here is the function to clone a linkedlist with a addition random pointer.
node* cloneRandom(node* head){
    node* clonehead = NULL;
    node* clonetail = NULL;

    node* temp = head;
    while(temp != NULL){
        insertAtTail(clonehead, clonetail, temp->data);
        temp = temp ->next;
    }

    node* originalNode = head;
    node* cloneNode = clonehead;
    while(originalNode != NULL && cloneNode != NULL){
        node* next = originalNode ->next;
        originalNode ->next = cloneNode;
        originalNode = next;

        next = cloneNode ->next;
        cloneNode ->next = originalNode;
        cloneNode= next;
    }

    temp = head;
    while( temp != NULL){
        if(temp ->next != NULL){
            if(temp ->random != NULL){
                temp ->next ->random = temp ->random ->next;
            }else{
                temp -> next ->random = NULL;
            }  
        temp = temp ->next ->next;
        }
    }

    originalNode = head;
    cloneNode = clonehead;

    while( originalNode != NULL && cloneNode != NULL){
        originalNode ->next = cloneNode ->next;
        originalNode = originalNode ->next;
        if(originalNode != NULL){
            cloneNode->next = originalNode ->next;
        }
        cloneNode = cloneNode ->next ;
    }
    return clonehead;
}