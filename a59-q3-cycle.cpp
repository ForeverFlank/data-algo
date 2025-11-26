#include <iostream>
#include <vector>

using namespace std;

int cycle(
    vector<vector<int>> &adj,
    bool traversed[],
    vector<int> &path,
    int u,
    int prev
)
{
    for (int &v : adj[u])
    {
        if (v == prev) continue;
        if (traversed[v])
        {
            for (int i = path.size() - 2; i >= 0; i--)
            {
                if (u == path[i])
                    return path.size() - i; 
            }
        }

        traversed[v] = true;
        path.push_back(u);
        int res = cycle(adj, traversed, path, v, u);
        if (res != 0) return res;
        traversed[v] = false;
        path.pop_back();
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool traversed[n] = {1};
    vector<int> path;
    cout << cycle(adj, traversed, path, 0, -1) << endl;

    return 0;
}
