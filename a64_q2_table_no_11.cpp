#include <iostream>

using namespace std;

int main()
{
    const int k = 100000007;
    int n;
    cin >> n;
    int dp[n + 1][3];
    for (int i = 0; i < 3; i++)
        dp[1][i] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i + 1][0] = ((dp[i][0] + dp[i][1]) % k + dp[i][2]) % k;
        dp[i + 1][1] = (dp[i][0] + dp[i][1]) % k;
        dp[i + 1][2] = (dp[i][0] + dp[i][2]) % k;
    }
    cout << ((dp[n][0] + dp[n][1]) % k + dp[n][2]) % k << endl;
    return 0;
}
