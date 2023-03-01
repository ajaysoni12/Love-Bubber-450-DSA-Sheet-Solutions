#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

/* method 1 (using queue data structure) */
vector<int> diagonal(Node *root)
{
    vector<int> res;
    if (root == nullptr)
        return res;

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        do
        {
            res.push_back(temp->data);
            if (temp->left)
                q.push(temp->left);
            temp = temp->right;
        } while (temp);
    }

    return res;
    /* TC-O(n) SC-O(n) */
}