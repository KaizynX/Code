#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5+7;

int n, nd;
long long nn, np;
int a[MAXN];
long long sum[MAXN], dis[MAXN];

struct TreeArray
{
    int tr[MAXN];
    inline void clear() { for (int i = 1; i <= n; ++i) tr[i] = 0; }
    inline void update(int x, int v) { for ( ; x <= n; x += x&-x) tr[x] += v; }
    inline void update(int x, int y, int v) { update(x, v); update(y+1, -v); }
    inline int query(int x) { int res = 0; for ( ; x; x -= x&-x) res += tr[x]; return res; }
    inline int query(int x, int y) { return query(y)-query(x-1); }
} TA;

int main()
{
    cin >> n;
    TA.clear();
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        dis[i] = sum[i] = sum[i-1]+a[i];
    }
    dis[n+1] = 0;
    sort(dis+1, dis+n+2);
    nd = unique(dis+1, dis+n+2)-dis-1;
    TA.update(lower_bound(dis+1, dis+nd+1, 0)-dis, nd, 1);
    for (int i = 1, cur; i <= n; ++i) {
        cur = lower_bound(dis+1, dis+nd+1, sum[i])-dis;
        // tr[i] the number of number <= i
        nn += i-TA.query(cur);
        np += TA.query(cur-1);
        TA.update(cur, nd, 1);
    }
    cout << nn << " " << np << endl;
    return 0;
}
