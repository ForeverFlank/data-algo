#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int dp[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int x;
            cin >> x;
            if (i == 0 && j == 0)
            {
                dp[0][0] = x;
                continue;
            }
            if (j == 0)
            {
                dp[i][0] = dp[i - 1][0] + x;
                continue;
            }
            if (j == i)
            {
                dp[i][j] = dp[i - 1][j - 1] + x;
                continue;
            }
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + x;
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, dp[n - 1][i]);
    cout << res << endl;
    return 0;
}
