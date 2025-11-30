#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int main()
{
    int nv, ne;
    cin >> nv >> ne;
    vector<vector<int>> adj(nv);
    vector<int> count(nv, 0);
    vector<int> color(nv, 1);

    for (int i = 0; i < ne; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
        // count[u]++;
        count[v]++;
    }

    queue<int> q;
    for (int i = 0; i < nv; i++)
        if (count[i] == 0)
            q.push(i);

    while (q.size())
    {
        int u = q.front();
        q.pop();
        // cout << u << endl;

        // if (traversed.find(u) != traversed.end()) continue;
        // traversed.insert(u);

        for (int &v : adj[u])
        {
            count[v]--;

            if (count[v] == 0)
                q.push(v);

            if (color[v] <= color[u])
                color[v] = color[u] + 1;
        }
    }

    int res = 0;
    for (int c : color)
    {
        res = max(res, c);
    }
    cout << res << "\n";

    return 0;
}
