#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+7;
const int MOD = 998244353;

int n, m;
int f[MAXN], g[MAXN], q[MAXN], r[MAXN];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; ++i) scanf("%d", f+i);
    for (int i = 0; i <= m; ++i) scanf("%d", g+i);
    for (int i = n-m; i >= 0; --i) {
        q[i] = f[n-(n-m-i)]/g[m];
        for (int j = m; j >= 0; --j)
            // f[n-(n-m-i)-(m-j)] -= q[i]*g[j];
            f[i+j] -= q[i]*g[j];
    }
    for (int i = 0; i <= n-m; ++i) printf("%d%c", q[i], " \n"[i==n-m]);
    int lim = m;
    while (lim && f[lim] == 0) --lim;
    for (int i = 0; i <= lim; ++i) printf("%d%c", f[i], " \n"[i==n-m]);
    return 0;
}
