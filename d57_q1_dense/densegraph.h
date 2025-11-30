#ifndef __DENSE_GRAPH_H__
#define __DENSE_GRAPH_H__

#include <vector>

using namespace std;
class DenseGraph
{
public:
    DenseGraph() : DenseGraph(3) { }

    DenseGraph(int n_in) :
        n(n_in),
        adj(vector<vector<bool>>(n_in, vector<bool>(n_in, false))),
        transposed(false)
    { }

    DenseGraph(const DenseGraph &G) :
        n(G.n),
        adj(G.adj),
        transposed(G.transposed)
    { }

    void AddEdge(int a, int b)
    {
        if (transposed)
            adj[b][a] = true;
        else
            adj[a][b] = true;
    }

    void RemoveEdge(int a, int b)
    {
        if (transposed)
            adj[b][a] = false;
        else
            adj[a][b] = false;
    }

    bool DoesEdgeExist(int a, int b) const
    {
        if (transposed)
            return adj[b][a];
        else
            return adj[a][b];
    }

    DenseGraph Transpose() const
    {
        DenseGraph g_t(*this);
        g_t.transposed = !transposed;
        return g_t;
    }

protected:
    int n;
    vector<vector<bool>> adj;
    bool transposed;
};
#endif // __DENSE_GRAPH_H__
