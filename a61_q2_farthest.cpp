#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>> pq;
    pq.push({0, 0});

    while (pq.size())
    {
        pair<int, int> top = pq.top();
        pq.pop();
        int w = top.first;
        int u = top.second;

        if (dist[u] < w) continue;

        for (int v = 0; v < n; v++)
        {
            int e = adj[u][v];
            if (e <= 0) continue;

            if (dist[u] + e < dist[v])
            {
                dist[v] = dist[u] + e;
                pq.emplace(dist[v], v);
            }
        }
    }


    int res = 0;
    for (int &d : dist)
    {
        if (d == INT_MAX)
        {
            cout << -1 << endl;
            return 0;
        }
        res = max(res, d);
    }
    cout << res << endl;

    return 0;
}
