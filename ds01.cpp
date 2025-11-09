#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    unordered_set<int> s(arr, arr + n);
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;

        bool found = false;
        for (int j = 0; j < n; j++)
        {
            auto it = s.find(num - arr[j]);
            if (it != s.end() && *it != arr[j])
            {
                found = true;
                break;
            }
        }
        cout << (found ? "YES" : "NO") << "\n";
    }

    return 0;
}
