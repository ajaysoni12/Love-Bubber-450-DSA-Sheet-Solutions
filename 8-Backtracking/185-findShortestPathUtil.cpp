#include <bits/stdc++.h>
using namespace std;

int solve(int row, int col, set<pair<int, int>> &st, vector<vector<bool>> &vist, int i, int j, int cnt)
{
    if (i == row or i < 0 or j < 0 or j == col or st.count({i, j}) or vist[i][j])
        return INT_MAX;

    if (j == col - 1)
        return cnt;

    vist[i][j] = true;
    int l1 = solve(row, col, st, vist, i + 1, j, cnt + 1);
    int l2 = solve(row, col, st, vist, i - 1, j, cnt + 1);
    int l3 = solve(row, col, st, vist, i, j + 1, cnt + 1);
    int l4 = solve(row, col, st, vist, i, j - 1, cnt + 1);
    vist[i][j] = false;
    return min({l1, l2, l3, l4});
}

int main()
{
    int row, col;
    cin >> row >> col;

    vector<vector<int>> mat(row, vector<int>(col));
    vector<vector<bool>> vist(row, vector<bool>(col, false));

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> mat[i][j];

    set<pair<int, int>> st;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (mat[i][j] == 0)
            {
                pair<int, int> p{i, j};
                st.insert(p);

                if (i + 1 < row)
                {
                    pair<int, int> p{i + 1, j};
                    st.insert(p);
                }

                if (i - 1 >= 0)
                {
                    pair<int, int> p{i - 1, j};
                    st.insert(p);
                }

                if (j + 1 < col)
                {
                    pair<int, int> p(i, j + 1);
                    st.insert(p);
                }

                if (j - 1 >= 0)
                {
                    pair<int, int> p(i, j - 1);
                    st.insert(p);
                }
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < row; i++)
    {
        if (st.count({i, 0}) == 0)
        {
            int length = solve(row, col, st, vist, i, 0, 0);
            ans = min(ans, length);
        }
    }

    cout << ans << endl;
    return 0;
}