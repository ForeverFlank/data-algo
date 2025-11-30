#include <iostream>

using namespace std;

int main()
{
    int k, n, mod = 32717;
    cin >> k >> n;

    int c[k], a[k], dp[n + 1], tmp;
    for (int i = 0; i < k; i++)
    {
        cin >> tmp;
        c[i] = tmp % mod;
    }
    for (int i = 0; i < k; i++)
    {
        cin >> tmp;
        dp[i] = a[i] = tmp % mod;
        
    }

    if (n < k)
    {
        cout << a[n] << endl;
        return 0;
    }

    for (int i = k; i <= n; i++)
    {
        int s = 0;
        for (int j = 1; j <= k; j++)
        {
            s = (s + c[j - 1] * dp[i - j]) % mod;
        }
        dp[i] = s;
    }

    cout << dp[n] << endl;
    return 0;
}
