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

void solve(vector<int> &inorder, node* root){
    if(root == NULL){
        return;
    }

    solve(inorder, root->left);
    inorder.push_back(root->data);
    solve(inorder, root->right);
}

node* inorderToBST(vector<int> &inorder , int left, int right){
    if(left > right){
        return NULL;
    }

    int mid = (left+right)/2;
    node* root = new node(inorder[mid]);
    root ->left = inorderToBST(inorder, left, mid-1);
    root->right = inorderToBST(inorder, mid +1, right);

    return root;
}

node* balancedBST(node* root){
    vector<int> inorder;
    solve(inorder, root);

    return inorderToBST(inorder, 0, inorder.size()-1);

}