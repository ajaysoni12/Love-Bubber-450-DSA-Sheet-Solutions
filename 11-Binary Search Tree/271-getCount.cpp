#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

/* method 1 (using brute force approach) */
void inorder(Node *root, vector<int> &v)
{
    if (root == NULL)
        return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}
vector<int> printNearNodes(Node *root, int low, int high)
{
    vector<int> in;
    inorder(root, in);
    vector<int> v;
    for (int i = 0; i < in.size(); i++)
        if (in[i] >= low && in[i] <= high)
            v.push_back(in[i]);
    return v;
}
int getCount(Node *root, int l, int h)
{
    vector<int> ans;
    inorder(root, ans);
    vector<int> res = printNearNodes(root, l, h);
    return res.size();
    /* TC-O(n) SC-O(n) */
}

/* method 2 (efficent approach) */
void inorder(Node *root, int l, int h, int &cnt)
{
    if (root)
    {
        inorder(root->left, l, h, cnt);
        if (root->data >= l and root->data <= h)
            cnt++;
        inorder(root->right, l, h, cnt);
    }
}
int getCount(Node *root, int l, int h)
{
    if (!root)
        return 0;
    int cnt = 0;
    inorder(root, l, h, cnt);
    return cnt;
    /* TC-O(n) SC-O(h) */
}