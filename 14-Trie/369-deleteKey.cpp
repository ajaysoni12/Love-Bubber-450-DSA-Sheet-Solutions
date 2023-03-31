#include <bits/stdc++.h>
using namespace std;

#define ALPHABET_SIZE 26
struct trie_node
{
    int value; // non zero if leaf
    trie_node *children[ALPHABET_SIZE];
};

void deleteKey(trie_node *root, char key[])
{
    int length = strlen(key);
    for (int i = 0; i < length; i++)
    {
        char ch = key[i];
        if (root->children[ch - 'a'])
            root->children[ch = 'a']->value = 0;
        root = root->children[ch - 'a'];
    }
}