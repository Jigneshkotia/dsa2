#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int num){
        this->data = num;
        this->next = NULL;
        this->prev = NULL;
    }
};

void printList(node* head){
    node* temp = head;
    while(temp!= NULL){
        cout<< temp-> data<< " ";
        temp=temp->next;
    }
    cout<< endl;
}

int getLength(node* head){
    int len = 0;
    node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(node* &tail,node* &head, int num){
    node* temp = new node(num);
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }

    temp-> next = head;
    head-> prev = temp;
    head = temp;
}

void insertAtTail(node* &tail,node* head, int num){
    node* temp = new node(num);
    if(tail == NULL){
        tail = temp;
        head = temp;
        return;
    }
    tail-> next = temp ;
    temp-> prev = tail;
    tail = temp;
}

void insertAtIdx(node* &tail,node* &head, int num,int idx){
    if(idx == 0){
        insertAtHead(tail,head,num);
        return;
    }
    node* temp = head;
    for(int i =0 ; i<idx-1 ; i++){
        temp = temp->next;
    }

    if(temp->next == NULL){
        insertAtTail(tail,head,num);
        return;
    }
    node* nodetoinsert= new node(num);
    nodetoinsert->next = temp->next;
    temp->next->prev = nodetoinsert;
    temp->next = nodetoinsert;
    nodetoinsert->prev = temp;

}

void deleteNode(node* &tail, node* &head, int idx){
    if( idx == 0){

        node* temp = head;
        head->next->prev = NULL;
        head = temp->next;
        temp -> next = NULL;
        delete temp;

    }else if(idx == getLength(head)-1){

        node* back = NULL;
        node* curr = head;
        for(int i = 0 ; i< idx; i++){
            back = curr;
            curr = curr -> next;
        }
        back -> next = curr -> next;
        curr -> next = NULL;
        curr -> prev = NULL;
        delete curr;
        tail = back;

    }else{

        node* back = NULL;
        node* curr = head;
        for(int i = 0 ; i< idx; i++){
            back = curr;
            curr = curr -> next;
        }
        back -> next = curr -> next;
        curr -> next -> prev = back;
        curr -> next = NULL;
        curr -> prev = NULL;

    }
}

int main(){
    // node* mylist = new node(10);
    node* head = NULL;
    node* tail = NULL;

    insertAtHead(tail,head , 5);
    insertAtTail(tail,head, 15);
    insertAtIdx(tail, head,6,2);

    printList(head);

    deleteNode(tail,head, 2);
    printList(head);

    cout<< "lenght of the list : "<< getLength(head)<<endl;
    cout<< "Tail : "<<tail->data<<endl;
    cout<< "head : "<<head->data<<endl;

    return 0;
}