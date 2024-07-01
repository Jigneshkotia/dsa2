#include <iostream>
#include<vector>

using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void solve(node* root, vector<int> & arr){
    if( root == NULL){
        return;
    }

    solve(root->left, arr);
    arr.push_back(root->data);
    solve(root->right, arr);
}

bool findTarget(node* root, int k){
    vector<int> inorder;
    solve(root, inorder);
    int i = 0; 
    int j = inorder.size()-1;
    while(i<j){
        int sum = inorder[i] + inorder[j];
        if( sum < k){
            i++;
        }else if(sum > k){
            j--;
        }else{
            return true;
        }
    }
    return false;
}