#include <bits/stdc++.h>

using namespace std;

const int kN = 3e5+7;

int n, num_d;
int l[kN], r[kN], trln[kN*3], trun[kN*3];
long long ans;
long long trlm[kN*3], trum[kN*3];
unordered_map<int, int> dis;

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

inline void Discrete(int x)
{
    if (!dis[x]) dis[x] = ++num_d;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", l+i, r+i);
        l[i] *= 2; r[i] *= 2;
        int m = l[i]/2+r[i]/2;
        Discrete(l[i]);
        Discrete(r[i]);
        Discrete(m);

        add(dis[l[i]], l[i], trlm);
        add(dis[m]+1, -l[i], trlm);
        add(dis[l[i]], 1, trln);
        add(dis[m]+1, -1, trln);
        add(dis[m]+1, r[i], trum);
        add(dis[r[i]]+1, -r[i], trum);
        add(dis[m]+1, 1, trun);
        add(dis[r[i]]+1, -1, trun);
    }
    for (int i = 1; i <= n; ++i) {
        int h = l[i]/2+r[i]/2;
        int ln = query(dis[h], trln), un = query(dis[h], trun);
        long long lm = query(dis[h], trlm), um = query(dis[h], trum);
        long long now = 1ll*ln*h-lm + um-1ll*un*h;
        ans = max(ans, now);
    }
    printf("%lld\n", ans);
    return 0;
}
