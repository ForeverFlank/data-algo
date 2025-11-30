#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

const ll k = 100000007;

ll add(ll a, ll b)
{
    return (a + b) % k;
}

ll add(ll a, ll b, ll c)
{
    return add(add(a, b), c);
}

// 00 -> 00, 01, 02
// 01 -> 10, 11
// 02 -> 20, 22
// 10 -> 00, 01
// 11 -> 10, 11
// 20 -> 00, 02
// 22 -> 20, 22

int main()
{
    int n;
    cin >> n;
    vector<vector<ll>> dp(n + 1, vector<ll>(7, 0));
    for (ll i = 0; i < 3; i++)
        dp[1][i] = 1;
    for (ll i = 1; i < n; i++)
    {
        dp[i + 1][0] = add(dp[i][0], dp[i][3], dp[i][5]);
        dp[i + 1][1] = add(dp[i][0], dp[i][3]);
        dp[i + 1][2] = add(dp[i][0], dp[i][5]);
        dp[i + 1][3] = add(dp[i][1], dp[i][4]);
        dp[i + 1][4] = add(dp[i][1], dp[i][4]);
        dp[i + 1][5] = add(dp[i][2], dp[i][6]);
        dp[i + 1][6] = add(dp[i][2], dp[i][6]);
    }
    ll res = 0;
    for (ll i = 0; i < 7; i++)
        res = add(res, dp[n][i]);
    cout << res << endl;
    return 0;
}
