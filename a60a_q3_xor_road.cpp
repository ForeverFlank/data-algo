#include <iostream>
#include <vector>
#include <queue>

typedef unsigned long long ull;
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<ull> city(n);
    vector<vector<ull>> adj(n, vector<ull>(n));
    for (int i = 0; i < n; i++)
    {
        cin >> city[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            ull beauty = city[i] ^ city[j];
            adj[i][j] = beauty;
            adj[j][i] = beauty;
        }
    }

    priority_queue<pair<ull, int>> pq;
    pq.push({0, 0});
    bool visited[n] = {0};
    ull res = 0;
    int cnt = 0;

    while (cnt < n)
    {
        pair<ull, int> item = pq.top();
        pq.pop();
        ull w = item.first;
        int u = item.second;
        if (visited[u]) continue;
        visited[u] = true;
        res += w;
        cnt++;
        for (int v = 0; v < n; v++)
        {
            pq.push({adj[u][v], v});
        }
    }
    
    cout << res << endl;

    return 0;
}
