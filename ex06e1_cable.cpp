#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int adj[n][n];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int a;
            cin >> a;
            adj[i][j] = a;
            adj[j][i] = a;
        }
    }
    for (int i = 0; i < n; i++)
    {
        adj[i][i] = -1;
    }

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;
    pq.push({0, 0});
    bool visited[n] = {0};
    int res = 0, cnt = 0;

    while (cnt < n)
    {
        pair<int, int> item = pq.top();
        pq.pop();
        int w = item.first;
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
