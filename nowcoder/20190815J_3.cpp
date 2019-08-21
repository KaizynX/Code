#include <bits/stdc++.h>

using namespace std;

const int kN = 3e5+7;

int n, num_d;
int dis[kN*3], l[kN], r[kN], trln[kN*3], trun[kN*3];
long long ans;
long long trlm[kN*3], trum[kN*3];

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
        scanf("%d%d", l+i, r+i);
        l[i] *= 2; r[i] *= 2;
        int m = l[i]/2+r[i]/2;
        dis[++num_d] = l[i];
        dis[++num_d] = r[i];
        dis[++num_d] = m;
    }
    sort(dis+1, dis+num_d+1);
    num_d = unique(dis+1, dis+num_d+1)-dis-1;
    for (int i = 1; i <= n; ++i) {
        int m = l[i]/2+r[i]/2;
        l[i] = lower_bound(dis+1, dis+num_d+1, l[i])-dis;
        r[i] = lower_bound(dis+1, dis+num_d+1, r[i])-dis;
        m = lower_bound(dis+1, dis+num_d+1, m)-dis;
        add(l[i], dis[l[i]], trlm);
        add(m+1, -dis[l[i]], trlm);
        add(l[i], 1, trln);
        add(m+1, -1, trln);
        add(m+1, dis[r[i]], trum);
        add(r[i]+1, -dis[r[i]], trum);
        add(m+1, 1, trun);
        add(r[i]+1, -1, trun);
        printf("%d %d %d\n", i, l[i], r[i]);//////////
    }
    for (int i = 1; i <= n; ++i) {
        int m = dis[l[i]]/2+dis[r[i]]/2;
        int h = lower_bound(dis+1, dis+num_d+1, m)-dis;
        int ln = query(h, trln), un = query(h, trun);
        long long lm = query(h, trlm), um = query(h, trum);
        long long now = 1ll*ln*dis[h]-lm + um-1ll*un*dis[h];
        ans = max(ans, now);
    }
    printf("%lld\n", ans);
    return 0;
}
