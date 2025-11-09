#include <iostream>

using namespace std;

int fib(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    int a = 0, b = 1;
    for (int i = 0; i < n; i++)
    {
        int c = a;
        a = b;
        b = c + b;
    }
    return a;
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}