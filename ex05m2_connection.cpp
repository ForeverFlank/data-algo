#include <iostream>
#include <vector>
#include <set>

using namespace std;

void traverse(
    vector<vector<int>> &adj,
    set<int> &s,
    int u,
    int k
)
{
    s.insert(u);
    if (k == 0) return;
    for (int &v : adj[u])
        traverse(adj, s, v, k - 1);
}

int main()
{
    int nv, ne, k;
    cin >> nv >> ne >> k;
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
        set<int> s;
        traverse(adj, s, i, k);
        res = max(res, (int)s.size());
    }
    cout << res << endl;

    return 0;
}
