#include <iostream>
#include <unordered_map>

typedef long long ll;

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    unordered_map<ll, ll> map;

    for (int i = 0; i < n; i++)
    {
        ll p, c;
        cin >> p >> c;
        map[c] = p;
    }

    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;

        if (a == b)
        {
            cout << "NO\n";
            continue;
        }

        auto pa = map.find(a);
        auto pb = map.find(b);

        if (pa == map.end() ||
            pb == map.end())
        {
            cout << "NO\n";
            continue;
        }

        auto gpa = map.find(pa->second);
        auto gpb = map.find(pb->second);
        
        if (gpa == map.end() ||
            gpb == map.end() ||
            gpa->second != gpb->second)
        {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
    }

    return 0;
}