#include<iostream>
using namespace std;
/*
******** STL uses ********
#include <queue>

making a doubly ended queue
deque<int> q;
and you will get a lot of operations :

1) q.push_back(num);
2) q.push_front(num);
3) q.pop_back();
4) q.pop_front();
5) q.size();
6) q.empty();

and many more😈
*/

class MyCircularDeque {
    int * arr;
    int start;
    int end;
    int size;
public:
    MyCircularDeque(int k) {
        this->size= k;
        arr = new int[k];
        start = -1;
        end = -1;
    }
    
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }
        else if(isEmpty()){
            start = end = 0;
        }else {
            start = (start-1+size)%size;
        }
        arr[start] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        if(start == -1){
            start = end = 0;
            arr[start]=value;
        }else{
            end = (end+1)%size;
            arr[end]=value;
        }
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){
        return false;
       }
       if(start == end){
        arr[start]=-1;
        start = end = -1;
       }else{
        arr[start]= -1;
        start = (start+1)%size;
       }
       return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
        return false;
       }
       arr[end]= -1;
       if(start == end){
        start = end = -1;
       }else if(end == 0) {
        end = size-1;
       }else{
        end --;
       }
       return true;
    }
    
    int getFront() {
        if(start == -1){
            return -1;
        }else{
            return arr[start];
        }
    }
    
    int getRear() {
        if(start == -1){
            return -1;
        }else{
            return arr[end];
        }
    }
    
    bool isEmpty() {
        return start == -1;
    }
    
    bool isFull() {
        return (end+1)%size == start;
    }
};
