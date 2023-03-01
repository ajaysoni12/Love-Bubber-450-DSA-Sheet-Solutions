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

/* method 1 (using two stack) */
vector<int> zigZagTraversal(Node *root)
{
    vector<int> res;

    // edge case
    if (root == nullptr)
        return res;

    stack<Node *> s1, s2;
    s1.push(root);

    while (!s1.empty())
    {
        // left-right
        while (!s1.empty())
        {
            res.push_back(s1.top()->data);
            if (s1.top()->left)
                s2.push(s1.top()->left);
            if (s1.top()->right)
                s2.push(s1.top()->right);
            s1.pop();
        }

        // right-left
        while (!s2.empty())
        {
            res.push_back(s2.top()->data);
            if (s2.top()->right)
                s1.push(s2.top()->right);
            if (s2.top()->left)
                s1.push(s2.top()->left);
            s2.pop();
        }
    }
    return res;
    /* TC-O(n) SC-O(n+n = 2n) */
}

vector<int> zigZagTraversal(Node *root)
{
    vector<int> res;
    if (root == nullptr)
        return res;

    deque<Node *> dq;
    dq.push_back(root);
    res.push_back(root->data);
    int level = 1;
    Node *temp;
    while (!dq.empty())
    {
        int n = dq.size();
        for (int i = 0; i < n; i++)
        {
            // find next level, where we traverse
            if (level % 2 == 0)
            {
                temp = dq.back();
                dq.pop_back();
            }
            else
            {
                temp = dq.front();
                dq.pop_front();
            }

            // push
            if (level % 2 != 0)
            {
                if (temp->right)
                {
                    dq.push_back(temp->right);
                    res.push_back(temp->right->data);
                }
                if (temp->left)
                {
                    dq.push_back(temp->left);
                    res.push_back(temp->left->data);
                }
            }

            else if (level % 2 == 0)
            {
                if (temp->left)
                {
                    dq.push_front(temp->left);
                    res.push_back(temp->left->data);
                }
                if (temp->right)
                {
                    dq.push_front(temp->right);
                    res.push_back(temp->right->data);
                }
            }
        }
        level++;
    }
    /* TC-O(n) SC-O(n) */
}