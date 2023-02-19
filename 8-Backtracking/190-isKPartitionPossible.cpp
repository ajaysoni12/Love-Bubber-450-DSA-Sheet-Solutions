#include <bits/stdc++.h>
using namespace std;

void solve(int a[], int n, int k, int curr_sum, int cnt, vector<int> &visited, int sum, bool &ans)
{
    if (cnt == k - 1)
    {
        ans = true;
        return;
    }

    if (curr_sum > sum)
        return;

    if (curr_sum == sum)
    {
        return solve(a, n, k, 0, cnt + 1, visited, sum, ans);
        if (ans == true)
            return;
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            solve(a, n, k, curr_sum + a[i], cnt, visited, sum, ans);
            if (ans == true)
                return;
            visited[i] = false;
        }
    }
    return;
}

bool isKPartitionPossible(int a[], int n, int k)
{
    // first case
    if (k > n)
        return false;

    if (k == 1)
        return true;

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];

    if (sum % k != 0)
        return false;

    vector<int> visited(n, false);
    bool ans = false;
    solve(a, n, k, 0, 0, visited, sum / k, ans);
    return ans;
    /* TC-O(n*2^n) SC-O(2^n) */
}