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

class info {
    public:
    int mini;
    int maxi;
    bool isBST;
    int size;
};

info solve(node* root, int & ans ){
    if(root ->left == NULL && root ->right == NULL){
        return {root->data, root->data, true, 1};
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info curr;
    curr.mini = min(root->data, left.mini);
    curr.maxi = max(root->data, right.maxi);

    if(left.isBST && right.isBST && root->data > left.maxi && root->data < right.mini){
        curr.isBST = true;
    }else{
        curr.isBST = false; 
    }

    curr.size = left.size + right.size +1;

    if(curr.isBST){
        ans = max(ans, curr.size);
    }

    return curr;
}

int largetBST(node* root){
    int ans = 0;
    info temp = solve(root, ans);
    return ans;
}