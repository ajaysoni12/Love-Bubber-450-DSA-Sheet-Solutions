#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

/* method 1 (using queue) */
vector<int> reverseLevelOrder(Node *root)
{
    vector<int> res;
    
    // edge case
    if (root == nullptr)
        return res;

    queue<Node *> q;
    q.push(root); // insert first root node

    while (!q.empty())
    {
        // insert data
        res.push_back(q.front()->data);

        // process right child
        if (q.front()->right)
            q.push(q.front()->right);

        // process left child
        if (q.front()->left)
            q.push(q.front()->left);

        // after processing pop out front element of queue
        q.pop();
    }

    // if you use stack here, then we no need to reverse, just inserted stack data into vector
    reverse(res.begin(), res.end());
    return res;
    /* TC - O(2n) SC-O(n) */
}