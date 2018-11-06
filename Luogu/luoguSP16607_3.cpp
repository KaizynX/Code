#include <bits/stdc++.h>

using namespace std;

const int Maxn = 11;
const int Maxm = 1e7+7;
const int MOD = 2004;

int n, m, a, b;
int tr[Maxm];

inline void update_tree(int i, int x)
{
    i++;
    for(; i <= b+1; i += i&-i) tr[i] = (tr[i]+x)%MOD;
}

inline int query_tree(int i, int j)
{
    i++; j++;
    int resi = 0, resj = 0;
    for(i--; i; i -= i&-i) resi = (resi+tr[i])%MOD;
    for(; j; j -= j&-j) resj = (resj+tr[j])%MOD;
    return ((resj-resi)%MOD+MOD)%MOD;
}

int main()
{
    scanf("%d%d%d", &n, &a, &b);
    int sum = 0;
    update_tree(0, 1);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", &m);
        for(int j = min(b, sum+m); j >= 0; --j)
            update_tree(j, query_tree(j-min(m, j), j-1));
        sum = min(sum+m, b); // sum of m[0, i]
    }
    printf("%d\n", query_tree(a, b));
    return 0;
}
