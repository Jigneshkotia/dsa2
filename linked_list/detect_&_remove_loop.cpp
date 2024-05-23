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

// less efficient approach T.C = O(n), S.C = O(n)
bool detectLoop(node* head){
    if( head == NULL){
        return false;
    }
    map<node* , bool> visited;
    node* temp = head;
    while(temp != NULL){
        if(visited[temp]==true){
            return true;
        }
        visited[temp]=true;
        temp = temp->next;
    }
    return false;
}

/* 
In the below code we are returning the 
intersection of slow and fast pointer but if we 
just want to detect the cycle then we just 
change NULL by false and return slow by return true 
*/
// efficient approach T.C = O(n), S.C = O(1).
node *floydDetectLoop(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            return slow;
        }
    }
    return NULL;
}


node *getStartingNode(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    node *intersection = floydDetectLoop(head);
    node* slow = head;
    while(slow != intersection){
        slow = slow ->next;
        intersection = intersection ->next;
    }
    return slow;
}


//removing the loop
void removeLoop(node* head){
    if( head == NULL){
        return;
    }
    node* startOfLoop= getStartingNode(head);
    node* temp = startOfLoop;
    while( temp -> next != startOfLoop){
        temp = temp -> next;
    }
    temp ->next = NULL;
}



int main(){
    //we can check our function here.
    return 0;
}