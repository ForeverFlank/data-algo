#include <iostream>

using namespace std;

// |a b||a b| = |aa+bc ab+bd|
// |c d||c d|   |ac+cd bc+dd|

void matmul(int *out, int *l, int *r, int k)
{
    int mul[4][4] = {
        {0, 0, 1, 2},
        {0, 1, 1, 3},
        {2, 0, 3, 2},
        {2, 1, 3, 3}
    };
    int res[4];
    for (int i = 0; i < 4; i++)
    {
        int a = l[mul[i][0]] * r[mul[i][1]];
        int b = l[mul[i][2]] * r[mul[i][3]];
        res[i] = ((a % k) + (b % k)) % k;
    }
    for (int i = 0; i < 4; i++)
        out[i] = res[i];
}

int main()
{
    int n, k;
    cin >> n >> k;
    int mat[4];
    for (auto &x : mat)
        cin >> x;

    int dp[31][4];
    for (int i = 0; i < 4; i++)
        dp[0][i] = mat[i];

    for (int i = 1, p = 2; p <= n; i++, p *= 2)
        matmul(dp[i], dp[i - 1], dp[i - 1], k);

    int res[4] = {1, 0, 0, 1};
    for (int i = 0; i < 31; i++)
    {
        if (1 & (n >> i))
        {
            matmul(res, res, dp[i], k);
        }
    }

    for (auto &x : res)
        cout << x << " ";

    return 0;
}
