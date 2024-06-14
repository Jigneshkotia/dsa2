#include<iostream>
using namespace std;

/*
we can use inbuild stack using stl.
#include<stack>
stack<int> s;

and we get some functionalities like:
1) s.push(num);
2) s.pop();
3) s.size();
4) s.empty();
etc.
*/

//___________________________________________//
// stack implementaion using array : 
class stack_via_array {
    int * arr;
    int top;
    int size;

public:
    stack_via_array(int size){
        this->size= size;
        arr = new int[size];
        top = -1;
    }

    void push(int num){
        if(top == size-1){
            cout<< "The stack is full"<< endl;
        }else{
            top ++;
            arr[top]= num;
        }
    }

    void pop(){
        if(isEmpty()){
            cout<<"The stack is empty "<< endl;
        }else{
            top--;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }else{
            return false;
        }
    }

    int peek(){
        if(isEmpty()){
            cout<< "the stack is empty "<<endl;
            return -1;
        }else{
            return arr[top];
        }
    }
};

//___________________________________________//
// stack implementaion using array : 
class node {
public:
    int data;
    node* next;
   
    node(int n)
    {
        this->data = n;
        this->next = NULL;
    }
};

class stack_via_linkedlist{
    node * top;

public:
    stack_via_linkedlist(){
        top = NULL;
    }

    void push(int num){
        node * temp = new node(num);
        if(isEmpty()){
            top = temp;
            return;
        }
        
        temp ->next = top;
        top = temp;
    }

    void pop(){
        if(isEmpty()){
            cout<< "The stack is empty "<< endl;
        }else{
            node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    bool isEmpty(){
        if(top == NULL){
            return true;
        }else{
            return false;
        }
    }

    int peek(){
        if(isEmpty()){
            cout<<"The stack is empty "<<endl;
            return -1;
        }else{
            return top->data;
        }
    }
};


int main(){
    stack_via_linkedlist s;
    s.push(3);
    s.push(2);
    s.push(10);
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    s.pop();
    return 0;
}

