#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

unordered_map<Node *, int> dp;
int getMaxSum(Node *root)
{
    if (root == nullptr)
        return 0;

    // already exist
    if (dp[root])
        return dp[root];

    // include
    int inc = root->data;
    if (root->left)
    {
        inc += getMaxSum(root->left->left);
        inc += getMaxSum(root->left->right);
    }
    if (root->right)
    {
        inc += getMaxSum(root->right->left);
        inc += getMaxSum(root->right->right);
    }

    // exclude
    int exc = getMaxSum(root->left) + getMaxSum(root->right);
    dp[root] = max(inc, exc);
    return dp[root];
    /* TC-O(n) SC-O(n) */
}