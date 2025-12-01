#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define pii pair<int, int>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> s(k), c(n);
    for (int &si : s)
        cin >> si;
    for (int &ci : c)
        cin >> ci;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int &si : s)
    {
        dist[si] = c[si];
        pq.push({c[si], si});
    }

    while (pq.size())
    {
        pii top = pq.top(); pq.pop();
        int d = top.first, u = top.second;

        if (dist[u] < d) continue;

        for (int &v : adj[u])
        {
            int w = c[v];

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    int res = 0;
    for (int &d : dist) res = max(res, d);
    cout << res << endl;

    return 0;
}