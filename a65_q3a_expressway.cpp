#include <iostream>
#include <vector>
#include <queue>
#define pii pair<int, int>

using namespace std;

int main()
{
    int n, c;
    cin >> n >> c;
    vector<vector<pii>> adj(n);
    adj[0].push_back({1, c});
    adj[1].push_back({0, c});
    for (int u = 3; u <= n; u++)
    {
        int k;
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            int v, w;
            cin >> v >> w;
            adj[u - 1].push_back({v - 1, w});
            adj[v - 1].push_back({u - 1, w});
        }
    }


    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> res(n);

    for (int t = 2; t < n; t++)
    {
        vector<int> dist(n, 1e8);
        dist[0] = 0;
        pq.push({0, 0});

        while (pq.size())
        {
            pii top = pq.top(); pq.pop();
            int d = top.first, u = top.second;

            if (dist[u] < d) continue;

            for (pii &e : adj[u])
            {
                int v = e.first, w = e.second;
                if (v > t) continue;
                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }
        cout << dist[1] << " ";
    }
    cout << endl;

    return 0;
}