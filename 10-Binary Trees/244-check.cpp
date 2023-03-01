#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

/* method 1 (using recurisve way) */
void solve(Node *root, int &ma, int &ans, int height)
{
    if (root == nullptr)
        return;

    // check leaf node
    if (!root->left and !root->right)
    {
        // first time update
        if (ma == -1)
            ma = height;

        // and other time check other leaf is equal to preverse leap height
        if (ma != height)
            ans = 0;
    }
    solve(root->left, ma, ans, height + 1);
    solve(root->right, ma, ans, height + 1);
}
bool check(Node *root)
{
    int ans = 1;
    int height = 0;
    int ma = -1;
    solve(root, ma, ans, height);
    return ans;
    /* TC-O(n) SC-O(h) */
}
