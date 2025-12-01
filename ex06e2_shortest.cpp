#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    const int inf = 1e8;
    int nv, ne, s;
    cin >> nv >> ne >> s;
    vector<vector<pair<int, int>>> adj(nv);
    for (int i = 0; i < ne; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<int> dist(nv, 1e8);
    dist[s] = 0;
    for (int i = 0; i < nv; i++)
    {
        for (int u = 0; u < nv; u++)
        {
            for (pair<int, int> &e : adj[u])
            {
                int v = e.first;
                int w = e.second;
                int d = dist[u] + w;
                if (d < dist[v])
                {
                    if (i == nv - 1)
                    {
                        cout << -1 << endl;
                        return 0;
                    }
                    dist[v] = d;
                }
            }
        }
    }

    for (int &d : dist)
        cout << d << " ";
    cout << endl;

    return 0;
}