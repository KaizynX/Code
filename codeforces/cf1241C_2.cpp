#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 2e5+7;

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

        if (x < y) swap(x, y), swap(a, b);
        int l = 1, r = n;
        long long lcm = 1ll*a*b/gcd(a, b);
        // check
        int pos = 0;
        int nab = static_cast<int>(n/lcm), na = n/a-nab, nb = n/b-nab;
        long long now = 0;
        for (int i = 1; i <= nab; ++i) now += p[++pos]*(x+y);
        for (int i = 1; i <= na; ++i) now += p[++pos]*x;
        for (int i = 1; i <= nb; ++i) now += p[++pos]*y;
        if (now < k) {
            printf("-1\n");
            continue;
        }

        while (l < r) {
            int mid = (l+r)>>1;
            nab = static_cast<int>(mid/lcm), na = mid/a-nab, nb = mid/b-nab;
            pos = 0;
            now = 0;
            for (int i = 1; i <= nab; ++i) now += p[++pos]*(x+y);
            for (int i = 1; i <= na; ++i) now += p[++pos]*x;
            for (int i = 1; i <= nb; ++i) now += p[++pos]*y;
            if (now >= k) r = mid;
            else l = mid+1;
        }
        printf("%d\n", l);
    }
    return 0;
}
