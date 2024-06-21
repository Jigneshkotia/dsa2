#include<iostream>
#include<queue>
#include<map>

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

vector<int> morris_inorder(node* root){
    vector<int> inorder;
    node* curr = root;
    while(curr != NULL){
        if(curr->left== NULL){
            inorder.push_back(curr->data);
            curr = curr->right;
        }else{
            node* temp = curr->left;
            while(temp ->right && temp->right != curr){
                temp= temp->right;
            }

            if(temp->right == NULL){
                temp->right = curr;
                curr = curr->left;
            }else{
                temp->right = NULL;
                inorder.push_back(curr->data);
                curr = curr->left;
            }
        }
    }
    return inorder;
}


vector<int> morris_inorder(node* root){
    vector<int> inorder;
    node* curr = root;
    while(curr != NULL){
        if(curr->left== NULL){
            inorder.push_back(curr->data);
            curr = curr->right;
        }else{
            node* temp = curr->left;
            while(temp ->right && temp->right != curr){
                temp= temp->right;
            }

            if(temp->right == NULL){
                temp->right = curr;
                inorder.push_back(curr->data);
                curr = curr->left;
            }else{
                temp->right = NULL;
                curr = curr->left;
            }
        }
    }
    return inorder;
}


void flatten_into_preorder(node* root){
    node* curr = root;
    while(curr != NULL){
        if(curr->left){
            node* temp = curr->left;
            while(temp->right){
                temp= temp->right;
            }
            temp->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr= curr->right;
    }
}