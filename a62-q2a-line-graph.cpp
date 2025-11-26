#include <iostream>
#include <vector>

using namespace std;

int traverse(
    vector<vector<int>> &adj,
    bool traversed[],
    int u,
    int prev
)
{
    int res = 1;
    for (int &v : adj[u])
    {
        if (v == prev) continue;
        if (traversed[v])
        {
            res = 0;
            continue;
        }
        traversed[v] = true;
        res &= traverse(adj, traversed, v, u);
    }
    return res & (adj[u].size() <= 2);
}

int main()
{
    int nv, ne;
    cin >> nv >> ne;
    vector<vector<int>> adj(nv);
    for (int i = 0; i < ne; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool traversed[nv] = {0};
    int res = 0;
    for (int i = 0; i < nv; i++)
    {
        if (!traversed[i])
        {
            res += traverse(adj, traversed, i, -1);
        }
        else continue;
    }
    cout << res << endl;

    return 0;
}
