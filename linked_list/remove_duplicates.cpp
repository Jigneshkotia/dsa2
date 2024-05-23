#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int num)
    {
        this->data = num;
        this->next = NULL;
    }
};

node *deleteDuplicate_sorted(node *head)
{
    if (head == NULL)
    {
        return head;
    }
    node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->next->data != curr->data)
        {
            curr = curr->next;
        }
        else if (curr->next->data == curr->data)
        {
            curr->next = curr->next->next;
        }
    }
    return head;
}

/*
for deleting in unsorted we have three ways 
- first sort the linked list then apply above
- using O(n^2) T.C for every value we traverse whole list.
- using map.
*/