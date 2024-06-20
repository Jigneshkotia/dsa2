#include<iostream>
#include<queue>

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

node* buildTree(node* root){

    cout<<"entre the data :"<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<< "entre data for inserting in the left of "<<data<< endl;
    root->left = buildTree(root->left);
    cout<< "entre data for inserting in the right of "<<data<< endl;
    root->right = buildTree(root->right);

    return root;
}


void buildFromLevelOrder(node * &root){
    queue<node* > q;
    cout<<"Enter the Data for root :"<<endl;
    int data ;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter data for left node of :"<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter data for right node of :"<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata != -1){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}


void levelOrderTraversal(node* root){
    
    queue<node* > q;
    q.push(root);
    q.push(NULL);

    while( !q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }

}


void inOrderTraversal(node * root){
    if(root == NULL){
        return;
    }

    inOrderTraversal(root->left);
    cout<< root->data<<" ";
    inOrderTraversal(root->right);
}


void preOrderTraversal(node * root){
    if(root == NULL){
        return;
    }

    cout<< root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}


void postOrderTraversal(node * root){
    if(root == NULL){
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<< root->data<<" ";
}

