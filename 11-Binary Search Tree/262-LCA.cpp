#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

/* method 1 (using brute force approach - binary tree)*/
Node *LCA(Node *root, int n1, int n2)
{
    if (root == nullptr or root->data == n1 or root->data == n2)
        return root;
    Node *left = LCA(root->left, n1, n2);
    Node *right = LCA(root->right, n1, n2);
    if (left == nullptr)
        return right;
    else if (right == nullptr)
        return left;
    else
        return root;
    /* TC-O(n) SC-O(h) */
}

/* method 2 (using bst lca) */
Node *LCA(Node *root, int n1, int n2)
{
    if (root == nullptr)
        return nullptr;

    // both data left side
    if (n1 < root->data and n2 < root->data)
        return LCA(root->left, n1, n2);

    // otherwise right side
    if (n1 > root->data and n2 > root->data)
        return LCA(root->right, n1, n2);

    // it's lca of n1, n2
    return root;
    /* TC-O(H) SC-O(H) */
}