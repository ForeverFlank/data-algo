#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define pii pair<int, int>
#define pipii pair<int, pii>

using namespace std;

vector<int> get_edges(int yx, int r, int c)
{
    vector<int> res;
    int y = yx / c;
    int x = yx % c;
    if (y - 1 >= 0) res.push_back((y - 1) * c + x);
    if (y + 1 <  r) res.push_back((y + 1) * c + x);
    if (x - 1 >= 0) res.push_back(y * c + x - 1);
    if (x + 1 <  c) res.push_back(y * c + x + 1);
    return res;
}

int main()
{
    int r, c;
    cin >> r >> c;
    
    vector<int> m(r * c);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> m[i * c + j];

    vector<int> dist(r * c, INT_MAX);
    dist[0] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});

    while (pq.size())
    {
        pii top = pq.top();
        pq.pop();
        int d = top.first;
        int u = top.second;
        if (dist[u] < d) continue;
        for (int &v : get_edges(u, r, c))
        {
            int w = m[v];
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << dist[i * c + j] << " ";
        }
        cout << endl;
    }

    return 0;
}