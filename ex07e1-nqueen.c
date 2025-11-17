#include <stdio.h>

// I use C btw
// written in vim on arch btw

void solve(int *res, int n, int r, int c, char *v, char *h, char *ud, char *dd)
{
	// printf("%d %d\n", r, c);
	int y = c / n;
	int x = c % n;
	int udiag = x + y;
	int ddiag = n + y - x - 1;

	if (v[x] || h[y] || ud[udiag] || dd[ddiag])
		return;

	if (r == n)
	{
		(*res)++;
		return;
	}

	r++;
	v[x] = 1;
	h[y] = 1;
	ud[udiag] = 1;
	dd[ddiag] = 1;
	for (int i = (y + 1) * n; i < n * n - n + r; i++)
	{
		solve(res, n, r, i, v, h, ud, dd);
	}
	v[x] = 0;
	h[y] = 0;
	ud[udiag] = 0;
	dd[ddiag] = 0;
}

int main()
{
	int n;
	scanf("%d", &n);
	
	char v[n] = {0}, h[n] = {0},
	 	 ud[2 * n - 1] = {0}, dd[2 * n - 1] = {0};
	int res = 0;
	for (int i = 0; i < n * n - n; i++)
	{
		solve(&res, n, 1, i, v, h, ud, dd);
	}

	printf("%d\n", res);

	return 0;
}
