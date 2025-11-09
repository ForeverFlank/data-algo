#include <iostream>
#include <vector>
using namespace std;
void reverse(vector<int> &v, vector<int>::iterator a, vector<int>::iterator b)
{
    if (a > b) swap(a, b);
    size_t start = a - v.begin();
    size_t stop = b - v.begin();
    size_t diff = stop - start;
    for (size_t i = 0; i < diff / 2; i++)
    {
        swap(v[start + i], v[start + diff - i - 1]);
    }
}
int main()
{
    //read input
    int n, a, b;
    cin >> n;
    vector<int> v;
    for (int i = 0;i < n;i++)
    {
        int c;
        cin >> c;
        v.push_back(c);
    }
    cin >> a >> b;
    //call function
    reverse(v, v.begin() + a, v.begin() + b + 1);
    //display content of the vector
    for (auto &x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}