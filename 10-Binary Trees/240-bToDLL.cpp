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

/* method 1 (using inorder traversal) */
void solve(Node *root, Node *&head, Node *&tail)
{
    // edge case
    if (root == nullptr)
        return;

    // process left subtree
    solve(root->left, head, tail);
    if (head == nullptr)
    {
        Node *n = new Node(root->data);
        head = tail = n;
    }
    else
    {
        Node *n = new Node(root->data);
        tail->right = n;
        tail = n;
    }
    // process right subtree
    solve(root->right, head, tail);
}

Node *bToDLL(Node *root)
{
    Node *head = nullptr, *tail = nullptr;
    solve(root, head, tail);
    return head;
    /* TC-O(n) SC-O(h) */
}