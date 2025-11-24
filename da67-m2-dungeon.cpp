#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int n, d, t, z;
    cin >> n >> d >> t >> z;

    priority_queue<int,
                   vector<int>,
                   greater<int>> items[z];
    for (int i = 0; i < d; i++)
    {
        int ti, zi;
        cin >> ti >> zi;
        items[zi].push(ti);
    }

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int q, use = 0;
        cin >> q;
        for (int j = 0; j < q; j++)
        {
            int zi;
            cin >> zi;

            if (items[zi].empty()) break;
            
            int top = items[zi].top();
            items[zi].pop();
            use += top;
            if (use > t) goto end;
        }
        t -= use;
        res++;
    }

    end: cout << res << endl;;

    return 0;
}

