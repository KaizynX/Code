#include <bits/stdc++.h>

using namespace std;

const int kN = 3e5+7;

int n;
int dis[kN*3], num_d;
long long ans;
int trln[kN*3], trun[kN*3];
long long trlm[kN*3], trum[kN*3];

struct Rec
{
    int l, r, m;
} a[kN];

// 单点修改 add(x, k);
// 区间修改 add(x, k); add(y+1, -k);
template <typename T> inline void add(int i, int k, T tr[])
{
    for( ; i <= num_d; i += i & -i) tr[i] += k;
}
// 单点查询
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
        a[i].l *= 2; a[i].r *= 2;
        a[i].m = (a[i].l+a[i].r)/2;
        dis[++num_d] = a[i].l;
        dis[++num_d] = a[i].r;
        dis[++num_d] = a[i].m;
    }
    sort(dis+1, dis+num_d+1);
    num_d = unique(dis+1, dis+num_d+1)-dis-1;
    for (int i = 1; i <= n; ++i) {
        a[i].l = lower_bound(dis+1, dis+num_d+1, a[i].l)-dis;
        a[i].r = lower_bound(dis+1, dis+num_d+1, a[i].r)-dis;
        a[i].m = lower_bound(dis+1, dis+num_d+1, a[i].m)-dis;
        add(a[i].l, dis[a[i].l], trlm);
        add(a[i].m+1, -dis[a[i].l], trlm);
        add(a[i].l, 1, trln);
        add(a[i].m+1, -1, trln);
        add(a[i].m, dis[a[i].r], trum);
        add(a[i].r+1, -dis[a[i].r], trum);
        add(a[i].m, 1, trun);
        add(a[i].r+1, -1, trun);
        // at_mid[a[i].m] += (dis[a[i].r]-dis[a[i].l])/2;
    }
    for (int i = 1; i <= n; ++i) {
        int h = a[i].m;
        int ln = query(h, trln), un = query(h, trun);
        long long lm = query(h, trlm), um = query(h, trum);
        long long now = 1ll*ln*dis[h]-lm + um-1ll*un*dis[h]
                        - (dis[a[i].r]-dis[a[i].l])/2;
        ans = max(ans, now);
    }
    printf("%lld\n", ans);
    return 0;
}
