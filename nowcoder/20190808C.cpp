#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int n;
int f[Maxn];
long long presump[Maxn], trp[Maxn];
long long presumc[Maxn], trc[Maxn];

struct Tree
{
    int h, c, p, rk, id;
    bool operator < (const Tree &nex) const { return h < nex.h; }
}a[Maxn];

bool cmp (const Tree &x, const Tree &y)
{
    return x.c < y.c;
}

// 单点修改 add(x, k);
// 区间修改 add(x, k); add(y+1, -k);
inline void add(int i, long long k, long long *tr)
{
    for( ; i <= n; i += i & -i) tr[i] += k;
}
// 单点查询
inline long long query(int x, long long *tr)
{
    long long res = 0;
    for( ; x; x -= x & -x) res += tr[x];
    return res;
}

int main()
{
    while(scanf("%d", &n)!=EOF)
    {
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d%d%d", &a[i].h, &a[i].c, &a[i].p);
            a[i].id = i;
            trc[i] = trp[i] = 0;
        }
        // 按cost排序
        sort(a+1, a+n+1, cmp);
        for(int i = 1; i <= n; ++i)
            a[i].rk = i;
        // 按height排序
        sort(a+1, a+n+1);
        for(int i = 1; i <= n; ++i)
            f[a[i].rk] = i;
        // 前缀和
        for(int i = 1; i <= n; ++i)
        {
            presumc[i] = presumc[i-1]+1ll*a[i].c*a[i].p;
            presump[i] = presump[i-1]+a[i].p;
        }
        long long res = -1;
        for(int i = 1, st; i <= n; ++i)
        {
            long long num = a[i].p;
            st = i;
            // 高度相同
            while(i+1 <= n && a[i+1].h == a[i].h)
            {
                i++;
                num += a[i].p;
            }
            long long cost = presumc[n]-presumc[i];
            long long delnum = presump[st-1]-(num-1);
            if(delnum <= 0) res = (res == -1 ? cost : min(res, cost));
            else
            {
                int l = 1, r = n;
                while(l < r)
                {
                    int mid = (l+r+1)/2;
                    if(query(mid, trp) >= delnum) r = mid-1;
                    else l = mid;
                }
                // l < delnum
                cost += query(l, trc);
                delnum -= query(l, trp);
                ++l;
                cost += a[f[l]].c*delnum;
                res = (res == -1 ? cost : min(res, cost));
            }

            for(int j = st; j <= i; ++j)
            {
                add(a[j].rk, a[j].p, trp);
                add(n+1, -a[j].p, trp);
                add(a[j].rk, 1ll*a[j].p*a[j].c, trc);
                add(n+1, -1ll*a[j].p*a[j].c, trc);
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}
