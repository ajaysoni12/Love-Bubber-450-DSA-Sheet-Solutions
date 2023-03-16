#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach) */
vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList)
{
    queue<vector<string>> q;
    q.push({beginWord});

    vector<string> usedWord;
    usedWord.push_back(beginWord);

    unordered_set<string> set(wordList.begin(), wordList.end());
    set.erase(beginWord);

    int level = 0;
    vector<vector<string>> ans;

    while (q.size())
    {
        vector<string> vec = q.front();
        q.pop();

        // level wise 
        if (vec.size() > level)
        {
            for (auto it : usedWord)
                set.erase(it);
            level++;
        }
        usedWord.clear();

        string word = vec.back();
        // word change done, in minimum steps 
        if (word == endWord)
        {
            // first sequence
            if (ans.size() == 0)
                ans.push_back(vec);
            else if (vec.size() == ans[0].size())
                ans.push_back(vec);
        }

        // word ladder 1
        for (int i = 0; i < word.size(); i++)
        {
            char org = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (set.count(word) > 0)
                {
                    vec.push_back(word);
                    q.push(vec);
                    usedWord.push_back(word);
                    vec.pop_back(); // for next word, we need to remove curr last word, 
                    // eg: bat pat or bat bot in same level 
                }
            }
            word[i] = org;
        }
    }
    return ans;
    /* TC- O(N*(logN * M * 26)) SC-O(N * M) where N = length of wordList and M = |wordListi| */
}