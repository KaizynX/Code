#include <bits/stdc++.h>

using namespace std;

const int kN = 3e5+7;

int n, num_d;
int dis[kN*3], trln[kN*3], trun[kN*3];
long long ans;
long long trlm[kN*3], trum[kN*3];

struct Rec
{
    int l, r, m, i;
} a[kN];

inline cmpl(const Rec &x, const Rec &y) { return x.l < y.l; }
inline cmpr(const Rec &x, const Rec &y) { return x.r < y.r; }
inline cmpm(const Rec &x, const Rec &y) { return x.m < y.m; }
inline cmpi(const Rec &x, const Rec &y) { return x.i < y.i; }

template <typename T> inline void add(int i, int k, T tr[])
{
    for( ; i <= num_d; i += i & -i) tr[i] += k;
}

template <typename T> inline T query(int x, T tr[])
{
    T res = 0;
    for( ; x; x -= x & -x) res += tr[x];
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &a[i].l, &a[i].r);
        a[i].i = i;
        a[i].m = a[i].l+a[i].r;
        a[i].l <<= 1; a[i].r <<= 1;
        dis[++num_d] = a[i].l;
        dis[++num_d] = a[i].r;
        dis[++num_d] = a[i].m;
    }
    sort(dis+1, dis+num_d+1);
    num_d = unique(dis+1, dis+num_d+1)-dis-1;

    sort(a+1, a+n+1, cmpl);
    int id = 1;
    for (int i = 1; i <= n; ++i) {
        while (id <= num_d && dis[id] < a[i].l) ++id;
        a[i].l = id;
    }
    sort(a+1, a+n+1, cmpr);
    id = 1;
    for (int i = 1; i <= n; ++i) {
        while (id <= num_d && dis[id] < a[i].r) ++id;
        a[i].r = id;
    }
    sort(a+1, a+n+1, cmpm);
    id = 1;
    for (int i = 1; i <= n; ++i) {
        while (id <= num_d && dis[id] < a[i].m) ++id;
        a[i].m = id;
    }
    sort(a+1, a+n+1, cmpi);
    for (int i = 1; i <= n; ++i) {
        add(a[i].l, dis[a[i].l], trlm);
        add(a[i].m+1, -dis[a[i].l], trlm);
        add(a[i].l, 1, trln);
        add(a[i].m+1, -1, trln);
        add(a[i].m+1, dis[a[i].r], trum);
        add(a[i].r+1, -dis[a[i].r], trum);
        add(a[i].m+1, 1, trun);
        add(a[i].r+1, -1, trun);
        printf("%d %d %d\n", i, a[i].l, a[i].r);/////////
    }

    for (int i = 1; i <= n; ++i) {
        int h = a[i].m;
        int ln = query(h, trln), un = query(h, trun);
        long long lm = query(h, trlm), um = query(h, trum);
        long long now = 1ll*ln*dis[h]-lm + um-1ll*un*dis[h];
        ans = max(ans, now);
    }
    printf("%lld\n", ans);
    return 0;
}
