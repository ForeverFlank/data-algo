#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int deg[n] = {0};
    int max_deg = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 0, tmp = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> tmp;
            deg[i] += tmp;
            count += tmp;
        }
        max_deg = max(max_deg, count);
    }
    int count[n] = {0};
    for (int i = 0; i < n; i++)
    {
        count[deg[i]]++;
    }
    for (int i = 0; i <= max_deg; i++)
    {
        cout << count[i] << " ";
    }
    return 0;
}