#include <bits/stdc++.h>

using namespace std;

const int Maxn = 5e5+7;
const int MOD = 1e9+7;

int n, m, k;
long long q, ans, fv;
int a[Maxn], b[Maxn];

inline long long f(int x)
{
    long long res = 0;
    for(int i = m; i >= 0; --i)
        res = (res*x+a[i])%MOD;
    return res;
}

void work(int i)
{
    for(b[i] = 1; b[i] < b[i-1]; ++b[i])
        if(i == k) ans = (ans+fv)%MOD;
        else work(i+1);
}

int main()
{
    scanf("%d%d%d%lld", &n, &m, &k, &q);
    for(int i = 0; i <= m; ++i) scanf("%d", a+i);
    b[0] = n+1; fv = f((int)(q%MOD));
    work(1);
    printf("%lld\n", ans);
    return 0;
}
