#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];

    bool containKey(char ch)
    {
        return links[ch - 'a'] != nullptr;
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
};

int countDistinctSubstring(string str)
{
    int cnt = 0;
    Node *root = new Node();

    for (int i = 0; i < str.length(); i++)
    {
        Node *node = root;
        for (int j = i; j < str.length(); j++)
        {
            if (!node->containKey(str[j]))
            {
                cnt++;
                node->put(str[j], new Node());
            }
            node = node->get(str[j]);
        }
    }
    return cnt + 1; // for empty string
}