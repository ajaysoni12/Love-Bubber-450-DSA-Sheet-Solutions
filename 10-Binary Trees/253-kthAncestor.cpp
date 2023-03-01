#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

/* method 1 (using storing path) */
bool findPath(Node *root, int node, vector<int> &path)
{
    if (root == NULL)
        return false;
    path.push_back(root->data);
    if (root->data == node)
        return true;
    if (findPath(root->left, node, path) || findPath(root->right, node, path))
        return true;
    path.pop_back();
    return false;
}
int kthAncestor(Node *root, int k, int node)
{
    vector<int> path;
    findPath(root, node, path);
    int size = path.size();
    if (k >= size)
        return -1;
    return path[size - 1 - k];
    /* TC-O(n) SC-O(n) */
}

/* method 2 (using recursive way) */
Node *solve(Node *root, int &k, int node, int &data)
{
    if (root == NULL)
        return NULL;
    if (root->data == node)
        return root;
    Node *left = solve(root->left, k, node, data);
    Node *right = solve(root->right, k, node, data);
    if (left == NULL && right == NULL)
        return NULL;
    k--;
    if (k == 0)
        data = root->data;
    return root;
}

int kthAncestor(Node *root, int k, int node)
{
    if (root == NULL)
        return -1;
    int data = -1;
    Node *ans = solve(root, k, node, data);
    return data;
    /* TC-O(n) SC-O(h) */
}