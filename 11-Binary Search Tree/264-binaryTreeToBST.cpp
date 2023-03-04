#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

/* method 1 (using sorting) */
void inorder(Node *root, vector<int> &v)
{
    if (root)
    {
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
}
void solve(Node *root, vector<int> &path, int &i)
{
    if (root)
    {
        solve(root->left, path, i);
        root->data = path[i++];
        solve(root->right, path, i);
    }
}
Node *binaryTreeToBST(Node *root)
{
    if (root == nullptr)
        return nullptr;
    vector<int> v;
    inorder(root, v);         // store all nodes value
    sort(v.begin(), v.end()); // then sort
    int i = 0;
    solve(root, v, i); // then swap data in bst order
    return root;
    /* TC-O(n + nlog(n) + n) SC-O(n) */
}