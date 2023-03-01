#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

/* method 1 (using map and queue data structure)*/
vector<int> bottomView(Node *root)
{
    vector<int> res;
    // edge cae
    if (root == nullptr)
        return res;

    // create map and queue
    map<int, Node *> mp;
    queue<pair<Node *, int>> q;

    // insert root
    q.push({root, 0});
    while (!q.empty())
    {
        // we need to update
        mp[q.front().second] = q.front().first;
        if (q.front().first->left)
            q.push({q.front().first->left, q.front().second - 1});
        if (q.front().first->right)
            q.push({q.front().first->right, q.front().second + 1});
        q.pop();
    }

    for (auto it : mp)
        res.push_back(it.second->data);
    return res;
    /* TC-O(n*log(n)) SC-O(n) */
}