#include <iostream>

using namespace std;

int main()
{   
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (auto &x : arr)
    {
        cin >> x;
    }
    for (int q = 0; q < m; q++)
    {
        int x;
        cin >> x;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == x) break;
            if (arr[i] > x) count++;
        }
        cout << count << endl;
    }
    return 0;
}
