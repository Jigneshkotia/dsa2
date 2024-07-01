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

// Recursive approach T.C : O(log(n)) , S.C : O(H)
bool searchBST_recursive(node* root, int val){
    if(root == NULL){
        return false;
    }

    if(root ->data == val){
        return true;
    }

    if(root ->data > val){
        return searchBST_recursive(root->right, val);
    }
    if(root ->data < val){
        return searchBST_recursive(root->left, val);
    }
}

// Itrative approach T.C : O(log(n)) , S.C : O(1)
bool searchBST_itrative(node* root, int val){
    node* temp = root;
    while(temp != NULL){
        if(temp ->data = val){
            return true;
        }
        if(temp->data> val){
            temp = temp->right;
        }
        if(temp->data< val){
            temp = temp->left;
        }
    }
    return false;
}


node* minval(node* root){
    node* temp = root;
    if(temp == NULL){
        return NULL;
    }

    while(temp->left){
        temp = temp->left;
    }
    return temp;
}

node* maxval(node* root){
    node* temp = root;
    if(temp == NULL){
        return NULL;
    }

    while(temp->right){
        temp = temp->right;
    }
    return temp;
}


node* deletefromBST(node* root , int num){
    if(root == NULL){
        return root;
    }

    if(root->data == num){
        //no child
        if(root -> left == NULL && root ->right == NULL){
            delete root;
            return NULL;
        }
        
        //single child:
          //left child
        if(root->left != NULL && root->right == NULL){
            node* temp = root -> left;
            delete root;
            return temp;
        }
          //right child
        if(root->left == NULL && root->right != NULL){
            node* temp = root -> right;
            delete root;
            return temp;
        }

        //double child
        if(root ->left != NULL && root ->right !=NULL){
            int mini = minval(root->right) ->data;
            root->data = mini;
            root->right = deletefromBST(root->right, mini);
            return root;
        }
    }else if(root->data >num){
        root->left = deletefromBST(root->left,num);
        return root;
    }else{
        root->right = deletefromBST(root->right, num);
        return root;
    }
}