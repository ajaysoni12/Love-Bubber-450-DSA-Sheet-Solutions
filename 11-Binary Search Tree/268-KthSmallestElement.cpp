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

/* method 1 (using extra space) */
void inorder(Node *root, vector<int> &v)
{
    if (root == NULL)
        return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}
int kthLargest(Node *root, int k)
{
    vector<int> v;
    inorder(root, v);
    return v[k];
    /* TC-O(n) SC-O(h) */
}

/* method 2 (using recursive way) */
void solve(Node *root, int &cnt, int k, int &ans)
{
    if (root)
    {
        solve(root->left, cnt, k, ans);
        cnt++;
        if (cnt == k)
        {
            ans = root->data;
            return;
        }
        solve(root->right, cnt, k, ans);
    }
}
int kthSmallest(Node *root, int K)
{
    if (!root)
        return -1;
    int cnt = 0;
    int ans = -1;
    solve(root, cnt, K, ans);
    return ans;
    /* TC-O(n) SC-O(h) */
}