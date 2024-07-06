#include<iostream>
#include<queue>

using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int num){
        this->data= num;
        this->next = NULL;
    }
};

class compare{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

node* mergeKLists(vector<node*>& lists) {
        priority_queue<node*, vector<node*> , compare > pq;
        int n = lists.size();
        for(int i = 0; i< n; i++){
            if(lists[i] != NULL){
                pq.push(lists[i]);
            }
        }
        node* ans = NULL;
        if(!pq.empty()){
            ans = pq.top();
            node* temp = pq.top();
            pq.pop();
            if(temp->next){
                pq.push(temp->next);
            }
        }
        node* extra= ans;

        while(!pq.empty()){
            extra->next = pq.top();
            node* temp = pq.top();
            pq.pop();
            if(temp->next){
                pq.push(temp->next);
            }
            extra = extra->next;
        }
        return ans;
    }

int main(){
    return 0;
}