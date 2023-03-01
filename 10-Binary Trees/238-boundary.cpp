#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

/* method 1 (brute force approach) */
/* check is leaf node */
bool isLeaf(Node *root)
{
    if (!root->left and root->right)
        return true;
    else
        return false;
}

/* left boundary traversal excluding leaf nodes */
void addLeftBoundary(Node *root, vector<int> &res)
{
    Node *curr = root->left;
    while (curr)
    {
        // it's not leaf nodes
        if (!isLeaf(curr))
            res.push_back(curr->data);

        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

/* right boundary traversal - excluding leaf nodes */
void addRightBoundary(Node *root, vector<int> &res)
{
    Node *curr = root->right;
    vector<int> temp;
    while (curr)
    {
        if (!isLeaf(curr))
            temp.push_back(curr->data);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }

    // reverse order
    for (int i = temp.size() - 1; i >= 0; i--)
        res.push_back(temp[i]);
}

// apply preorder traversal or any traversal
void addLeaves(Node *root, vector<int> &res)
{
    if (isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
    if (root->left)
        addLeaves(root->left, res);
    if (root->right)
        addLeaves(root->right, res);
}

vector<int> boundary(Node *root)
{
    vector<int> res;
    if (!root)
        return res;

    // if root node not a leap node
    if (!isLeaf(root))
        res.push_back(root->data);

    // add left boundary
    addLeftBoundary(root, res);

    // add leaves
    addLeaves(root, res);

    // add right boundary
    addRightBoundary(root, res);
    return res;
    /* TC-O(n) SC-O(n) */
}