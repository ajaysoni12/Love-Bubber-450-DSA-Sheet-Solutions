#include <bits/stdc++.h>
using namespace std;

/* method 1 (using brute force approach) */
void solve(int i, int j, vector<vector<int>> &m, int n, vector<string> &ans, vector<vector<int>> &vis, string move)
{
    // reaching point
    if (i == n - 1 and j == n - 1)
    {
        ans.push_back(move);
        return;
    }

    // downward
    if (i + 1 < n and !vis[i + 1][j] and m[i + 1][j] == 1)
    {
        vis[i][j] = 1; // mark as a visited
        solve(i + 1, j, m, n, ans, vis, move + 'D');
        vis[i][j] = 0; // mark as a unvisited
    }

    // leftward
    if (j - 1 >= 0 and !vis[i][j - 1] and m[i][j - 1] == 1)
    {
        vis[i][j] = 1;
        solve(i, j - 1, m, n, ans, vis, move + 'L');
        vis[i][j] = 0;
    }

    // rightward
    if (j + 1 < n and !vis[i][j + 1] and m[i][j + 1] == 1)
    {
        vis[i][j] = 1;
        solve(i, j + 1, m, n, ans, vis, move + 'R');
        vis[i][j] = 0;
    }

    // upward
    if (i - 1 >= 0 and !vis[i - 1][j] and m[i - 1][j] == 1)
    {
        vis[i][j] = 1;
        solve(i - 1, j, m, n, ans, vis, move + 'U');
        vis[i][j] = 0;
    }
    /* TC-O(4^(m*n)) SC-O(m*n) */
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;                            // store all paths
    vector<vector<int>> vis(n, vector<int>(n, 0)); // intially mark as a false

    // if starting point is 1 then we go further direction
    if (m[0][0] == 1)
        solve(0, 0, m, n, ans, vis, "");
    return ans;
}

/* method 2 (optimized code) */
void solve(int i, int j, vector<vector<int>> &m, int n, vector<string> &ans, vector<vector<int>> &vis, string move, int di[], int dj[])
{
    // reaching point
    if (i == n - 1 and j == n - 1)
    {
        ans.push_back(move);
        return;
    }

    string dir = "DLRU";
    for (int ind = 0; ind < 4; ind++)
    {
        int nexti = i + di[ind];
        int nextj = j + di[ind];
        if (nexti >= 0 and nextj >= 0 and nexti < n and nextj < n and !vis[nexti][nextj] and m[nexti][nextj] == 1)
        {
            vis[i][j] = 1;
            solve(nexti, nextj, m, n, ans, vis, move, di, dj);
            vis[i][j] = 0;
        }
    }
    /* TC-O(4^(m*n)) SC-O(m*n) */
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;                            // store all paths
    vector<vector<int>> vis(n, vector<int>(n, 0)); // intially mark as a false

    int di[] = {1, 0, 0, -1};
    int dj[] = {0, -1, 1, 0};

    // if starting point is 1 then we go further direction
    if (m[0][0] == 1)
        solve(0, 0, m, n, ans, vis, "", di, dj);
    return ans;
}
