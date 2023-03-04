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

/* method 1 (brute force approach) */
void inorder(Node *root, vector<int> &v)
{
    if (root)
    {
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
}
vector<int> merge(Node *root1, Node *root2)
{
    vector<int> res;
    inorder(root1, res);
    inorder(root1, res);
    sort(res.begin(), res.end());
    return res;
    /* TC-O(n*log(n)) SC-O(n+m) */
}

/* method 2 (efficeint approach) */
void inorder(Node *root, vector<int> &v)
{
    if (root)
    {
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
}
vector<int> merge(Node *root1, Node *root2)
{
    vector<int> v1, v2;
    inorder(root1, v1);
    inorder(root2, v2);
    vector<int> res;
    // merge both of the array
    int left = 0, right = 0;
    while (left < v1.size() and right < v2.size())
    {
        if (v1[left] <= v2[right])
            res.push_back(v1[left++]);
        else
            res.push_back(v2[right++]);
    }
    while (left < v1.size())
        res.push_back(v1[left++]);
    while (right < v2.size())
        res.push_back(v2[right++]);
    return res;
    /* TC-O(n+m+(n+m)) SC-O(n+m)*/
}