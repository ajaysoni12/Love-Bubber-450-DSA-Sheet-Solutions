#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

string bfs(Node *root, unordered_map<string, int> &mp, vector<Node *> &duplicates)
{
    if (root == NULL)
        return "#";
    string left = bfs(root->left, mp, duplicates);
    string right = bfs(root->right, mp, duplicates);

    string s = left + "," + right + "," + to_string(root->data);

    if (mp[s] == 1) // means we have found the duplicate
        duplicates.push_back(root);

    mp[s]++;
    return s;
}
vector<Node *> printAllDups(Node *root)
{
    unordered_map<string, int> mp;
    vector<Node *> res;
    bfs(root, mp, res);
    return res;
}