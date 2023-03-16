#include <bits/stdc++.h>
using namespace std;

/* method 1 (using dfs) */
void dfs(int sr, int sc, vector<vector<int>> &image, int newColor, int color, vector<vector<bool>> &vis)
{
    // image size
    int n = image.size();
    int m = image[0].size();

    // fill new color
    image[sr][sc] = newColor;
    vis[sr][sc] = true;

    // all four direction
    int dx[] = {-1, 0, +1, 0};
    int dy[] = {0, +1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int nrow = sr + dx[i];
        int ncol = sc + dy[i];

        // if it is safe and not viisted and same color we have
        if (nrow >= 0 and ncol >= 0 and nrow < n and ncol < m and image[nrow][ncol] == color and !vis[nrow][ncol])
            dfs(nrow, ncol, image, newColor, color, vis);
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int n = image.size();
    int m = image[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    dfs(sr, sc, image, newColor, image[sr][sc], vis);
    return image;
    /* TC-O(n*m*4) SC-O(n*m(vis) + n*m(recursion call))*/
}