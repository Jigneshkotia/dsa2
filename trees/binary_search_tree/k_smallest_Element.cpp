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


void solve(node * root, int &k , int &ans){
    if(root == NULL){
        return;
    }

    solve(root->left, k , ans);
    k--;
    if(k == 0){
        ans = root->data;
    }
    solve(root->right, k , ans);
}

int k_smallest(node* root, int k){
    int ans;
    solve(root , k , ans);
    return ans;
}