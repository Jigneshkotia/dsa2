#include <iostream>
#include <queue>
#include <map>

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

node *createParentMapping(node *root, int target, map<node *, node *> &nodeToParent)
{
    node *res = NULL;

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *front = q.front();
        q.pop();

        if (front->data == target)
        {
            res = front;
        }

        if (front->left)
        {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }

        if (front->right)
        {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}

int burnTree(node *targetNode, map<node *, node *> nodetoParent)
{
    map<node *, bool> visited;
    queue<node *> q;

    int ans = 0;

    q.push(targetNode);
    visited[targetNode] = true;

    while (!q.empty())
    {
        bool flag = false;
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            node *front = q.front();
            q.pop();

            if (front->left && !visited[front->left])
            {
                flag = true;
                visited[front->left] = true;
                q.push(front->left);
            }

            if (front->right && !visited[front->right])
            {
                flag = true;
                visited[front->right] = true;
                q.push(front->right);
            }

            if (nodetoParent[front] && !visited[nodetoParent[front]])
            {
                flag = true;
                visited[nodetoParent[front]] = true;
                q.push(nodetoParent[front]);
            }
        }
        if (flag)
        {
            ans++;
        }
    }
    return ans;
}

int minTimeToBurn(node *root, int target)
{
    map<node *, node *> nodeToParent;
    node *targetNode = createParentMapping(root, target, nodeToParent);

    int ans = burnTree(targetNode, nodeToParent);

    return ans;
}