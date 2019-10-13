#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 2e5;
#ifndef DEBUG
const int V = 1e6;
#else
const int V = 12;
#endif
const int MOD = 998244353;

int n, res;
int a[N+7], w[V+7], sum[V+7], a2[V+7];

void exgcd(int a, int b, int &x, int &y)
{
    if (!b) { x = 1; y = 0; return; }
    exgcd(b, a%b, y, x);
    y -= a/b*x;
}

inline int mul_inv(int a, int mo)
{
    int x, y;
    exgcd(a, mo, x, y);
    return (x%mo+mo)%mo;
}

int main()
{
    for (int i = 1; i <= V; ++i) {
        // w[i] = 0
        for (int j = 1; j*j <= i; ++j) {
            if (i%j) continue;
            w[i] = (w[i]+w[j])%MOD;
            if (i/j != j) w[i] = (w[i]+w[i/j])%MOD;
        }
        // w[i] = sum( w[d]; d | i, d < i )
        w[i] = ((mul_inv(i, MOD)-w[i])%MOD+MOD)%MOD;
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
        for (int j = 1; j*j <= a[i]; ++j) {
            if (a[i]%j) continue;
            sum[j] = (sum[j]+a[i])%MOD;
            a2[j] = (a2[j]+static_cast<int>(1ll*a[i]*a[i]%MOD))%MOD;
            if (a[i]/j != j) {
                sum[a[i]/j] = (sum[a[i]/j]+a[i])%MOD;
                a2[a[i]/j] = (a2[a[i]/j]+static_cast<int>(1ll*a[i]*a[i]%MOD))%MOD;
            }
        }
    }
    for (int i = 1, inv2 = mul_inv(2, MOD); i <= V; ++i) {
#ifdef DEBUG
        printf("%d %d %d\n", i, sum[i], a2[i]);
#endif
        int cur = static_cast<int>(1ll*w[i]*inv2%MOD*
                  (((1ll*sum[i]*sum[i]%MOD-a2[i])%MOD+MOD)%MOD) %MOD);
        res = (res+cur)%MOD;
    }
    printf("%d\n", res);
    return 0;
}
