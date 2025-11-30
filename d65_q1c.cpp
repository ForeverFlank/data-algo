#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int> &prefix, int p, int x)
{
    auto it = lower_bound(prefix.begin(), prefix.end(), p);
    int t = it - prefix.begin();
    if (t <= x) return t;

    int total_at_x = prefix[x];
    it = lower_bound(prefix.begin(), prefix.end(), p + total_at_x);
    t = it - prefix.begin();
    return t;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m, start;
    cin >> n >> m >> start;

    vector<pair<int, int>> incomes(n + 1);
    incomes[0] = {0, start};

    for (int i = 0; i < n; i++)
    {
        int a, s;
        cin >> a >> s;
        incomes[i + 1] = {a, s};
    }

    sort(incomes.begin(), incomes.end());

    vector<int> prefix(100001);
    prefix[0] = start;
    for (int i = 1, j = 0; i < 100001; i++)
    {
        if (j < incomes.size() - 1 &&
            i == incomes[j + 1].first)
            j++;
        prefix[i] = prefix[i - 1] + incomes[j].second;
    }

    for (int i = 0; i < m; i++)
    {
        int p, x;
        cin >> p >> x;

        cout << solve(prefix, p, x) << " ";
    }
    cout << "\n";

    return 0;
}