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


// ********   ZIG-ZAG Traversal  **********
vector<vector<int> > zig_zag_Traversal(node* root){
    vector<vector<int> > ans;
    if(root == NULL){
        return ans;
    }

    queue<node*> q;
    q.push(root);
    bool leftright = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> temp(size);

        for( int i = 0 ; i<size; i++){
            node* front = q.front();
            q.pop();

            int idx = leftright ? i:size-i-1;
            temp[idx] = front -> data;

            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
        leftright = !leftright;
        ans.push_back(temp);
    }
    return ans;
}


// ********   Boundary Traversal  **********
void traverseLeft(node* root, vector<int> &ans){
    if(root == NULL || (root->left == NULL && root->right == NULL) ){
        return ;
    }

    ans.push_back(root->data);
    
    if(root->left){
        traverseLeft(root->left,ans);
    }else{
        traverseLeft(root->right,ans);
    }
};

void traverseLeaf(node* root, vector<int> &ans){
    if(root == NULL){
        return;
    }

    traverseLeaf(root->left,ans);
    traverseLeaf(root->right, ans);

    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
    }
};

void traverseRight(node* root, vector<int> &ans){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }

    if(root->right){
        traverseRight(root->right,ans);
    }else{
        traverseRight(root->left, ans);
    }

    ans.push_back(root->data);
};


vector<int> boundaryTraversal(node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    ans.push_back(root->data);

    traverseLeft(root->left, ans);

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);

    traverseRight(root->right,ans);

    return ans;
}


// ********   Vertical Traversal  **********
vector<int> verticalOrder(node* root){
    map<int,map<int, vector<int> > > nodes;
    queue<pair<node*, pair<int , int> > > q;
    vector<int> ans;

    if(root == NULL){
        return ans;
    }

    q.push(make_pair(root, make_pair(0,0)));

    while(!q.empty()){
        pair<node* , pair<int, int> > temp = q.front();
        q.pop();

        node* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode->data);

        if(frontNode->left){
            q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
        }

        if(frontNode->right){
            q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
        }
    }

    for(auto i: nodes){
        for(auto j : i.second){
            for(auto k : j.second){
                ans.push_back(k);
            }
        }
    }
    return ans;
}

