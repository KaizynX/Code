#include <iostream>
#include <cstring>
#include <cstdio>
#define DEBUG

using namespace std;

const int Maxn = 1e3+7;

int T, n, m;
int a[Maxn][Maxn];
int u[Maxn][Maxn], l[Maxn][Maxn];

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        memset(a, -1, sizeof a);
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                scanf("%d", &a[i][j]);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
            {
                if(u[i][j] > l[i][j]) u[i][j] = max(u[i][j], a[i][j]);
                else l[i][j] = max(l[i][j], a[i][j]);
                u[i+1][j] = a[i+1][j] > a[i][j+1] ? u[i][j]+l[i][j] : 0;
                l[i][j+1] = a[i+1][j] > a[i][j+1] ? 0 : u[i][j]+l[i][j];
                // u[i][j] = max(a[i-1][j], max(u[i-1][j], l[i-1][j])) + min(u[i-1][j], l[i-1][j]);
                // l[i][j] = max(a[i][j-1], max(u[i][j-1], l[i][j-1])) + min(u[i][j-1], l[i][j-1]);
#ifdef DEBUG
                // printf("%d %d %d %d\n", u[i+1][j], l[i][j+1], u[i][j], l[i][j]);
#endif
            }
#ifdef DEBUG
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= m; ++j)
                printf("(%d,%d) ", u[i][j], l[i][j]);
            putchar('\n');
        }
#endif
        printf("%d\n", max(a[n][m], max(u[n][m], l[n][m])) + min(u[n][m], l[n][m]));
    }
    return 0;
}
