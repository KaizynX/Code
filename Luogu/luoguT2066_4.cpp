#include <bits/stdc++.h>

using namespace std;

const int Maxn = 5e5+7;
const int MOD = 1e9+7;

int n, m, k;
long long q, ans;
int a[Maxn];
int b[Maxn];

inline long long f(int x)
{
    long long res = 0;
    for(int i = m; i >= 0; --i)
        res = (res*x+a[i])%MOD;
    return res;
}

int work(int _n, int _k)
{
    for(int i = 1; i <= _n; ++i) b[i] = i;
    for(int i = 2; i <= _k; ++i)
        for(int j = 1; j <= _n-i+1; ++j)
            (b[j] += b[j-1]) %= MOD;
    return b[_n-_k+1];
}

int main()
{
    scanf("%d%d%d%lld", &n, &m, &k, &q);
    for(int i = 0; i <= m; ++i) scanf("%d", a+i);
    ans = f((int)(q%MOD))*work(n, k)%MOD;
    printf("%lld\n", ans);
    return 0;
}
