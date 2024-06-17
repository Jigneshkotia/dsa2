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

bool isIdentical(node* p, node* q){
    if(p == NULL && q == NULL){
        return true;
    }

    if(p == NULL && q != NULL){
        return false;
    }

    if(q == NULL && p != NULL){
        return false;
    }

    bool left = isIdentical(p->left , q->left);
    bool right = isIdentical(p->right, q->right);
    bool value = p->data == q->data;

    if(left && right && value){
        return true;
    }else{
        return false;
    }
}

int main(){
    // use the functions here.
    return 0;
}