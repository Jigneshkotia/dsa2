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

pair<int, int> solve(node* root){
    if(root == NULL){
        pair<int, int> p = make_pair(0,0);
        return p;
    }

    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    pair<int,int> res ;
    
    res.first = root->data + left.second + right.second;
    res.second = max(left.first, left.second) + max(right.first , right.second);

    return res;
}

int maxSum_NonAdjecent(node* root){
    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
}