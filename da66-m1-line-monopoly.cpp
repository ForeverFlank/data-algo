#include <iostream>
#include <map>

using namespace std;

void merge(map<int, int>& ranges, map<int, int>::iterator it)
{
    int l = it->first;
    int r = it->second;
    bool del = false;
    while (it != ranges.end() && it->first <= r + 1)
    {
        r = max(r, it->second);
        if (del)
            it = ranges.erase(it);
        else
            it++;
        ranges[l] = r;
        del = true;
    }
}

void add_range(map<int, int>& ranges, int a, int b)
{
    map<int, int>::iterator it = ranges.find(a);
    bool exist = it != ranges.end();
    if (exist)
        ranges[a] = max(ranges[a], b);
    else
        it = ranges.insert({a, b}).first;
    bool p = !exist && it != ranges.begin();
    if (p)
        merge(ranges, it--);
    merge(ranges, it);    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    map<int, int> ranges;
    for (int i = 0; i < n; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int a, b;
            cin >> a >> b;
            add_range(ranges, a, b);
        }
        if (op == 2)
        {
            cout << ranges.size() << "\n";  
        }
    }
    return 0;
}

