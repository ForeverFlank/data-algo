#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    unordered_map<string, int> map;
    string name;
    while (n--)
    {
        cin >> name;
        map[name]++;
    }

    vector<pair<string, int>> arr;
    arr.reserve(map.size());
    for (auto item : map)
    {
        arr.push_back(item);
    }

    sort(arr.begin(), arr.end(), [](pair<string, int> a, pair<string, int> b)
    {
        return a.second > b.second;
    });

    size_t idx = min((size_t)k - 1, arr.size() - 1);
    cout << arr[idx].second << endl;

    return 0;
}