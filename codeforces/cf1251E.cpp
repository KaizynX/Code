#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n, t;
int vis[N];
long long res;

struct Node
{
    int m, p, id;
} a[N], b[N];

bool cmpp(const Node &x, const Node &y) { return x.p == y.p ? x.m > y.m : x.p < y.p; }
bool cmpm(const Node &x, const Node &y) { return x.m == y.m ? x.p > y.p : x.m < y.m; }

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        res = 0;
        for (int i = 1; i <= n; ++i) vis[i] = 0;

        for (int i = 1, m, p; i <= n; ++i) {
            scanf("%d %d", &m, &p);
            a[i].m = b[i].m = m;
            a[i].p = b[i].p = p;
            a[i].id = b[i].id = i;
        }
        sort(a+1, a+n+1, cmpp);
        sort(b+1, b+n+1, cmpm);

        int cnt = 0, apos = 1, bpos = 1;
        while (cnt < n) {
            while (bpos <= n && cnt >= b[bpos].m) {
                if (!vis[b[bpos].id]) {
                    vis[b[bpos].id] = 1;
                    if (++cnt >= n) break;
                } else {
                    while (apos <= n && vis[a[apos].id]) ++apos;
                    if (apos > n) continue;
                    vis[a[apos].id] = 1;
                    res += a[apos].p-b[bpos].p;
                    if (++cnt >= n) break;
                }
                ++bpos;
            }
            while (apos <= n && vis[a[apos].id]) ++apos;
            if (apos > n) continue;
            vis[a[apos].id] = 1;
            res += a[apos].p;
            ++cnt;
        }
        printf("%I64d\n", res);
    }
    return 0;
}
