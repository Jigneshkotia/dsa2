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

node *reverseLinkedList_itrative(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *prev = NULL;
    node *curr = head;
    node *forward = NULL;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

node *reverseLinkedList_recursive(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *newhead = reverseLinkedList_recursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}

node *reverseKGroup(node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    int len = 0;
    node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    if (len < k)
    {
        return head;
    }

    node *prev = NULL;
    node *curr = head;
    node *forward = NULL;
    for (int i = 0; i < k; i++)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    if (curr != NULL)
    {
        head->next = reverseKGroup(curr, k);
    }
    return prev;
}

int main()
{
    // we can call function for any linkedlist.
    return 0;
}