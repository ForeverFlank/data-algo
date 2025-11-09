#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int main()
{
    int nv, ne;
    cin >> nv >> ne;
    vector<vector<int>> adj(nv, vector<int>(nv, 0));
    vector<int> count(nv, 0);
    vector<int> color(nv, 1);
    unordered_set<int> traversed;

    for (int i = 0; i < ne; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
        count[u]++;
        count[v]++;
    }

    queue<int> q;
    q.push(0);

    while (q.size())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            int u = q.front();
            q.pop();
            // cout << u << endl;

            // if (traversed.find(u) != traversed.end()) continue;
            // traversed.insert(u);

            for (int v = 0; v < nv; v++)
            {
                if (adj[u][v] == 0) continue;

                count[v]--;

                if (count[v] == 0)
                    q.push(v);

                if (color[v] <= color[u])
                    color[v] = color[u] + 1;
            }

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