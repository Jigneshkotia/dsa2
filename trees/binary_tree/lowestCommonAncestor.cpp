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

node* lca(node* root, node* a, node* b){
    if(root == NULL){
        return NULL;
    }
    if(root == a || root == b){
        return root;
    }

    node* left = lca(root->left, a, b);
    node* right = lca(root->right, a, b);

    if(left != NULL && right == NULL){
        return left;
    }else if(right != NULL && left == NULL){
        return right;
    }else if(left != NULL && right != NULL){
        return root;
    }else{
        return NULL;
    }
}