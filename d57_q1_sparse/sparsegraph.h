#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__

#include <vector>
#include <set>

using namespace std;

class SparseGraph
{
public:
    SparseGraph() : SparseGraph(3) { }

    SparseGraph(int n_in) : transposed(false) { }

    SparseGraph(const SparseGraph &G) : adj(G.adj), transposed(G.transposed) { }

    void AddEdge(int a, int b)
    {
        auto edge = transposed ? make_pair(b, a) : make_pair(a, b);
        adj.insert(edge);
    }

    void RemoveEdge(int a, int b)
    {
        auto edge = transposed ? make_pair(b, a) : make_pair(a, b);
        adj.erase(edge);
    }

    bool DoesEdgeExist(int a, int b) const
    {
        auto edge = transposed ? make_pair(b, a) : make_pair(a, b);
        return adj.find(edge) != adj.end();
    }

    SparseGraph Transpose() const
    {
        SparseGraph g_t(*this);
        g_t.transposed = !transposed;
        return g_t;
    }

protected:
    set<pair<int, int>> adj;
    bool transposed;
};
#endif // __SPARSE_GRAPH_H__

