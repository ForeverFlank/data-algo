#include <iostream>
#include <vector>

using namespace std;

const int mod = 1000003;

int count(
    int n,
    vector<int>& s,
    int total,
    int prev_idx,
    vector<vector<int>>& dp,
    vector<vector<bool>>& memo
)
{
    if (total > n) return 0;
    if (total == n) return 1;

    if (memo[total][prev_idx])
        return dp[total][prev_idx];

    int res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (i == prev_idx) continue;
        int curr = total;
        while (curr <= n)
        {
            curr += s[i];
            res = (res + count(n, s, curr, i, dp, memo) % mod) % mod;
        }
    }

    memo[total][prev_idx] = true;
    dp[total][prev_idx] = res;
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> s(k);
    for (auto &x : s)
        cin >> x;

    vector<vector<int>>  dp  (n, vector<int> (k + 1));
    vector<vector<bool>> memo(n, vector<bool>(k + 1));
    cout << count(n, s, 0, k, dp, memo) << endl;
    return 0;
}

