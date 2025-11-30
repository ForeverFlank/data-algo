#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

int main()
{
    int r, c, k;
    cin >> r >> c >> k;
    vector<vector<int>> m(r, vector<int>(c));
    queue<int> q;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> m[i][j];
            if (m[i][j] == 1)
            {
                q.push(i * c + j);
            }
        }
    }

    unordered_set<int> traversed;
    while (k-- >= 0)
    {
        int n = q.size();
        while (n > 0)
        {
            int pos = q.front(); q.pop();
            n--;

            if (traversed.find(pos) != traversed.end()) continue;
            traversed.insert(pos);

            int y = pos / c;
            int x = pos % c;

            if (y + 1 < r) q.push((y + 1) * c + x);
            if (y - 1 >= 0) q.push((y - 1) * c + x);
            if (x + 1 < c) q.push(y * c + x + 1);
            if (x - 1 >= 0) q.push(y * c + x - 1);

            if (m[y][x] == 0) m[y][x] = 2;
        }
    }

    for (auto row : m)
    {
        for (auto cell : row)
        {
            cout << cell << " ";
        }
        cout << "\n";
    }

    return 0;
}