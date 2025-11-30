#include <iostream>
#include <vector>

using namespace std;

bool traverse(int s, int u, int k, vector<vector<int>> &adj, bool traversed[])
{
	int n = adj.size();
	for (int v = 0; v < n; v++)
	{
		if (traversed[v]) continue;

		int w = adj[u][v];
	   	if (w == 0) continue;
		
		int s_next = s + w;
		if (s_next > k) continue;
		if (s_next == k) return true;
		
		traversed[u] = true;
		if (traverse(s_next, v, k, adj, traversed))
			return true;
		traversed[u] = false;
	}
	return false;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n, vector<int>(n, 0));
	int k[8];
	for (int i = 0; i < 8; i++)
		cin >> k[i];
	for (int i = 0; i < m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		adj[a][b] = w;
		adj[b][a] = w;
	}
	for (int i = 0; i < 8; i++)
	{
		bool res = false;
		for (int u = 0; u < n && !res; u++)
		{
			bool traversed[n] = {0};
			traversed[u] = true;
			res |= traverse(0, u, k[i], adj, traversed); 
		}
		cout << (res ? "YES" : "NO") << endl;
	}

	return 0;
}
