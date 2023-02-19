#include <bits/stdc++.h>
using namespace std;

/* method 1 (using backtracking) */
// check adjancent node have same color
bool isSafe(int node, int color[], bool graph[101][101], int n, int col)
{
    for (int k = 0; k < n; k++)
        if (k != node && graph[k][node] == 1 && color[k] == col)
            return false;
    return true;
}
// recursion
bool solve(int node, int color[], bool graph[101][101], int m, int n)
{
    // if it's reach last node means we can color nodes successfully
    if (node == n)
        return true;

    // try all possible color
    for (int i = 1; i <= m; i++)
    {
        if (isSafe(node, color, graph, n, i))
        {
            color[node] = i; // mark color
            // if it's return true then, return true no need to check for other nodes
            if (solve(node + 1, color, graph, m, n) == true)
                return true;
            color[node] = 0; // now time to backtrack then remove color
        }
    }
    return false; // anyone color not fit there
}
bool graphColoring(bool graph[101][101], int m, int n)
{
    int color[n] = {0};
    if (solve(0, color, graph, m, n))
        return true;
    return false;
    /* TC-O(n^m) SC-O(n + n) */
}