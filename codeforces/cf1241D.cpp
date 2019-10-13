#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 3e5+7;

int q, n;
int a[N], vis[N], big[N], sma[N];

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

inline void clear()
{
    for (int i = 1; i <= n; ++i) vis[i] = 0;
    BIT.clear();
}

int main()
{
    scanf("%d", &q);
    while (q--) {
        int res = n;
        scanf("%d", &n);
        clear();
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a+i);
            big[i] = BIT.query(a[i]+1, n);
            if (!vis[a[i]]) {
                vis[a[i]] = 1;
                BIT.update(a[i], 1);
            }
        }
        clear();
        for (int i = n; i; --i) {
            sma[i] = BIT.query(a[i]-1);
            if (!vis[a[i]]) {
                vis[a[i]] = 1;
                BIT.update(a[i], 1);
            }
#ifdef DEBUG
            printf("samll:%d big:%d\n", sma[i], big[i]);
#endif
            res = min(res, big[i]+sma[i]);
        }
        printf("%d\n", res);
    }
    return 0;
}
