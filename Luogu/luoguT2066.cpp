#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int Maxn = 5e3+7;
const int MOD = 1e9+7;

int n, m, k;
long long q, ans, fv;
int a[Maxn];
long long b[Maxn][Maxn];

inline long long f(int x)
{
    long long res = 0;
    for(int i = m; i >= 0; --i)
        res = (res*x+a[i])%MOD;
    return res;
}

long long work(int cur, int last)
{
    if(b[cur][last]) return b[cur][last];
    if(cur == k) return last-1;
    for(int i = 1; i < last; ++i)
        (b[cur][last]+=work(cur+1, i))%=MOD;
    return b[cur][last];
}

#ifdef DEBUG
inline void print()
{
	printf("%lld\n", f((int)(q%MOD)));
    for(int i = 1; i <= k; ++i)
    {
        for(int j = 1; j <= n; ++j)
            printf("%lld ", b[i][j]);
        putchar('\n');
    }
}
#endif

int main()
{
    scanf("%d%d%d%lld", &n, &m, &k, &q);
    for(int i = 0; i <= m; ++i) scanf("%d", a+i);
    ans = f((int)(q%MOD))*work(1, n+1)%MOD;
    printf("%lld\n", ans);
#ifdef DEBUG
    print();
#endif
    return 0;
}
