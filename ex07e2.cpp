#include <iostream>

using namespace std;

int f(int n, int target)
{
    if (target < 0) return 0;
    if (target == 0) return 1;
    int res = 0;
    for (int i = n; i <= target; i++)
    {
        res += f(i, target - i);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << f(1, n);
    return 0;
}