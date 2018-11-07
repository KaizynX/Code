#include <bits/stdc++.h>

using namespace std;

const int Maxn = 5e3+7;
const int MOD = 1e9+7;

int n, m, k;
long long q, ans;
int a[Maxn];
int b[Maxn][Maxn];

inline long long f(int x)
{
    long long res = 0;
    for(int i = m; i >= 0; --i)
        res = (res*x+a[i])%MOD;
    return res;
}

void work()
{
    for(int i = 2; i <= n-k+2; ++i) b[k][i] = i-1;
    for(int i = k-1; i; --i)
        for(int j = k-i+2; j <= n-i+2; ++j) // b[i] = j
            for(int l = k-i+1; l < j; ++l)
                (b[i][j] += b[i+1][l]) %= MOD;
#ifdef DEBUG
    for(int i = 1; i <= k; ++i)
    {
        for(int j = 1; j <= n+1; ++j)
            printf("%d ", b[i][j]);
        putchar('\n');
    }
#endif
}

int main()
{
    scanf("%d%d%d%lld", &n, &m, &k, &q);
    for(int i = 0; i <= m; ++i) scanf("%d", a+i);
    work();
    ans = f((int)(q%MOD))*b[1][n+1]%MOD;
    printf("%lld\n", ans);
    return 0;
}
