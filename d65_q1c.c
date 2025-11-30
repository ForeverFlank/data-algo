#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#define N 100001

// C on top  
// no AIs involved
// stackoverflow >>> clankers 

uint32_t search(uint32_t *prefix, uint32_t val)
{
    uint32_t l = 0, h = N, m;
    while (l < h)
    {
        m = l + (h - l) / 2;
        if (val == prefix[m])
            return m;
        else if (val < prefix[m])
            h = m;
        else
            l = m + 1;
    }
    return l;
}

uint32_t solve(uint32_t *prefix, uint32_t p, uint32_t x)
{
    uint32_t t = search(prefix, p);
    return t <= x ? t : search(prefix, p + prefix[x]);
}

int main()
{
    uint16_t n, start;
    uint32_t m;
    scanf("%hd%d%hd", &n, &m, &start);

    uint16_t incomes[N];
    incomes[0] = start;

    for (uint16_t i = 0; i < n; i++)
    {
        uint32_t a;
        uint16_t s;
        scanf("%d%hd", &a, &s);
        incomes[a] = s;
    }

    uint32_t prefix[N] = {start};
    uint32_t curr_income = start;
    for (uint32_t i = 1; i < N; i++)
    {
        if (incomes[i]) curr_income = incomes[i];
        prefix[i] = prefix[i - 1] + curr_income;
    }
    for (uint32_t i = 0; i < m; i++)
    {
        uint32_t p, x;
        scanf("%d%d", &p, &x);
        uint32_t res = solve(prefix, p, x);
        printf("%d ", res);
    }
    printf("\n");

    return 0;
}