#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int dp[n + 1][n + 1] = {0};
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    cout << dp[n][k] << "\n";

    return 0;
}