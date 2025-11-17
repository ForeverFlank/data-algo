#include <iostream>

using namespace std;

void search(string s, int n, int k)
{
	if (n == 0)
	{
		int c = 0, m = 0;
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] == '1')
				c++;
			else
				c = 0;
			m = max(m, c);
		}
		if (m >= k)
			cout << s << "\n";
		return;
	}

	n--;
	search(s + "0", n, k);
	search(s + "1", n, k);
}

int main()
{
	int n, k;
	cin >> n >> k;

	search("", n, k);	

	return 0;
}

