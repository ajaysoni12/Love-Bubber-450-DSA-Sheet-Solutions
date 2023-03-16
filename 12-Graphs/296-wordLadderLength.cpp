#include <bits/stdc++.h>
using namespace std;

/* method 1 (using bfs) */
int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
{
    queue<pair<string, int>> q;
    q.push({startWord, 1});
    unordered_set<string> set(wordList.begin(), wordList.end());
    set.erase(startWord); // not do similar thing again

    while (!q.empty())
    {
        string word = q.front().first;
        int steps = q.front().second; // level
        q.pop();

        // if word match then it's is minimum steps because we do bfs(level wise traversal)
        if (word == targetWord)
            return steps;

        // N * word.length * 26 * log(n)
        for (int i = 0; i < word.size(); i++)
        {
            char orignal = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;

                // if exists in the set
                if (set.find(word) != set.end())
                {
                    set.erase(word);
                    q.push({word, steps + 1});
                }
            }
            // change to orignal word
            word[i] = orignal;
        }
    }
    return 0;
    /* TC-O(N * N(word length) * 26) SC-O(N + N*LOG(N) )*/
}