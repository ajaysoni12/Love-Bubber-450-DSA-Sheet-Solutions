#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

/* method 1 (using map) */
Node *buildTree(int in[], int inStart, int inEnd, int pre[], int preStart, int preEnd, unordered_map<int, int> mp)
{
    if (inStart > inEnd or preStart > preEnd)
        return nullptr;
    Node *root = new Node(pre[preStart]);

    int inRoot = mp[pre[preStart]];
    int numsLeft = inRoot - inStart;
    root->left = buildTree(in, inStart, inRoot - 1, pre, preStart + 1, preStart + numsLeft, mp);
    root->right = buildTree(in, inRoot + 1, inEnd, pre, preStart + numsLeft + 1, preEnd, mp);
    return root;
}
Node *buildTree(int in[], int pre[], int n)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[in[i]] = i;
    return buildTree(in, 0, n - 1, pre, 0, n - 1, mp);
}

/* method 2 (without using map) */
Node *helper(int in[], int pre[], int &index, int s, int e, int size)
{
    if (index >= size || s > e)
    {
        return NULL;
    }
    int ele = pre[index++];
    Node *root = new Node(ele);
    int pos = 0;

    for (int i = s; i <= e; i++)
    {
        if (in[i] == ele)
        {
            pos = i;
            break;
        }
    }

    root->left = helper(in, pre, index, s, pos - 1, size);
    root->right = helper(in, pre, index, pos + 1, e, size);

    return root;
}

Node *buildTree(int in[], int pre[], int n)
{
    int index = 0;
    return helper(in, pre, index, 0, n - 1, n);
}