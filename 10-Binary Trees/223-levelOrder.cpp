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

/* method 1 (using queue) */
vector<int> levelOrder(Node *node)
{
    vector<int> res;

    // edge case
    if (node == nullptr)
        return res;

    // queue data strcture is sutaiable, we insert left, and right child then process it
    queue<Node *> q;

    // insert first node
    q.push(node);

    while (!q.empty())
    {
        res.push_back(q.front()->data);

        // insert left node
        if (q.front()->left)
            q.push(q.front()->left);

        // insert right node
        if (q.front()->right)
            q.push(q.front()->right);

        // after inserting child, then pop
        q.pop();
    }
    return res;
    /* TC-O(n) SC-O(n) */
}