#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *right, *left;
};

/* method 1 (using brute force approach) */
void PreorderStore(Node *root, map<int, int> &mp)
{
    if (root == nullptr)
        return;
    mp[root->data]++;
    PreorderStore(root->left, mp);
    PreorderStore(root->right, mp);
}
void leafNodes(Node *root, vector<Node *> &vec)
{
    if (root == nullptr)
        return;
    if (root->left == nullptr && root->right == nullptr)
    {
        vec.push_back(root);
        return;
    }
    leafNodes(root->left, vec);
    leafNodes(root->right, vec);
}
bool isDeadEnd(Node *root)
{
    map<int, int> mp;
    vector<Node *> vec;
    PreorderStore(root, mp);
    leafNodes(root, vec);
    for (auto ele : vec)
        if ((mp[ele->data + 1] == 1 || ele->data + 1 <= 0) && (mp[ele->data - 1] == 1 || ele->data - 1 <= 0))
            return 1;
    return 0;
    /* TC-O(n) SC-O(n) */
}

/* method 2 (using efficent approach) */
bool solve(Node *root, int min, int max)
{
    if (!root)
        return false;
    if (min == max)
        return true;
    return solve(root->left, min, root->data - 1) or solve(root->right, root->data + 1, max);
}
bool isDeadEnd(Node *root)
{
    return solve(root, 1, INT_MAX);
    /* TC-O(n) SC-O(H) */
}