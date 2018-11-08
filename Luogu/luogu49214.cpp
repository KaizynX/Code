#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int Maxn = 5e3+7;
const int MOD = 998244353;

int T, n;
int a[Maxn][Maxn];

inline void init()
{
    const int N = 10;
    a[1][1] = 1;
    for(int i = 2; i <= N; ++i)
    {
        for(int j = 1; j <= i; ++j)
        {
            a[i][j] = ((a[i-1][j-1]+a[i-1][j])%MOD+a[i][j-1])%MOD;
#ifdef DEBUG
            printf("%d ", a[i][j]);
#endif
        }
#ifdef DEBUG
        putchar('\n');
#endif
    }
}

int main()
{
    init();
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        printf("%d\n", a[n][n]);
    }
    return 0;
}
