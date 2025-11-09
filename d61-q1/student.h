#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v(A.begin(), A.end());
    unordered_set<T> s(A.begin(), A.end());
    for (auto b : B)
    {
        if (s.find(b) == s.end())
        {
            v.push_back(b);
        }
    }
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    unordered_set<T> s(B.begin(), B.end());
    for (auto a : A)
    {
        if (s.find(a) != s.end())
        {
            v.push_back(a);
        }
    }
    return v;
}
