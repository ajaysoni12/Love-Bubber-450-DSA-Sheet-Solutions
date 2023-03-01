#include <bits/stdc++.h>
using namespace std;

/* method 1 (using queue and map) */
string FirstNonRepeating(string A)
{
    unordered_map<char, int> count;
    queue<int> q;
    string ans = "";

    for (int i = 0; i < A.length(); i++)
    {
        char ch = A[i];
        // Increase the count of characters
        count[ch]++;
        // Push in Queue
        q.push(ch);

        while (!q.empty())
        {
            if (count[q.front()] > 1)
            {
                // Repeating Character
                q.pop();
            }
            else
            {
                ans.push_back(q.front());
                break;
            }
        }

        if (q.empty())
            ans.push_back('#');
    }

    return ans;
}