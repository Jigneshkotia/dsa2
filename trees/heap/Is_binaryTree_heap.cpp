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

int count(node* root){
    if( root == NULL){
        return 0;
    }
     
    return ( 1 + count(root->left) + count(root->right));
}

bool isCBT(node* root, int i, int &n){
    if(root == NULL){
        return true;
    }

    if(i>=n){
        false;
    }else{
        bool left = isCBT(root->left, 2*i +1, n);
        bool right = isCBT(root->right, 2*i +2, n);
        return(left && right);
    }
}

bool isMaxOrder(node* root){
    if(root->left == NULL && root->right == NULL){
        return true;
    }

    if(root->right == NULL){
        return(root->data > root->left->data);
    }else{
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        return(
            left && right && (root->data > root->left ->data && root->data > root->right->data)
        );
    }
}

bool isHeap(node* root){
    int index = 0;
    int totalNodes = count(root);
    if( isCBT(root,index ,totalNodes) && isMaxOrder(root)){
        return true;
    }else{
        return false;   
    }
}



int main(){
    return 0;
}