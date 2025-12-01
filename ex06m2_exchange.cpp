#include <iostream>
#include <vector>
#include <climits>

using namespace std;

bool solve()
{
    int n;
    cin >> n;

    vector<vector<double>> adj(n, vector<double>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    vector<double> dist(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int u = 0; u < n; u++)
        {
            for (int v = 0; v < n; v++)
            {
                double w = adj[u][v];
                double d = dist[u] * w;
                if (d > dist[v])
                {
                    if (i == n - 1) return true;
                    dist[v] = d;
                }
            }
        }
    }

    return false;
}

int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
        cout << (solve() ? "YES" : "NO") << endl;
    return 0;
}