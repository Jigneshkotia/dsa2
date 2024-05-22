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

node* reverse(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node* prev= NULL;
    node* curr = head;
    node* forward = NULL;
    while( curr != NULL){
        forward = curr ->next;
        curr->next = NULL;
        prev = curr;
        curr = forward;
    }    
    return prev;
}

bool isPalindrome(node* head){
    node* fast = head->next;
    node* slow = head;
    while(fast!= NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    node* temp2= slow->next;
    node* temp1 = head;
    temp2=reverse(temp2);

    while(temp2 != NULL){
        if( temp1 ->data != temp2->data){
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

int main(){
    //we can check our function here.
    return 0;
}