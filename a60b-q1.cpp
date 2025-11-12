#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int max_sum(vector<vector<int>> &m, int i, int j)
{
    int best_sum = m[i][j];
    int curr_sum = m[i][j];
    i++; j++;
    while (i < m.size() && j < m.size())
    {
        curr_sum = max(m[i][j], curr_sum + m[i][j]);
        best_sum = max(best_sum, curr_sum);
        i++; j++;
    }
    return best_sum;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> m[i][j];

    int res = INT_MIN;
    for (int i = 0; i < n; i++)
        res = max(res, max_sum(m, i, 0));
    for (int i = 1; i < n; i++)
        res = max(res, max_sum(m, 0, i));

    cout << res;

    return 0;
}