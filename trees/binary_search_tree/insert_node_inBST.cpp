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

node* insertIntoBST(node* root, int data){
    if(root == NULL){
        root = new node(data);
        return root;
    }

    if(data < root->data){
        root->left = insertIntoBST(root->left, data);
    }

    if(data > root->data){
        root->right = insertIntoBST(root->right, data);
    }
     
    return root;
}

void takeInput(node* root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root, data);
        cin>>data;
    }
}


int main(){
    node* root = NULL;
    cout<<'Enter the data to create BST'<<endl;
    takeInput(root);
    return 0;
}

// INORDER of a BST is sorted