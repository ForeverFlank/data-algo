#include <iostream>

using namespace std;

bool check(int *l, int *r, int len)
{
    if (len == 2) return true;
    
    int l_cnt = 0, r_cnt = 0;
    int *it = l;
    while (it < l + len / 2)
    {
        if (*it == 1) l_cnt++;
        it++;
    }
    while (it < r)
    {
        if (*it == 1) r_cnt++;
        it++;
    }

    int diff = l_cnt - r_cnt;
    return
        -1 <= diff && diff <= 1        &&
        check(l, l + len / 2, len / 2) &&
        check(l + len / 2, r, len / 2);
}

int main()
{
    int n, k;
    cin >> n >> k;
    int len = 1 << k;
    int arr[len];
    for (int i = 0; i < n; i++)
    {
        for (auto &x : arr)
            cin >> x;
        cout << (check(arr, arr + len, len) ? "yes" : "no") << "\n";
    }

    return 0;
}
