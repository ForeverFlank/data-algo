#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define pdd pair<double, double>
using namespace std;

int main()
{
    double W;
    int n;
    cin >> W >> n;
    vector<pdd> vw(n);
    for (auto &vwi : vw) cin >> vwi.first;
    for (auto &vwi : vw) cin >> vwi.second;

    sort(vw.begin(), vw.end(), [](pdd a, pdd b)
    {
        return a.first / a.second > b.first / b.second;
    });

    double res = 0;
    for (int i = 0; i < n; i++)
    {
        pdd item = vw[i];
        double v = item.first;
        double w = item.second;
        if (W > w)
        {
            res += v;
            W -= w;
        }
        else
        {
            res += v * W / w;
            break;
        }
    }
    printf("%.4f\n", res);

    return 0;
}
