#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[2] = {nullptr};
    bool containKey(int bit) { return links[bit] != nullptr; }
    Node *get(int bit) { return links[bit]; }
    void put(int bit, Node *node) { links[bit] = node; }
};

class Trie
{
private:
    Node *root;

public:
    Trie() { root = new Node(); }
    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->containKey(bit))
                node->put(bit, new Node());
            node = node->get(bit);
        }
    }
    int getMax(int num)
    {
        Node *node = root;
        int mxNum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1; // right shift
            if (node->containKey(1))
            {
                mxNum = mxNum | (1 << i);
                node = node->get(1);
            }
            else
                node = node->get(bit);
        }
        return mxNum;
    }
};

int maxAND(int arr[], int n)
{
    Trie trie;
    for (int i = 0; i < n; i++)
        trie.insert(arr[i]);

    int maxi = 0;

    for (int j = 0; j < n; j++)
        maxi = max(maxi, trie.getMax(arr[j]));
    return maxi;
}

// 5 4 3 7 
// 0101 0100 0011 0111 
// 0101 
// 5 - 0101