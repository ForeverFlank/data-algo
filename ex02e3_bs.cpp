#include <iostream>

using namespace std;

int bsearch(int *arr, int n, int q)
{
    if (q < arr[0]) return -1;
    int l = 0, r = n;
    while (l < r)
    {
        int m = l + (r - l) / 2;
        if (q >= arr[m])
            l = m + 1;
        else
            r = m;
    }
    l--;
    return l;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (auto &x : arr)
        cin >> x;
    for (int i = 0; i < m; i++)
    {
        int q;
        cin >> q;
        cout << bsearch(arr, n, q) << "\n";
    }
    return 0;
}
