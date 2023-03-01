#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

/* method 1 (level order traversal) */
vector<int> leftView(Node *root)
{
    vector<int> res;

    // edge case
    if (root == nullptr)
        return res;

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        // level vise traversal
        int size = q.size();
        for (int i = 1; i <= size; i++)
        {
            Node *temp = q.front();
            q.pop();

            // if i = 1 means next level start
            if (i == 1)
                res.push_back(temp->data);

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return res;
    /* TC-O(n) SC-O(n) */
}

/* method 2 (using recursive way) */
void solve(Node *root, int level, vector<int> &res)
{
    if (root == nullptr)
        return;
    if (level == res.size())
        res.push_back(root->data);
    solve(root->left, level + 1, res);
    solve(root->right, level + 1, res);
}
vector<int> leftView(Node *root)
{
    vector<int> res;
    solve(root, 0, res);
    return res;
    /* TC-O(n) SC-O(h) */
}