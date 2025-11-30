#include <iostream>
#include <vector>

using namespace std;

void gen_matrix(vector<vector<int>> &m, int a, int b, int x, int y)
{
    if (a == 0) 
    {
        m[y][x] = b;
        return;
    }
    int offset = 1 << (a - 1);
    gen_matrix(m, a - 1, b + 0, x         , y         );
    gen_matrix(m, a - 1, b - 1, x + offset, y         );
    gen_matrix(m, a - 1, b + 1, x         , y + offset);
    gen_matrix(m, a - 1, b + 0, x + offset, y + offset);
}

int main()
{
    int a, b;
    cin >> a >> b;

    int dim = 1 << a;
    vector<vector<int>> m(dim, vector<int>(dim));
    gen_matrix(m, a, b, 0, 0);

    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}