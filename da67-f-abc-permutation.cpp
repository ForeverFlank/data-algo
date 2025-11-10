#include <iostream>
#include <set>

using namespace std;

void perm(set<string> &s, string &str, int n, int a, int b, int c)
{
	if (n == 0)
	{
		s.insert(str);
		return;
	}

	if (a)
	{
		str.push_back('A');
		perm(s, str, n - 1, a - 1, b, c);
		str.pop_back();
	}
	if (b)
	{
		str.push_back('B');
		perm(s, str, n - 1, a, b - 1, c);
		str.pop_back();
	}
	if (c)
	{
		str.push_back('C');
		perm(s, str, n - 1, a, b, c - 1);
		str.pop_back();
	}
}

int main()
{
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	
	set<string> s;
	string str = "";
	perm(s, str, n, a, b, c);

	cout << s.size() << "\n";
	for (auto item : s)
	{
		cout << item << "\n";
	}

	return 0;
}

