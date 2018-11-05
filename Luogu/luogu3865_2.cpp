#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int n, m;
int a[Maxn], log_2[Maxn], st[Maxn][20];

inline void init_ST(int *a, int st[][20])
{
    for(int i = 2; i <= n; ++i) log_2[i] = log_2[i>>1]+1;
    // st[i][j] --> [i-2^j+1, i]
    for(int i = 1; i <= n; ++i)
    {
        st[i][0] = a[i];
        for(int j = 1; j <= log_2[i]; ++j)
            st[i][j] = max(st[i][j-1], st[i-(1<<(j-1))][j-1]);
    }
}

inline int query(int l, int r, int st[][20])
{
    int k = log_2[r-l+1];
    return max(st[r][k], st[l+(1<<k)-1][k]);
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", a+i);
    init_ST(a, st);
    for(int i = 1, l, r; i <= m; ++i)
    {
        scanf("%d%d", &l, &r);
        printf("%d\n", query(l, r, st));
    }
    return 0;
}
