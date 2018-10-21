#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int Maxn = 5e4+7;
const int Maxm = 5e2+7;
const int Maxp = 1e4;
const int Maxk = 1e9;
// Maxv = n*p = 5e8

int n, m;
int v[Maxn], k[Maxn], p[Maxn];
long long f[Maxn][Maxm];
map<int, int> mmp;

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d%d", k+i, p+i);
        v[i] = max(v[i-1], p[i]);
    }
    for(int i = 1, x; i <= n; ++i)
    {
        scanf("%d", &x);
        mmp[k[i]] += p[i];
        v[i] = max(v[i], mmp[x]);
        f[i][0] = f[i-1][0]+v[i];
#ifdef DEBUG
        printf("v[%d]=%d\n", i, v[i]);
#endif
    }

    long long ans = f[n][0];
    for(int i = 2; i <= n; ++i)
    {
        // before i use j double, use double at n is useless
        for(int j = 1; j <= m; ++j)
        {
            // use 'double' at i-1 or not
            f[i][j] = max(f[i-2][j-1]+2*v[i], f[i-1][j]+v[i]);
#ifdef DEBUG
            printf("f[%d][%d]=%lld\n", i, j, f[i][j]);
#endif
            if(i == n) ans = max(ans, f[i][j]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
