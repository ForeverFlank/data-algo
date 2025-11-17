#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int arr[n], cnt[3] = {0};
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		arr[i] = num;
		cnt[num - 1]++;
	}

	int res = 0;
	for (int i = cnt[0], j = 0; i < n; i++)
	{
		if (arr[i] == 1)
		{
			while (arr[j] == 1) j++;
			swap(arr[i], arr[j]);
			res++;
		}
	}
	for (auto x : arr) cout << x << " ";
	for (int i = cnt[0]; i < cnt[0] + cnt[1]; i++)
	{
		if (arr[i] != 2) res++;
	}	

	cout << res << endl;

	return 0;
}

// 2 3 1 3 2 1 3
// 1 1 2 3 2 3 3
