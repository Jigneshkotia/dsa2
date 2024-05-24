// we will add two numbers represented by two linked list.
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    // constructor
    node(int num)
    {
        this->data = num;
        this->next = NULL;
    }
};

node* reverse(node* head){
    if(head == NULL || head ->next == NULL){
        return head;
    }
    node* prev= NULL;
    node* curr = head;
    node* forward = NULL;
    while( curr != NULL){
        forward = curr->next;
        curr ->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

void insertAtTail(node* &head, node* &tail , int val){
    node* temp = new node(val);
    if(head == NULL){
        head = temp ;
        tail = temp;
        return;
    }
    tail ->next = temp;
    tail = temp;
}

node* add(node* &first,node* &second){
    int carry = 0;
    node* anshead = NULL;
    node* anstail = NULL;

    while( first != NULL || second != NULL || carry != 0){
        int val1 = 0;
        if(first != NULL){
            val1 = first->data;
        }
        
        int val2 = 0;
        if(second != NULL){
            val2 = second ->data;
        }

        int sum = carry + val1 + val2;
        int digit = sum % 10;

        insertAtTail(anshead, anstail, digit);

        carry = sum / 10;
        
        if(first != NULL){
            first = first->next;
        }
        if(second != NULL){
            second = second ->next;
        }
    }
    return anshead;
}

node* addTwoNumber(node* l1, node* l2){
    node* list1 = reverse(l1);
    node* list2 = reverse(l2);

    node* ans = add(list1 , list2);
    return reverse(ans);
}