#include <iostream>
#include <queue>
#include <set>

using namespace std;

int main()
{
    int r, c, steps;
    cin >> r >> c >> steps;
    int m[r][c];
    queue<pair<int, int>> q;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> m[i][j];
            if (m[i][j] == 1)
                q.push({i, j});
        }
    }
    for (int t = 0; t <= steps; t++)
    {
        int size = q.size();
        set<pair<int, int>> s;
        for (int i = 0; i < size; i++)
        {
            pair<int, int> u = q.front();
            q.pop();
            int y = u.first, x = u.second;
            m[y][x] = 1;
            if (y - 1 >= 0 && m[y - 1][x] == 0)
                s.insert({y - 1, x});
            if (y + 1 <  r && m[y + 1][x] == 0)
                s.insert({y + 1, x});
            if (x - 1 >= 0 && m[y][x - 1] == 0)
                s.insert({y, x - 1});
            if (x + 1 <  c && m[y][x + 1] == 0)
                s.insert({y, x + 1});
        }
        for (pair<int, int> item : s)
            q.push(item);
    }
    int res = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (m[i][j] == 1) res++;
            // cout << m[i][j] << " ";
        // cout << endl;
    cout << res << endl;
    return 0;
}
