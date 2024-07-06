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

void bstInorder(node* &root, vector<int> &inorder){
    if(root == NULL){
        return;
    }

    bstInorder(root->left, inorder);
    inorder.push_back(root->data);
    bstInorder(root->right, inorder);
}

void BSTtoMinHeap(node* &root, vector<int> &inorder, int i){
    if(root == NULL){
        return;
    }

    root->data = inorder[i++];

    BSTtoMinHeap(root->left, inorder, i);
    BSTtoMinHeap(root->right, inorder, i);
}

int main(){
    //assunme any bst
    node* root;
    vector<int> inorder;
    bstInorder(root,inorder);
    BSTtoMinHeap(root,inorder,0);
    return 0;
}