#include <iostream>
#include <map>
#include <queue>
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



int findPos(int element, vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

node *solve(int &preidx, int inorderStart, int inorderEnd, vector<int> preorder, vector<int> &inorder)
{
    if (preidx > preorder.size() || inorderStart > inorderEnd)
    {
        return NULL;
    }

    int element = preorder[preidx++];
    node *root = new node(element);
    int pos = findPos(element, inorder);

    root->left = solve(preidx, inorderStart, pos - 1, preorder, inorder);
    root->right = solve(preidx, pos + 1, inorderEnd, preorder, inorder);

    return root;
}

node *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int preOrderIdx = 0;
    int inorderEnd = inorder.size() - 1;
    int inorderStart = 0;
    node *root = solve(preOrderIdx, inorderStart, inorderEnd, preorder, inorder);
    return root;
}