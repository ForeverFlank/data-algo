#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        int yr, mn;
        cin >> yr >> mn;
        p[i] = yr * 13 + mn;
    }

    sort(p.begin(), p.end());

    for (int i = 0; i < m; i++)
    {
        int yr, mn;
        cin >> yr >> mn;
        int t = yr * 13 + mn;
        
        auto it = lower_bound(p.begin(), p.end(), t);
        
        if ((it > p.begin() && *it != t) ||
            it == p.end()) it--;
        
        if (t < p.front())
            cout << "-1 -1 ";
        else if (*it == t)
            cout << "0 0 ";
        else
            cout << *it / 13 << " " << *it % 13 << " ";
    }

    return 0;
}