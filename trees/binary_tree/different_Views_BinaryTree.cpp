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

// ********* Top View *********
vector<int> topView(node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    map<int , int> topNode;
    queue<pair<node* , int> > q;

    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<node* , int> temp = q.front();
        q.pop();

        node* frontNode = temp.first;
        int hd = temp.second;

        if(topNode.find(hd) == topNode.end()){
            topNode[hd] = frontNode->data;
        }

        if(frontNode->left){
            q.push(make_pair(frontNode->left,hd-1));
        }

        if(frontNode->right){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }
    for(auto i: topNode){
        ans.push_back(i.second);
    }
    return ans;
}

// ********* Bottom View *********
vector<int> topView(node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    map<int , int> topNode;
    queue<pair<node* , int> > q;

    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<node* , int> temp = q.front();
        q.pop();

        node* frontNode = temp.first;
        int hd = temp.second;

        topNode[hd] = frontNode->data;

        if(frontNode->left){
            q.push(make_pair(frontNode->left,hd-1));
        }

        if(frontNode->right){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }
    for(auto i: topNode){
        ans.push_back(i.second);
    }
    return ans;
}

// ********* Left View *********
void solveleft(node* root, vector<int> &ans,int level){
    if(root == NULL){
        return;
    }

    if(level == ans.size()){
        ans.push_back(root->data);
    }

    solveleft(root->left, ans , level+1);
    solveleft(root->right, ans , level+1);
}

vector<int> leftView(node* root){
    vector<int> ans;
    solveleft(root, ans, 0);
    return ans;
}


// ********* Right View *********
void solveright(node* root, vector<int> &ans,int level){
    if(root == NULL){
        return;
    }

    if(level == ans.size()){
        ans.push_back(root->data);
    }

    solveright(root->right, ans , level+1);
    solveright(root->left, ans , level+1);
}

vector<int> leftView(node* root){
    vector<int> ans;
    solveright(root, ans, 0);
    return ans;
}



