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

int height(Node *root, bool &ok)
{
    if (root == nullptr)
        return 0;
    int leftH = height(root->left, ok);
    int rightH = height(root->right, ok);
    if (abs(leftH - rightH) > 1)
        ok = false;
    return max(leftH, rightH) + 1;
}
bool isBalanced(Node *root)
{
    if (root == nullptr)
        return true;
    bool ok = false;
    height(root, ok);
    return ok;
    /* TC-O(n) SC-O(n) */
}