#include <bits/stdc++.h>

using namespace std;

const int Maxn = 5e5+7;
const int MOD = 1e9+7;

int n, m, k;
long long q, ans;
int a[Maxn];
int mul[Maxn];

inline long long f(int x)
{
    long long res = 0;
    for(int i = m; i >= 0; --i)
        res = (res*x+a[i])%MOD;
    return res;
}

inline void init()
{
    mul[1] = 1;
    for(int i = 2; i <= n; ++i)
        mul[i] = (int)((1ll*mul[i-1]*i)%MOD);
}

void exgcd(int a, int b, int &x, int &y)
{
    if(!b) { x = 1; y = 0; return; }
    exgcd(b, a%b, y, x);
    y -= a/b*x;
}

inline int mul_inverse(int b)
{
    int x, y;
    exgcd(b, MOD, x, y);
    return (x%MOD+MOD)%MOD;
}

inline long long C(int p, int q) // C_p^q
{
    if(p < q) return 0;
    int inv1 = mul_inverse(mul[q]), inv2 = mul_inverse(mul[p-q]);
    return 1ll*mul[p]*inv1%MOD*inv2%MOD;
}

int main()
{
    scanf("%d%d%d%lld", &n, &m, &k, &q);
    for(int i = 0; i <= m; ++i) scanf("%d", a+i);
    init();
    ans = f((int)(q%MOD))*C(n, k)%MOD;
    printf("%lld\n", ans);
    return 0;
}
