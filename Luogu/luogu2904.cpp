#include <cstdio>
#include <iostream>
#define DEBUG

using namespace std;

const int Maxn = 2500+7;

int n, m, a[Maxn], f[Maxn];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", a+i);
        f[i] = m+(a[i] += a[i-1]);
    }
    for(int i = 1; i <= n; ++i)
    {
#ifdef DEBUG
        printf("%d 0 %d\n", i, f[i]);
#endif
        for(int j = 1; j < i; ++j)
        {
            f[i] = min(f[i], f[j]+a[i-j]+m+m);
#ifdef DEBUG
            printf("%d %d %d\n", i, j, f[i]);
#endif
        }
    }
    printf("%d\n", f[n]);
    return 0;
}
