#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

/* method 1 (using map and queue)*/
vector<int> topView(Node *root)
{
    vector<int> res;
    if (root == nullptr)
        return res;

    // create map and queue
    map<int, Node *> mp;
    queue<pair<Node *, int>> q;

    q.push({root, 0}); // insert first root node with 0 line
    while (!q.empty())
    {
        // if line not found then inserted
        if (mp.find(q.front().second) == mp.end())
            mp[q.front().second] = q.front().first;

        // if left part exist
        if (q.front().first->left)
            q.push({q.front().first->left, q.front().second - 1});

        // if right part exist
        if (q.front().first->right)
            q.push({q.front().first->right, q.front().second + 1});

        // root node processing completed
        q.pop();
    }

    // in map, line are sorted order
    for (auto it : mp)
        res.push_back(it.second->data);
    return res;
    /* TC-O(n*log(n)) SC-O(n+n) */
}

