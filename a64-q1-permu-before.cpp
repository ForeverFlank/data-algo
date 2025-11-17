#include <iostream>
#include <vector>

using namespace std;

void search(
	int n,
	int m,
	int r,
	string s,
	vector<int> &c,
	vector<bool> &valid
)
{
	if (r == 0)
	{
		cout << s << "\n";
		return;
	}
	r--;
	for (int i = 0; i < n; i++)
	{
		if (!valid[i]) continue;

		int a = c[i];
		if (a != -1 && valid[a]) continue;

		valid[i] = false;
		search(n, m, r, s + to_string(i) + " ", c, valid);
		valid[i] = true;
	}	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> c(n, -1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		c[b] = a;
	}
	vector<bool> valid(n, true);
	search(n, m, n, "", c, valid);
	return 0;
}
