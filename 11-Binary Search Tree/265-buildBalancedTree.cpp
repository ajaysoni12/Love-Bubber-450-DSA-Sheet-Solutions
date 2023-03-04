#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

/* method 1 (using middle point node)*/
void inorder(Node *root, vector<Node *> &v)
{
    if (root)
    {
        inorder(root->left, v);
        v.push_back(root);
        inorder(root->right, v);
    }
}
Node *solve(vector<Node *> &v, int start, int end)
{
    if (start > end)
        return nullptr;
    int mid = (start + end) / 2;
    Node *root = v[mid];
    root->left = solve(v, start, mid - 1);
    root->right = solve(v, mid + 1, end);
    return root;
}
Node *buildBalancedTree(Node *root)
{
    if (!root)
        return nullptr;
    vector<Node *> v;
    inorder(root, v);
    int start = 0;
    int end = v.size() - 1;
    return solve(v, start, end);
    /* TC-O(n) SC-O(n) */
}