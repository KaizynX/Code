#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxt = 1e3+7;
const int Maxn = 1e2+7;

int D, n;
int dp[Maxn];
// dp[i] at height i can get max energy
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
    memset(dp, -1, sizeof dp);
    dp[0] = 10;
    for(int i = 1; i <= n; ++i)
        for(int j = D; j >= 0; --j)
            if(dp[j] >= a[i].t)
            {
                if(j+a[i].h >= D)
                {
                    printf("%d\n", a[i].t);
                    return 0;
                }
                dp[j+a[i].h] = max(dp[j+a[i].h], dp[j]);
                dp[j] += a[i].f;
            }
    printf("%d\n", dp[0]);
    return 0;
}
