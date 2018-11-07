#include <bits/stdc++.h>

using namespace std;

const int Maxn = 5e3+7;
const int MOD = 1e9+7;

int n, m, k;
long long q, ans;
int a[Maxn];
int b[Maxn][Maxn];

inline long long f(int x)
{
    long long res = 0;
    for(int i = m; i >= 0; --i)
        res = (res*x+a[i])%MOD;
    return res;
}

void work()
{
    for(int i = 2; i <= n-k+2; ++i) b[k][i] = (b[k][i-1]+i-1)%MOD;
    for(int i = k-1; i > 1; --i)
        for(int j = k-i+2; j <= n-i+2; ++j) // b[i] = j
            b[i][j] = (b[i][j-1]+b[i+1][j-1])%MOD;
}

int main()
{
    scanf("%d%d%d%lld", &n, &m, &k, &q);
    for(int i = 0; i <= m; ++i) scanf("%d", a+i);
    work();
    if(k == 1) ans = f((int)(q%MOD))*n%MOD;
    else ans = f((int)(q%MOD))*b[2][n]%MOD;
    printf("%lld\n", ans);
    return 0;
}
