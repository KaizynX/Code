#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n, t;
int b[N];
long long res;

struct BinaryIndexedTree
{
    // set your type
    typedef int T;
    T tr[N];
    BinaryIndexedTree() { memset(tr, 0, sizeof tr); }
    inline void clear() { for (int i = 1; i <= n; ++i) tr[i] = 0; }
    inline void update(int x, T v) { for ( ; x <= n; x += x&-x) tr[x] += v; }
    inline void update(int x, int y, T v) { update(x, v); update(y+1, -v); }
    inline T query(int x) { T res = 0; for ( ; x; x -= x&-x) res += tr[x]; return res; }
    inline T query(int x, int y) { return query(y)-query(x-1); }
} BIT;

struct Node
{
    int m, p;
} a[N];

bool cmpp(const Node &x, const Node &y) { return x.p == y.p ? x.m > y.m : x.p < y.p; }
bool cmpm(const Node &x, const Node &y) { return x.m == y.m ? x.p > y.p : x.m < y.m; }

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        BIT.clear();
        res = 0;
        for (int i = 1; i <= n; ++i) b[i] = 0;

        for (int i = 1; i <= n; ++i) {
            scanf("%d %d", &a[i].m, &a[i].p);
        }
        sort(a+1, a+n+1, cmpm);
        int cnt = 0, st = 0, cur = 0, pos = 1;
        while (cur < n) {
            while (pos <= n && a[pos].m <= cur) {
                b[a[pos].m] = cur;
                if (!st) st = pos;
                ++cur;
                ++pos;
            }
            if (cur >= n) break;
            ++cur;
            ++cnt;
            st = 0;
        }
        b[a[n].m+1] = n; // INF
        for (int i = a[n].m; i >= a[st].m; --i) {
            if (b[i] < i) b[i] = b[i+1];
            else b[i] = min(b[i+1], b[i]-i);
        }
        sort(a+st, a+n+1, cmpp);
        for (int i = st, add = 0; i <= n && add < cnt; ++i) {
            // res += a[st+i].p;
            if (BIT.query(a[i].m)+b[a[i].m]) {
                res += a[i].p;
                ++add;
                BIT.update(a[i].m, n, -1);
            }
        }
        printf("%I64d\n", res);
    }
    return 0;
}
