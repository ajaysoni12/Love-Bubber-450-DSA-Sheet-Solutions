#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

/* method 1 (brute force approach) */
void solve(Node *root, vector<Node *> &path)
{
    // store all inorder traversal nodes
    if (root)
    {
        solve(root->left, path);
        path.push_back(root);
        solve(root->right, path);
    }
}
void populateNext(Node *root)
{
    if (root == nullptr)
        return;
    vector<Node *> path;
    solve(root, path);

    // next pointer point inorder successor, for last node we no need to do
    for (int i = 0; i < path.size() - 1; i++)
        path[i]->next = path[i + 1];
    /* TC-O(n) SC-O(n) */
}

/* method 2 (using recursive apprpach) */
void solve(Node *root, Node *&prev)
{
    if (root == nullptr)
        return;
    solve(root->left, prev);

    // if prev null, means not have inorder successor
    if (prev == nullptr)
        prev = root;

    // means have inorder successor
    else
    {
        prev->next = root;
        prev = root; // update inorder successor
    }
    solve(root->right, prev);
}
void populateNext(Node *root)
{
    if (root == nullptr)
        return;
    Node *prev = nullptr;
    solve(root, prev);
    /* TC-O(n) SC-O(h) */
}