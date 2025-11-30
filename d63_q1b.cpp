#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bsearch(vector<int> &v, int p)
{
    if (p < v.front()) return 0;
    if (p > v.back()) return v.size();

    size_t l = 0, h = v.size() - 1;
    size_t m;
    int x;
    while (l <= h)
    {
        m = l + (h - l) / 2;
        x = v[m];
        if (x == p) return m + 1;
        if (x < p) l = m + 1;
        if (x > p) h = m - 1;
    }

    if (v[m] > p) m--;
    return m + 1;
}

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < m; i++)
    {
        int p;
        cin >> p;

        cout << bsearch(v, p + k) - bsearch(v, p - k - 1) << " ";
    }

    return 0;
}