#include <iostream>
#include<map>
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

node* solve(node* first, node* second){
    if(first ->next == NULL){
        first->next = second;
        return first;
    }
    node* curr1 = first;
    node* next1 = curr1->next;
    node* curr2 = second;
    node* next2 = curr2->next;

    while(next1 != NULL && curr2 != NULL){
        if(curr2 ->data >= curr1->data && curr2->data <= next1->data){
            next2 = curr2->next;
            curr1 ->next = curr2;
            curr2 ->next = next1;

            curr2 = next2;
            curr1 = curr1 ->next;
        }else{
            curr1 = curr1->next;
            next1 = next1->next;

            if(next1 == NULL){
                curr1 ->next = curr2 ;
                return first;
            }
        }
    }
    return first;
}

node* mergeTwoList(node* list1 , node* list2){
    if(list1 == NULL){
        return list2;
    }
    if(list2 == NULL){
        return list1;
    }
    if(list1->data >= list2->data){
        return solve(list2,list1);
    }else{
        return solve(list1,list2);
    }
}

int main(){

    return 0;
}