#include <bits/stdc++.h>
using namespace std;

/* method 1 (using sorting) */
int findLongestConseqSubseq(int arr[], int N)
{
    int ans = 0;
    int count = 1;

    sort(arr, arr + N);

    for (int i = 1; i < N; i++)
    {
        if (arr[i] == arr[i - 1]) // for removing duplicate
            continue;
        if (arr[i] == arr[i - 1] + 1)
            count++;
        else
        {
            ans = max(ans, count);
            count = 1;
        }
    }
    return count;

    /*  Time Complexity: O(n * log(n))
        Auxiliary Space: O(1) */
}

/* method 2 (using hashing) */
int findLongestConseqSubseq(int arr[], int n)
{
    unordered_set<int> hashSet;
    int longestStreak = 0;

    for (int i = 0; i < n; i++)
        hashSet.insert(arr[i]);

    for (int i = 0; i < n; i++)
    {
        if (hashSet.find(arr[i] - 1) == hashSet.end()) // it is intial state
        {
            int currNum = arr[i];
            int currStreak = 1; // currNum also streak

            /* it take overall n element tarversal */
            while (hashSet.find(currNum + 1) != hashSet.end())
            {
                currNum += 1;
                currStreak += 1;
            }

            longestStreak = max(longestStreak, currStreak);
        }
    }
    return longestStreak;

    /*  Time Complexity: O(n) + O(n) + O(N) = O(3n)
        Auxiliary Space: O(n) */
}
