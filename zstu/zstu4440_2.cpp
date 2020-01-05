#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 1e9+7;

int T, n, m, x, y, z;
int a[N], q[N], f[N];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d %d %d %d", a+1, a+2, &x, &y, &z, &n, &m);
        for (int i = 3; i <= n; ++i)
            a[i] = static_cast<int>((1ll*x*a[i-1]+1ll*y*a[i-2]+z)%MOD);
        q[1] = a[1]%n+1; q[2] = a[2]%n+1;
        for (int i = 3; i <= m; ++i)
            q[i] = static_cast<int>((1ll*y*q[i-1]+1ll*x*q[i-2]+z)%n+1);
        int p = 0;
        memset(f, 0, sizeof(int)*(n+3));
        for (int i = m, mv = 0, last = 0; i; --i) {
            if (q[i]&1) { // op 2
                if (mv >= q[i] || last >= q[i]) continue;
                for (int j = q[i]; j > mv; --j) f[j] = ++p;
                last = q[i];
            } else { // op 1
                mv = max(mv, q[i]);
            }
        }
        long long res = 0;
        for (int i = 1; i <= n; ++i) {
            if (!f[i]) f[i] = ++p;
            (res += 1ll*i*a[f[i]]) %= MOD;
        }
#ifdef DEBUG
        for (int i = 1; i <= m; ++i)
            printf("%d%c", q[i], " \n"[i==m]);
        for (int i = 1; i <= n; ++i)
            printf("%d%c", f[i], " \n"[i==n]);
        for (int i = 1; i <= n; ++i)
            printf("%d%c", a[f[i]], " \n"[i==n]);
#endif
        printf("%d\n", static_cast<int>(res));
    }
    return 0;
}
