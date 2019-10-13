#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+7;
const int MOD = 998244353;

int n, m;
int f[MAXN], g[MAXN], q[MAXN], r[MAXN];

void exgcd(int a, int b, int &x, int &y)
{
    if (!b) {
        x = 1;
        y = 0;
        return;
    }
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
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; ++i) scanf("%d", f+i);
    for (int i = 0; i <= m; ++i) scanf("%d", g+i);
    for (int i = n-m; i >= 0; --i) {
        // q[i] = f[n-(n-m-i)]/g[m];
        q[i] = static_cast<int>(1ll*f[n-(n-m-i)]*mul_inv(g[m], MOD)%MOD);
        for (int j = m; j >= 0; --j) {
            f[i+j] -= static_cast<int>(1ll*q[i]*g[j]%MOD);
            f[i+j] = (f[i-(m-j)]+MOD)%MOD;
        }
    }
    for (int i = 0; i <= n-m; ++i) printf("%d%c", q[i], " \n"[i==n-m]);
    int lim = m;
    while (lim && f[lim] == 0) --lim;
    for (int i = 0; i <= lim; ++i) printf("%d%c", f[i], " \n"[i==n-m]);
    return 0;
}
