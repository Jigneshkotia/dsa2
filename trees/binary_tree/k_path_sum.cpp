#include<iostream>
#include<map>
#include<queue>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data= d;
        this->left = NULL;
        this->right = NULL;
    }
};

void solve(node* root, int k, vector<int> path,int &count ){
    if(root == NULL){
        return;
    }

    path.push_back(root->data);

    solve(root->left, k , path, count);
    solve(root->right, k, path, count);

    int size = path.size();
    int sum = 0;
    for(int i = size-1; i>=0; i--){
        sum += path[i];
        if(sum == k){
            count++;
        }
    }
}

int sumk(node* root, int k){
    vector<int> path;
    int count = 0;
    solve(root, k, path, count);
    return count;
}