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

node *solve(int &postIdx, int inorderStart, int inorderEnd, vector<int> postorder, vector<int> &inorder)
{
    if (postIdx < 0 || inorderStart > inorderEnd)
    {
        return NULL;
    }

    int element = postorder[postIdx--];
    node *root = new node(element);
    int pos = findPos(element, inorder);

    root->right = solve(postIdx, pos + 1, inorderEnd, postorder, inorder);
    root->left = solve(postIdx, inorderStart, pos - 1, postorder, inorder);
    
    return root;
}

node *buildTree(vector<int> &postorder, vector<int> &inorder)
{
    int postOrderIdx = inorder.size()-1;
    int inorderEnd = inorder.size() - 1;
    int inorderStart = 0;
    node *root = solve(postOrderIdx, inorderStart, inorderEnd, postorder, inorder);
    return root;
}