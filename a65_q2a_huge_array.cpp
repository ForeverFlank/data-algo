#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++)
    {
        int x, c;
        cin >> x >> c;
        pq.push({x, c});
    }
    int pos[n], val[n], acc = 0;
    for (int i = 0; i < n; i++)
    {
        auto item = pq.top();
        pq.pop();
        // cout << item.first << " " << acc << endl;
        val[i] = item.first;
        pos[i] = acc;
        acc += item.second;
    }
    for (int i = 0; i < q; i++)
    {
        int idx;
        cin >> idx;
        auto it = upper_bound(pos, pos + n, idx - 1) - 1;
        // cout << "(" << it - pos << ") ";
        cout << val[it - pos] << endl;
    }
    return 0;
}

// 4 4 4 4 4 7 7 7 7 7 7 7 8 8 8 9 9 9 9

