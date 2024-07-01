#include<iostream>
#include<vector>

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


// ******* Approach first ********
bool solve_1(node* root, int min, int max){
    if(root == NULL){
        return true;
    }

    if(root->data > min && root->data < max){
        bool left = solve_1(root->left, min , root->data);
        bool right = solve_1(root->right, root->data, max);
        return (left && right);
    }else{
        return false;
    }
}

bool validateBST_1(node* root){
    return solve_1(root,INT_MIN, INT_MAX);
}


// ******* Approach Second ********
void solve_2(node* root, vector<int> &arr){
    if(root== NULL){
        return;
    }

    solve_2(root->left, arr);
    arr.push_back(root->data);
    solve_2(root->right, arr);
}

bool validateBST_2(node* root){
    vector<int> arr ;
    solve_2(root, arr);
    int size = arr.size();
    long int k = LONG_MIN;
    for( int i = 0; i<size ; i++){
        if(k< arr[i]){
            k = arr[i];
        }else{
            return false;
        }
    }
    return true;
}