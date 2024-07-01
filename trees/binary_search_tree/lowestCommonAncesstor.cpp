#include <iostream>

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

// ******** Recursive Approach ***********
node *lowestCommonAncestor_recursive(node *root, node *a, node *b)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data < a->data && root->data < b->data)
    {
        return lowestCommonAncestor_recursive(root->right, a, b);
    }

    if (root->data > a->data && root->data > b->data)
    {
        return lowestCommonAncestor_recursive(root->left, a, b);
    }

    return root;
}

// ******** Recursive Approach ***********
node *lowestCommonAncestor_itrative(node *root, node *a, node *b)
{
    while (root != NULL)
    {
        if (root->data < a->data && root->data < b->data)
        {
            root = root->right;
        }else if (root->data > a->data && root->data > b->data)
        {
            root = root->left;
        }else{
            return root;
        }

    }
}