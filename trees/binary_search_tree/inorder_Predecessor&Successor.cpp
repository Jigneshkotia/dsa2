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


pair<int,int> predecessorSuccessor(node* root, int key){
    node* temp = root;
    int pred = -1;
    int succ = -1;

    while(temp -> data != key){
        if(temp->data > key){
            succ = temp ->data;
            temp = temp->left;
        }else{
            pred = temp->data;
            temp = temp->right;
        }
    }

    node* left = temp->left;
    while(left != NULL){
        pred = left->data;
        left = left ->right;
    }


    node* right = temp->right;
    while(right != NULL){
        succ = right->data;
        right = right -> right;
    }

    pair<int, int> ans = make_pair(pred, succ);
    return ans;

}