#include <bits/stdc++.h>

using namespace std;

const int Maxn = 5e4+7;
const int Maxm = 5e2+7;

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
        if(mmp.count(k[i])) mmp[k[i]] += p[i];
        else mmp.insert(make_pair(k[i], p[i]));
        v[i] = max(v[i], mmp.count(x) ? mmp[x] : 0);
        f[i][0] = f[i-1][0]+v[i];
    }

    long long ans = f[n][0];
    for(int i = 2; i <= n; ++i)
    {
        for(int j = 1; j <= min(i-1, m); ++j)
        {
            f[i][j] = max(f[i-2][j-1]+2*v[i], f[i-1][j]+v[i]);
            if(i == n) ans = max(ans, f[i][j]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
