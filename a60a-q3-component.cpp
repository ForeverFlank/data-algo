#include <iostream>
#include <vector>

using namespace std;

void traverse(
    vector<vector<int>> &adj,
    bool traversed[],
    int u
)
{
    if (traversed[u]) return;
    traversed[u] = true;
    for (int &v : adj[u])
        traverse(adj, traversed, v);
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
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool traversed[nv] = {0};
    int res = 0;
    for (int i = 0; i < nv; i++)
    {
        if (!traversed[i])
        {
            res++;
            traverse(adj, traversed, i);
        }
        else continue;
    }
    cout << res << endl;

    return 0;
}
