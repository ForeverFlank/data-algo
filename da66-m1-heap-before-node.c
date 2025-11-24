#include <stdio.h>

// C btw
// written in vim on arch btw

void traverse(int node, int n, char *tree, int *res)
{
    if (node >= n) return;
    tree[node] = 1;
    (*res)--;
    traverse(2 * node + 1, n, tree, res);
    traverse(2 * node + 2, n, tree, res);
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    char tree[n] = {0};
    int res = n;
    traverse(m, n, tree, &res);
    printf("%d\n", res);
    for (int i = 0; i < n; i++)
    {
        if (!tree[i]) printf("%d ", i);
    }
    return 0;
}

