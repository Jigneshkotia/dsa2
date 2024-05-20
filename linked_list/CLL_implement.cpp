#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int num){
        this->data = num;
        this->next = NULL;
    }
};

//as there is no sequence in CLL so we will add in front of "element".
void insertNode(node* &tail, int element , int num){
    //empty list
    if(tail == NULL){

        node* newnode = new node(num);
        tail = newnode;
        newnode -> next = newnode;

    }else{
        //assuming the element is present in the list.
        node* temp = new node(num);
        node* curr = tail;
        while(curr -> data != element){
            curr = curr->next;
        }
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}

void deleteNode(node* &tail, int value){
    if(tail == NULL){
        cout<< " the list is empty !!";
        return;
    }

    node* prev = tail;
    node* curr = prev -> next;

    while(curr -> data != value){
        prev = curr;
        curr = prev -> next;
    }

    prev -> next = curr -> next;

    //when there is only single node in the list.
    if(curr == prev){
        tail = NULL;
    }
    //when there is more then one node in the list.
    else if(curr == tail ){
        tail = prev;
    }

    curr -> next = NULL;
    delete curr;
}

void printList(node* tail){
    if(tail == NULL){
        cout<< "The list is empty !!"<< endl;
        return;
    }
    node* temp = tail;
    cout<< temp->data<< " ";
    while (temp -> next != tail){
        temp = temp -> next;
        cout<< temp -> data << " ";
    }
    cout<<endl;
    //do while loop can be useful here.
}

int main(){

    node* tail = NULL;

    insertNode(tail,3,10);
    insertNode(tail,10,15);
    insertNode(tail,10,12);
    insertNode(tail,15,17);
    printList(tail);
    deleteNode(tail,12);
    printList(tail);
    deleteNode(tail,15);
    printList(tail);
    deleteNode(tail,17);
    printList(tail);
    deleteNode(tail,10);
    printList(tail);

    return 0;
}