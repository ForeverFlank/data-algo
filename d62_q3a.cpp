#include <iostream>
#include <set>

using namespace std;

void search(set<int> &res, int n, int a)
{
    if (a >= n) return;
    res.insert(a);
    search(res, n, 2 * a + 1);
    search(res, n, 2 * a + 2);
}

int main()
{
    int n, a;
    cin >> n >> a;
    set<int> res;
    search(res, n, a);
    cout << res.size() << "\n";
    for (auto node : res)
    {
        cout << node << " ";
    }
    return 0;
}