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

void insertAtHead(node* &head , int d){
    // new node create
    node* temp = new node(d);
    temp -> next = head;
    head = temp;
};

void insertAtTail(node* &tail, int d){
    node * temp = new node(d);
    tail -> next = temp;
    tail = temp;
};

void insertAtIdx(node* &tail, node* &head, int d , int idx){
    if(idx == 0){
        insertAtHead(head,d);
        return;
    }

    node* temp = head;
    //new node create
    node * newnode = new node(d);
    for(int i = 0; i<idx-1;i++){
        temp = temp->next;
    }

    if(temp->next == NULL){
        insertAtTail(tail, d);
        return;
    }

    node * newtemp = temp-> next;
    temp-> next = newnode;
    newnode-> next = newtemp;
};

void printList(node * head){
    node * temp = head;
    while(temp != NULL){
        cout<< temp->data << " ";
        temp = temp -> next;
    }
    cout<< endl;
};

int main(){
    node* node1= new node(10);
    // cout << node1 -> data << endl;
    // cout << node1 -> next << endl;
    node * head = node1;
    node * tail = node1;

    insertAtTail(tail, 20);
    printList(head);

    insertAtHead(head, 5);
    printList(head);

    insertAtIdx(tail,head,7,1);
    printList(head);

    insertAtIdx(tail,head,4,0);
    printList(head);

    cout<<"head "<< head->data<<endl;
    cout<<"tail "<< tail->data<<endl;
}