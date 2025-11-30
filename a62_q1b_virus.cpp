#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int> arr)
{
    if (arr.size() == 2)
        return arr[0] == 0 &&
               arr[1] == 1;

    int hlen = arr.size() / 2;
    vector<int> l1(arr.begin(), arr.begin() + hlen);
    vector<int> l2(arr.begin(), arr.begin() + hlen);
    vector<int> r (arr.begin() + hlen, arr.end());
    reverse(l2.begin(), l2.end());

    return (check(l1) || check(l2)) && check(r);
}

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int len = 1 << k;
        vector<int> arr(len);
        for (int j = 0; j < len; j++)
        {
            cin >> arr[j];
        }
        cout << (check(arr) ? "yes" : "no") << "\n";
    }
    return 0;
}
