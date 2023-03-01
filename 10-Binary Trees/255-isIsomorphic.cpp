#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

bool isIsomorphic(Node *root1, Node *root2)
{
    if (!root1 && !root2)
        return true;

    if (!root1 || !root2)
        return false;

    if (root1->data == root2->data)
        return (
            (isIsomorphic(root1->left, root2->right) &&
             isIsomorphic(root1->right, root2->left)) ||
            (isIsomorphic(root1->left, root2->left) &&
             isIsomorphic(root1->right, root2->right)));
    else
        return false;
}