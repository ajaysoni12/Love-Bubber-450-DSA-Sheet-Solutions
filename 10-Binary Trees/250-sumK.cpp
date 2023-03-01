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

/* method 1 (using vector) */
void solve(Node *root, vector<int> &path, int k, int &totalPath)
{
    // if we get null, then return
    if (!root)
        return;

    // store all paths data
    path.push_back(root->data);

    // go left
    solve(root->left, path, k, totalPath);

    // go right
    solve(root->right, path, k, totalPath);

    int sum = 0;
    for (int i = path.size() - 1; i >= 0; i--)
    {
        sum += path[i];

        // sum equal then increment totalPath and print
        if (sum == k)
        {
            totalPath++;
            for (int j = i; j < path.size(); j++)
                cout << path[j] << " ";
        }
    }
    path.pop_back();
}
int sumK(Node *root, int k)
{
    vector<int> path;
    int totalPath = 0;
    solve(root, path, k, totalPath);
    return totalPath;
    /* TC-O(n) SC-O(h) */
}