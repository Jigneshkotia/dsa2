#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int num){
        this->data= num;
        this->next = NULL;
    }
};

node* findMid(node* head){
    node* fast= head;
    node* slow= head;

    while(fast != NULL || fast->next != NULL){
        fast = fast->next->next;
        slow = slow ->next;
    }
    return slow;
}

int main(){
    //we can use fuction for any linkedlist here.
    return 0;
}