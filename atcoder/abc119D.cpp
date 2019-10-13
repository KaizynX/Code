#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 1e5+7;
const long long INF = 1e18;

int a, b, q;
long long s[N], t[N];

inline long long calc(long long ss, long long tt, long long xx)
{
    if (ss <= xx && tt <= xx) {
        return xx-min(ss, tt);
    } else if (ss >= xx && tt >= xx) {
        return max(ss, tt)-xx;
    } else {
        return min(abs(ss-xx), abs(tt-xx))+abs(ss-tt);
    }
}

int main()
{
    scanf("%d %d %d", &a, &b, &q);
    for (int i = 1; i <= a; ++i)
        scanf("%lld", s+i);
    for (int i = 1; i <= b; ++i)
        scanf("%lld", t+i);
    long long x, res;
    for (int i = 1; i <= q; ++i) {
        scanf("%lld", &x);
        int ps = lower_bound(s+1, s+a+1, x)-s,
            pt = lower_bound(t+1, t+b+1, x)-t;
#ifdef DEBUG
        printf("ps:%d pt:%d\n", ps, pt);
#endif
        res = INF;
        for (int i = -1; i <= 0; ++i) {
            if (ps+i > a || ps+i < 1) continue;
            for (int j = -1; j <= 0; ++j) {
                if (pt+j > b || pt+j < 1) continue;
                res = min(res, calc(s[ps+i], t[pt+j], x));
            }
        }
        cout << res << endl;
    }
    return 0;
}
