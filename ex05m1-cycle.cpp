#include <iostream>
#include <vector>

using namespace std;

bool traverse(
    vector<vector<int>> &adj,
    bool traversed[],
    int u,
    int prev
)
{
    if (traversed[u])
        return true;
    traversed[u] = true;
    for (int &v : adj[u])
    {
        if (v == prev)
            continue;
        if (traverse(adj, traversed, v, u))
            return true;
    }
    return false;
}

void check()
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
    bool res = false;
    for (int i = 0; i < nv && !res; i++)
    {
        if (traversed[i]) continue;
        res |= traverse(adj, traversed, i, -1);
    }
    cout << (res ? "YES" : "NO") << endl;
}

int main()
{
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
        check();
    return 0;
}
