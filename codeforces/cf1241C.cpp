#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 1e5+7;

int q, n, x, y, a, b;
long long k;
int p[N];

inline int gcd(int aa, int bb)
{
    return bb ? gcd(bb, aa%bb) : aa;
}

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", p+i);
            p[i] /= 100;
        }
        scanf("%d%d%d%d%lld", &x, &a, &y, &b, &k);
        sort(p+1, p+n+1);
        reverse(p+1, p+n+1);

        int pos = 1, cnt = 0;
        long long lcm = 1ll*a/gcd(a, b)*b, now = 0;
        for (long long i = lcm; i <= n; i += lcm) {
            now += p[pos]*(x+y);
            ++cnt;
            ++pos;
            if (now >= k) break;
        }
#ifdef DEBUG
        printf("1:%lld %d\n", now, cnt);
#endif
        if (now >= k) {
            printf("%d\n", cnt);
            continue;
        }
        if (x < y) swap(x, y), swap(a, b);
        for (int i = a; i <= n; i += a) {
            if (i%lcm == 0) continue;
            now += p[pos]*x;
            ++cnt;
            ++pos;
            if (now >= k) break;
        }
#ifdef DEBUG
        printf("2:%lld %d\n", now, cnt);
#endif
        if (now >= k) {
            printf("%d\n", cnt);
            continue;
        }
        for (int i = b; i <= n; i += b) {
            if (i%lcm == 0) continue;
            now += p[pos]*y;
            ++cnt;
            ++pos;
            if (now >= k) break;
        }
#ifdef DEBUG
        printf("3:%lld %d\n", now, cnt);
#endif
        if (now >= k) {
            printf("%d\n", cnt);
            continue;
        }
        printf("-1\n");
    }
    return 0;
}
