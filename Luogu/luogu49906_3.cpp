#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e3+7;
const long long INF = 1e15;

int n;
int b[Maxn][Maxn], vis[Maxn];
long long ans = INF, all;

struct Node
{
    int v, id;
    long long s;
} a[Maxn];

inline bool cmp1(const Node x, const Node y) { return x.s*x.v < y.s*y.v; }
inline bool cmp2(const Node x, const Node y) { return x.s < y.s; }
inline bool cmp3(const Node x, const Node y) { return x.v < y.v; }
inline bool cmp4(const Node x, const Node y) { return x.s*(all-x.v) > y.s*(all-y.v); }

inline long long calc()
{
    long long res = 0;
    memset(vis, 0, sizeof vis);
    for(int i = 1; i <= n; ++i)
    {
        vis[a[i].id] = 1;
        long long sum = 0;
        for(int j = 1; j <= n; ++j)
            if(!vis[j]) sum += b[a[i].id][j];
        res += sum*a[i].v;
    }
    return res;
}

void brute(int cur, long long val)
{
    if(cur > n)
    {
        ans = min(ans, val);
        return;
    }
    for(int i = 1; i <= n; ++i)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            long long sum = 0;
            for(int j = 1; j <= n; ++j)
                if(!vis[j]) sum += b[i][j];
            brute(cur+1, val+sum*a[i].v);
            vis[i] = 0;
        }
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i].v);
        a[i].id = i;
        all += a[i].v;
    }
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            scanf("%d", &b[i][j]);
            a[i].s += b[i][j];
        }
    }
    if(n < 10) brute(1, 0);
    else
    {
        sort(a+1, a+n+1, cmp1);
        ans = min(ans, calc());
        sort(a+1, a+n+1, cmp2);
        ans = min(ans, calc());
        sort(a+1, a+n+1, cmp3);
        ans = min(ans, calc());
        sort(a+1, a+n+1, cmp4);
        ans = min(ans, calc());
    }
    printf("%lld\n", ans);
    return 0;
}
