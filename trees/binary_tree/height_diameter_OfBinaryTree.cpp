#include<iostream>
using namespace std;

// we will be considering nodes not the edges !!

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

int heightOfTree(node* node) {
    if(node == NULL){
        return 0;  
    }

    int left = heightOfTree(node -> left);
    int right = heightOfTree(node -> right);

    return max(left,right) + 1;
}

int diameter(node* root){
    if(root == NULL){
        return 0;
    }

    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = heightOfTree(root->left) + 1 + heightOfTree(root->right);

    return max(op1, max(op2,op3));
}

pair<int,int> solveDiameterFast(node* node){
    if(node == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = solveDiameterFast(node->left);
    pair<int,int> right = solveDiameterFast(node->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + 1 + right.second;

    pair<int, int> ans;
    ans.first = max(op1,max(op2,op3));
    ans.second = max(left.second, right.second) +1;

    return ans;
}

int diameterFast(node* root){
    return solveDiameterFast(root).first;
}

int main(){
    // use the functions here.
    return 0;
}