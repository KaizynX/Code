#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxt = 1e3+7;
const int Maxn = 1e2+7;

int D, n;
int dp[Maxn][Maxt];
// dp[i][j] when deal whit rubbish i, with j energy can clab max hight
struct Rubbish
{
    int t, f, h;
    bool operator < (const Rubbish &b) const
    {
        return t < b.t;
    }
} a[Maxn];

int main()
{
    scanf("%d%d", &D, &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d%d%d", &a[i].t, &a[i].f, &a[i].h);
    sort(a+1, a+n+1);
    memset(dp, 0x80, sizeof dp);
    int cnt = 10; // max energy
    for(int i = 0; i <= cnt; ++i) dp[0][i] = 0;
    for(int i = 1; i <= n; ++i)
    {
        // starve to death
        if(cnt < a[i].t)
        {
            printf("%d\n", cnt);
            return 0;
        }
        if(dp[i-1][a[i].t]+a[i].h >= D)
        {
            printf("%d\n", a[i].t);
            return 0;
        }
        // put it
        for(int j = a[i].t; j <= cnt; ++j)
            dp[i][j] = dp[i-1][j] + a[i].h;
        cnt += a[i].f;
        // eat it
        for(int j = a[i].t; j <= cnt-a[i].f; ++j)
            dp[i][j+a[i].f] = max(dp[i][j+a[i].f], dp[i-1][j]);
    }
    printf("%d\n", cnt);
    return 0;
}
