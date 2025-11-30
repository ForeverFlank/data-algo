#include <iostream>
#include <vector>

using namespace std;

const int mod = 100000007;

int search(
    int y, int x, int prev, vector<vector<int>> &m,
    vector<vector<vector<int>>> &dp
)
{
    if (x == m[0].size() - 1) return 1;

    if (prev != -1 && dp[y][x][prev] != -1)
        return dp[y][x][prev];

    int res = 0;
    if (prev != 0 && y - 1 >= 0 && m[y - 1][x + 1] == 0)
        res += search(y - 1, x + 1, 0, m, dp);
    if (prev != 1 && m[y][x + 1] == 0)
        res += search(y + 0, x + 1, 1, m, dp);
    if (prev != 2 && y + 1 < m.size() && m[y + 1][x + 1] == 0)
        res += search(y + 1, x + 1, 2, m, dp);

    if (prev != -1)
        dp[y][x][prev] = res;

    return res;
}

int main()
{
    // TODO:
    // - space optimized dp
    // - mod 1e8+7
    int r, c;
    cin >> r >> c;
    vector<vector<int>> m(r, vector<int>(c));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < r; j++)
            cin >> m[i][j];
    vector<vector<vector<int>>> dp(
        r, vector<vector<int>>(c, vector<int>(3, -1))
    );
    int res = 0;
    for (int i = 0; i < r; i++)
    {
        if (m[i][0] == 1) continue;
        res += search(i, 0, -1, m, dp);
    }
    cout << res << endl;

    return 0;
}
