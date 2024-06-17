#include<iostream>
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

// This is more efficient approach in which we are updating the height instead of call height function for all nodes. T.C : O(n) instead of O(n^2)
pair<bool, int> checkBalanced(node* root){
    if(root == NULL){
        pair<bool, int> p = make_pair(0,0);
        return p;
    }

    pair<bool,int> left = checkBalanced(root->left);
    pair<bool,int> right = checkBalanced(root->right);

    bool leftAns= left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second -right.second) <=1;

    pair<bool, int> ans;
    ans.second= max(left.second , right.second) +1;

    if(leftAns && rightAns && diff){
        ans.first = true;
    }else{
        ans.first = false;
    }
    return ans;
}

bool isBalanced(node* root){
    return checkBalanced(root).first;
}

int main(){
    // Use functions here.
    return 0;
}