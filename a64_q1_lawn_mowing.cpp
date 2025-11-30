#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int prefix[n], dp[n];
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + arr[i];
    for (int i = 0; i < n; i++)
        dp[i] = prefix[i] + (i + 1) * k;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        int cost = b + (a == 0 ? 0 : dp[a - 1]);
        auto it = upper_bound(dp + a, dp + n, cost) - 1;
        auto idx = it - dp;
        int res = idx < 0
            ? 0
            : prefix[idx] - (a == 0 ? 0 : prefix[a - 1]);
        cout << res << "\n";
    }

    return 0;
}
