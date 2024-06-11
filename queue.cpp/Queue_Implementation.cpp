#include<iostream>
#include<stack>
using namespace std;

/*
******** STL uses ********
#include <queue>

making a queue
queue<int> q;
and you will get a lot of operations :

1) q.push(num);
2) q.pop();
3) q.size();
4) q.empty();

and many more😈
*/

/*___________________________________________________*/
//IMPLEMENTATION USING ARRAY:   
class queue_via_array{
    int *arr;
    int start;
    int end;
    int size;

public:
    queue_via_array(int size){
        arr = new int[size];
        start = 0;
        end = 0;
    }

    void enqueue(int data){
        if(end == size){
            cout<< "queue is full" << endl;
        }else{
            arr[end]= data;
            end ++;
        }
    }

    int dequeue(){
        if (start == end){
            return -1;
        }else{
            int num = arr[start];
            arr[start]= -1;
         start ++;
            if (start == end){
             start = 0;
                end = 0;
            }
            return num;
        }
    }

    int front(){
        if (start == end){
            return -1;
        }else{
            return arr[start];
        }
    }

    bool empty(){
        if (start == end){
            return true;
        }else{
            return false;
        }
    }

};

/*___________________________________________________*/
//IMPLEMENTATION USING LINKED-LIST:
class qnode{

public:

    int data;
    qnode *next;
    qnode(int num){
        this->data = num;
        this->next = NULL;
    }
};

class queue_via_linkedlist{
    qnode * start;
    qnode * end;

    queue_via_linkedlist(){
        start = NULL;
        end = NULL;
    }

    void enqueue(int data){
        qnode * temp = new qnode(data);
        if(start == NULL){
            start = end = temp;
            return;
        }

        end->next = temp;
        end = temp;
    }

    int dequeue(){
        if(start == NULL){
            return -1;
        }
        qnode* temp = start;
        start = start->next;

        if(start == NULL){
            end = NULL;
        }
        int ans = temp ->data;
        delete(temp);
        return ans;
    }
};

/*___________________________________________________*/
//IMPLEMENTATION USING STACK:
class queue_via_stack{
    stack<int> s;
    int start;
    int end;
public:
    queue_via_stack(){ 
        start = -1;
        end = -1;
    }
    
    void enqueue(int x) {
        if(start == -1){
            s.push(x);
            start = end = 0;
        }else{
            s.push(x);
            end++;
        }
    }
    
    int dequeue() {
        if(start == -1){
            return 0;
        }else{
            stack<int> newstack;
            while(!s.empty()){
                int temp = s.top();
                s.pop();
                newstack.push(temp);
            }
            int ans = newstack.top();
            newstack.pop();
            while(!newstack.empty()){
                int temp = newstack.top();
                newstack.pop();
                s.push(temp);
            }
            if(s.empty()){
                start = end = -1;
                return ans;
            }else{
                end--;
                return ans;
            }
        }
    }
    
    int front() {
        if(start == -1){
            return -1;
        }else{
            stack<int> newstack;
            while(!s.empty()){
                int temp = s.top();
                s.pop();
                newstack.push(temp);
            }
            int ans = newstack.top();
            while(!newstack.empty()){
                int temp = newstack.top();
                newstack.pop();
                s.push(temp);
            }
            return ans;
        }
    }
    
    bool empty() {
        if(start == -1){
            return true;
        }else{
            return false;
        }
    }
};