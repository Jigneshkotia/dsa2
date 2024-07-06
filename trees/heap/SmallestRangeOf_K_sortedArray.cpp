#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    int row;
    int col;

    node(int d, int r, int c){
        data = d;
        row = r;
        col = c;
    }
};

class compare{
    public:
    bool operator()(node* a , node* b){
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int> > &arr, int k , int n){
    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue< node*, vector<node*> , compare > pq;

    for( int i = 0; i< k ; i++){
        int element = arr[i][0];
        mini = min(mini,element);
        maxi = max(maxi, element);

        pq.push(new node(element, i, 0));
    }

    int start = mini, end = maxi;

    while(!pq.empty()){
        node* temp = pq.top();
        pq.pop();

        mini = temp->data;

        if(maxi - mini < end - start){
            start = mini;
            end = maxi;
        }

        if(temp->col +1 < n){
            maxi = max(maxi, arr[temp->row][temp->col +1 ]);
            pq.push(new node(arr[temp->row][temp->col + 1], temp->row, temp->col +1));
        }else{
            break;
        }
    }

    return (end-start +1);
}