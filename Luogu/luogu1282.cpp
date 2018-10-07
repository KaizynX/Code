#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define DEBUG

using namespace std;

const int Maxn = 1e3+7;
const int Maxv = 2e4+7;
const int Zero = 1e4;

int n, sum, c[Maxn];
int f[Maxv]; // change i need min time

int main()
{
    int uv, dv;
    uv = dv = sum = Zero;
    scanf("%d", &n);
    for(int i = 1, a, b; i <= n; ++i)
    {
        scanf("%d%d", &a, &b);
        c[i] = a-b;
        sum += c[i];
        c[i] <<= 1;
        if(c[i] < 0) dv += c[i];
        if(c[i] > 0) uv += c[i];
    }
    memset(f, -1, sizeof f);
    f[Zero] = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(c[i] >= 0)
        {
            for(int j = uv; j >= c[i]; --j)
                if(f[j-c[i]] != -1)
                    f[j] = f[j] == -1 ? f[j-c[i]]+1 : min(f[j], f[j-c[i]]+1);
        }
        else // c[i] < 0
        {
            for(int j = dv; j <= Zero*2+c[i]; ++j)
                if(f[j-c[i]] != -1)
                    f[j] = f[j] == -1 ? f[j-c[i]]+1 : min(f[j], f[j-c[i]]+1);
        }
#ifdef DEBUG
        for(int j = dv; j <= uv; ++j)
            printf("(%d, %d) ", j-Zero, f[j]);
        putchar('\n');
#endif
    }
    int ans = Maxn, cur = 0;
    while(ans == Maxn)
    {
        if(f[sum+cur] != -1)
            ans = min(ans, f[sum+cur]);
        if(f[sum-cur] != -1)
            ans = min(ans, f[sum-cur]);
        cur++;
    }
    printf("%d\n", ans);
    return 0;
}
