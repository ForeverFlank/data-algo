#include <iostream>
#include <vector>
#include <bitset>

using namespace std;


int main()
{
	int n, m;
	cin >> n >> m;

	vector<bitset<1000>> vs(m);
	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			int d;
			cin >> d;
			vs[i].set(d - 1);
		}
		for (int j = n; j < 1000; j++)
		{
			vs[i].set(j);
		}
	}

	int res = m;
	for (int i = 0; i < (1 << m); i++)
	{
		int popcount = __builtin_popcount(i);
		if (res < popcount) continue;
		bitset<1000> u;
		for (int j = 0; j < m; j++)
		{
			if ((1 & (i >> j)) == 0) continue;
			u |= vs[j];
		}
		if (u.all()) res = min(res, popcount);
	}

	cout << res << "\n";

	return 0;
}

