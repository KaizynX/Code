#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int Maxn = 1e3+7;

int T, n, m;
int a[Maxn][Maxn];
long long f[Maxn][Maxn];

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        memset(f, 0, sizeof f);
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                scanf("%d", &a[i][j]);
        for(int i = 1; i <= n; ++i)
            for(int j = m; j >= 1; --j)
                f[i][j] = max(max(f[i-1][j], f[i][j+1]), f[i-1][j+1]+a[i][j]);
        printf("%lld\n", f[n][1]);
    }
    return 0;
}
