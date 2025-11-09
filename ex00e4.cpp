#include <iostream>
#include <vector>

using namespace std;

void collect(vector<string> &res, string &curr, int len, int rem)
{
    if (rem > len) return;
    if (len == 0)
    {
        res.push_back(curr);
        return;
    }

    if (rem > 0)
    {
        curr += '1';
        collect(res, curr, len - 1, rem - 1);
        curr.pop_back();
    }

    curr += '0';
    collect(res, curr, len - 1, rem);
    curr.pop_back();
}

int main()
{
    int a, b;
    cin >> a >> b;

    vector<string> res;
    string str = "";
    collect(res, str, b, a);
    for (auto item : res)
        cout << item << "\n";
    
    return 0;
}