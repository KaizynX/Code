#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int MAXN = 1e5+7;

int T, n, k;
int t[MAXN], vis[MAXN];

inline bool cmp(const int x, const int y)
{
    if (x%k == 0) return true;
    if (y%k == 0) return false;
    return x%k > y%k;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", t+i);
        }
        sort(t+1, t+n+1, cmp);
#ifdef DEBUG
        for (int i = 1; i <= n; ++i) {
            printf("%d ", t[i]);
        }
        putchar('\n');
#endif
        long long res = k, finish = 1ll*n*k;
        for (int i = 1 ;i <= n; ++i) {
            if (res+t[i] >= finish) {
                res += t[i];
            } else {
                res += (t[i]%k ? t[i]/k*k+k : t[i]);
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}
