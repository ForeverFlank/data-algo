#include <iostream>
#include <vector>
#include <set>

using namespace std;

void traverse(vector<vector<int>> &m, int y, int x, vector<vector<bool>> &traversed, string &str)
{
    if (traversed[y][x]) return;
    if (m[y][x] == 1) return;

    if (y == m.size() - 1 && x == m[0].size() - 1)
    {
        cout << str << "\n";
        return;
    }

    if (x + 1 < m[0].size())
    {
        str += 'A';
        traversed[y][x] = true;
        traverse(m, y, x + 1, traversed, str);
        traversed[y][x] = false;
        str.pop_back();
    }
    if (y + 1 < m.size())
    {
        str += 'B';
        traversed[y][x] = true;
        traverse(m, y + 1, x, traversed, str);
        traversed[y][x] = false;
        str.pop_back();
    }
    if (y - 1 >= 0)
    {
        str += 'C';
        traversed[y][x] = true;
        traverse(m, y - 1, x, traversed, str);
        traversed[y][x] = false;
        str.pop_back();
    }
}

int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> m(r, vector<int>(c));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> m[i][j];
    vector<vector<bool>> traversed(r, vector<bool>(c, false));
    string str = "";        
    traverse(m, 0, 0, traversed, str);
    cout << "DONE\n";
    return 0;
}