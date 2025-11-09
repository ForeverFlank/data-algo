#include <iostream>

using namespace std;

bool check()
{
    int n;
    cin >> n;

    int arr[n] = {0};
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (x < 1 || x > n) return 0;
        if (arr[x - 1]) return 0;
        arr[x - 1]++;
    }

    return 1;
}

int main()
{
    cout << (check() ? "YES\n" : "NO\n");
    return 0;
}