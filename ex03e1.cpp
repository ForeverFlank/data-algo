#include <iostream>
#include <vector>

using namespace std;

int lcs(string &s1, string &s2, int p, int q, vector<vector<int>> &dp)
{
    if (p == s1.size() || q == s2.size())
        return 0;

    if (dp[p][q] != -1)
        return dp[p][q];

    if (s1[p] == s2[q])
    {
        int n = lcs(s1, s2, p + 1, q + 1, dp) + 1;
        dp[p][q] = n;
        return n;
    }

    int n = max(lcs(s1, s2, p + 1, q, dp), lcs(s1, s2, p, q + 1, dp));
    dp[p][q] = n;
    return n;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));

    cout << lcs(s1, s2, 0, 0, dp) << endl;

    return 0;
}