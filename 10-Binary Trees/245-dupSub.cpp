#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};

/* method 1 (using hashing) */
map<string, int> m;
string solve(Node *root)
{
    if (root == NULL)
        return "$ ";

    string s = "";
    if (root->left == NULL && root->right == NULL)
    {
        s = to_string(root->data);
        return s;
    }

    s = s + "@" + to_string(root->data);
    s = s + "@" + solve(root->left);
    s = s + "@" + solve(root->right);

    m[s]++;
    return s;
}

/*This function returns true if the tree contains
a duplicate subtree of size 2 or more else returns false*/
int dupSub(Node *root)
{
    solve(root);
    for (auto it : m)
        if (it.second >= 2)
            return 1;

    return 0;
}