#include<iostream>

using namespace std;

class node{
    
public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void solve(node* root, vector<node* > & arr){
    if( root == NULL){
        return;
    }

    solve(root->left, arr);
    arr.push_back(root);
    solve(root->right, arr);
}

node* flatten(node* root){
    vector<node* > preorder;
    solve(root, preorder);
    int len = preorder.size();

    for(int i = 0; i<len -1; i++){
        preorder[i] ->left = NULL;
        preorder[i] ->right = preorder[i+1];
    }
    preorder[len-1] ->left = NULL;
    preorder[len-1] ->right = NULL;

    return preorder[0];
}